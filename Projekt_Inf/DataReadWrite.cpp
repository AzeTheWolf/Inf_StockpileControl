#include "DataReadWrite.h"
#include "Item.h"
#include "ProgramState.h"
#include "IPlaceable.h"
#include "Item.h"
#include "Compartment.h"
#include "Storage.h"
#include "Finders.h"
#include "BoxHandler.h"

#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/prepared_statement.h>

#include <msclr/marshal_cppstd.h>

#include <string>
#include <codecvt>

using namespace Program;
using namespace Program::DataReadWrite;
using namespace System::Xml::Serialization;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace msclr::interop;


System::Collections::Generic::List<PlaceableData^>^ FileIO::_convert(System::Collections::Generic::List<IPlaceable^>^ input)
{
	List<PlaceableData^>^ output = gcnew List<PlaceableData^>;

	for each (IPlaceable ^ element in input)
	{
		PlaceableData^ data = gcnew PlaceableData;
		data->displayName = element->getName();
		data->description = element->getDescription();

		if (element->GetType()->Name == L"Item")
		{
			Item^ item = dynamic_cast<Item^>(element);
			if (item == nullptr) continue;

			data->decaysOn = item->getDecayDate();
			data->quantity = item->getQuantity();
			data->stockpileAlert = item->getAlertLevel();
			data->contents = nullptr;
			data->type = ElementType::ITEM;
		} else if (element->GetType()->Name == L"Compartment")
		{
			Compartment^ store = dynamic_cast<Compartment^>(element);
			if (store == nullptr) continue;

			data->quantity = 0;
			data->stockpileAlert = 0;
			data->contents = FileIO::_convert(store->getContents());
			data->type = ElementType::COMPARTMENT;
		}

		output->Add(data);
	}

	return output;
}

void FileIO::_deconvertAndPlace(List<PlaceableData^>^ input, CStore^ parent)
{
	for each (PlaceableData ^ element in input)
	{
		if (element->type == ElementType::ITEM)
		{
			Item^ item = gcnew Item(
				element->displayName,
				element->description,
				element->quantity
			);

			item->setAlertLevel(element->stockpileAlert);
			item->setDecayDate(element->decaysOn);
			item->__forceGUID(element->id);
			parent->place(item);
		}
		else if (element->type == ElementType::COMPARTMENT)
		{
			Compartment^ store = gcnew Compartment(
				element->displayName,
				element->description
			);

			store->__forceGUID(element->id);
			parent->place(store);
			FileIO::_deconvertAndPlace(element->contents, store);
		}
	}
}

void Program::DataReadWrite::FileIO::write()
{
	XmlSerializer^ serializer = 
		gcnew XmlSerializer(List<PlaceableData^>::typeid);

	List<PlaceableData^>^ list
		= FileIO::_convert(ProgramState::masterStorage->getContents());

	StreamWriter^ writer = gcnew StreamWriter(FileIO::path);
	serializer->Serialize(writer, list);
	writer->Close();
}

void Program::DataReadWrite::FileIO::read(System::String^ path)
{
	XmlSerializer^ serializer
		= gcnew XmlSerializer(List<PlaceableData^>::typeid);

	try 
	{
		StreamReader^ reader = gcnew StreamReader(path);
		List<PlaceableData^>^ data = 
			dynamic_cast<List<PlaceableData^>^>(serializer->Deserialize(reader));
		reader->Close();

		while (ProgramState::masterStorage->getContents()->Count > 0)
		{
			ProgramState::masterStorage->remove(ProgramState::masterStorage->getContents()[0]);
		}
		FileIO::_deconvertAndPlace(data, ProgramState::masterStorage);
		FileIO::path = path;
	}
	catch (FileNotFoundException^ ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(L"Nie mo¿na otworzyæ pliku: {0}", ex->FileName)
		);
		return;
	}
}

DatabaseConnection::DatabaseConnection()
{
	try
	{
		this->driver = sql::mysql::get_mysql_driver_instance();
	}
	catch (sql::SQLException& e)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
				e.getErrorCode()
			)
		);
	}
}

Program::DataReadWrite::DatabaseConnection::~DatabaseConnection()
{
	this->closeConnection();
	delete this->driver;
}

void DatabaseConnection::openConnection()
{
	if (!ProgramState::isRemote) return;
	if (!isClosed) return;

	this->conn = this->driver->connect("tcp://localhost:3306/stockpilemanager", "usr", "passwd");

	this->conn->setClientOption("OPT_CHARSET_NAME", "utf8");
	this->conn->setClientOption("OPT_SET_CHARSET_NAME", "utf8");
}

void DatabaseConnection::closeConnection()
{
	if (!isClosed)
	{
		this->conn->close();
		delete this->conn;
	}
}

void DatabaseConnection::putDatabaseItemRecord(Item^ item)
{
	if (!ProgramState::isRemote) return;
	sql::PreparedStatement* statement;

	try
	{
		System::String^ parentID = item->parent()->getUUID() == nullptr
			? "root"
			: item->parent()->getUUID()->ToString();

		statement =
			this->conn->prepareStatement("INSERT INTO items VALUES(?, ?, ?, ?, ?, ?, ?)");

		statement->setString(1, msclr::interop::marshal_as<std::string>(item->getUUID()->ToString()));
		statement->setInt(2, item->getQuantity());
		statement->setInt(3, item->getAlertLevel());
		statement->setString(4,
			msclr::interop::marshal_as<std::string>(item->getDecayDate().ToString()));
		statement->setString(5, 
			wstring_utf8(msclr::interop::marshal_as<std::wstring>(item->getName())));
		statement->setString(6, msclr::interop::marshal_as<std::string>(item->getDescription()));
		statement->setString(7, msclr::interop::marshal_as<std::string>(parentID));

		statement->execute();
		delete statement;

	}
	catch (sql::SQLException ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
				ex.getErrorCode()
			)
		);
	}
	catch (System::NullReferenceException^ ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"Przedmiot {0} nie posiada elementu nadrzêdnego! {1}",
				item->getName(), ex->Message
			)
		);
	}
}

void DatabaseConnection::delDatabaseItemRecord(Item^ item)
{
	if (!ProgramState::isRemote) return;
	sql::PreparedStatement* statement;

	try
	{
		statement =
			this->conn->prepareStatement("DELETE FROM items WHERE uuid = ?");

		statement->setString(1, msclr::interop::marshal_as<std::string>(item->getUUID()->ToString()));

		statement->execute();
	}
	catch (sql::SQLException ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
				ex.getErrorCode()
			)
		);
	}
	finally
	{
		delete statement;
	}
}

void DatabaseConnection::putDatabaseStoreRecord(Compartment^ store)
{
	if (!ProgramState::isRemote) return;
	sql::PreparedStatement* statement;

	try
	{
		System::String^ parentID = store->parent()->getUUID() == nullptr
			? "root"
			: store->parent()->getUUID()->ToString();

		statement =
			this->conn->prepareStatement("INSERT INTO compartments VALUES(?, ?, ?, ?)");

		statement->setString(
			1, msclr::interop::marshal_as<std::string>(store->getUUID()->ToString())
		);
		statement->setString(
			2, msclr::interop::marshal_as<std::string>(store->getName())
		);
		statement->setString(
			3, msclr::interop::marshal_as<std::string>(store->getDescription())
		);
		statement->setString(
			4, msclr::interop::marshal_as<std::string>(parentID)
		);

		statement->execute();
		delete statement;

	}
	catch (sql::SQLException ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
				ex.getErrorCode()
			)
		);
	}
	catch (System::NullReferenceException^ ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"Pojemnik {0} nie posiada elementu nadrzêdnego! {1}",
				store->getName(),
				ex->StackTrace
			)
		);
	}
}

void DatabaseConnection::delDatabaseStoreRecord(Compartment^ store)
{
	if (!ProgramState::isRemote) return;
	sql::PreparedStatement* statement;

	try
	{
		statement =
			this->conn->prepareStatement("DELETE FROM compartments WHERE uuid = ?");

		statement->setString(
			1, msclr::interop::marshal_as<std::string>(store->getUUID()->ToString())
		);

		statement->execute();
		delete statement;

	}
	catch (sql::SQLException ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
				ex.getErrorCode()
			)
		);
	}
}

void Program::DataReadWrite::DatabaseConnection::emptyDatabaseItemTable()
{
	if (!ProgramState::isRemote) return;
	sql::PreparedStatement* statement;

	try
	{
		statement =
			this->conn->prepareStatement("DELETE FROM items");

		statement->execute();
		delete statement;

	}
	catch (sql::SQLException ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
				ex.getErrorCode()
			)
		);
	}
}

void Program::DataReadWrite::DatabaseConnection::emptyDatabaseStoreTable()
{
	if (!ProgramState::isRemote) return;
	sql::PreparedStatement* statement;

	try
	{
		statement =
			this->conn->prepareStatement("DELETE FROM compartments");

		statement->execute();
		delete statement;

	}
	catch (sql::SQLException ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
				ex.getErrorCode()
			)
		);
	}
}

void DatabaseConnection::updateDatabaseItemEntry(System::String^ col, System::String^ value, System::Guid^ uuid)
{
	if (!ProgramState::isRemote) return;
	sql::PreparedStatement* statement;

	try
	{
		statement =
			this->conn->prepareStatement(
				msclr::interop::marshal_as<std::string>("UPDATE items SET "+col+" = ? WHERE uuid = ?")
			);

		statement->setString(1, msclr::interop::marshal_as<std::string>(value));
		statement->setString(2, msclr::interop::marshal_as<std::string>(uuid->ToString()));

		statement->execute();
		delete statement;

	}
	catch (sql::SQLException ex)
	{
		Helpers::BoxHandler::handleError(
			System::String::Format(
				L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
				ex.getErrorCode()
			)
		);
	}
}

void DatabaseConnection::purge(Compartment^ store, bool doRootElement)
{
	if (!ProgramState::isRemote) return;
	sql::PreparedStatement* statement;

	for each (IPlaceable ^ element in store->getContents())
	{
		if (element->GetType()->Name != "Compartment") continue;

		try
		{
			statement =
				this->conn->prepareStatement("DELETE FROM items WHERE parent = ?");

			statement->setString(1, msclr::interop::marshal_as<std::string>(element->getUUID()->ToString()));

			statement->execute();
			delete statement;
		}
		catch (sql::SQLException ex)
		{
			Helpers::BoxHandler::handleError(
				System::String::Format(
					L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
					ex.getErrorCode()
				)
			);
		}
		this->purge(dynamic_cast<Compartment^>(element), true);
	}

	if (!doRootElement) return;
		try
		{
			statement =
				this->conn->prepareStatement("DELETE FROM compartments WHERE uuid = ?");

			statement->setString(1, msclr::interop::marshal_as<std::string>(store->getUUID()->ToString()));
			statement->execute();
			delete statement;
		}
		catch (sql::SQLException ex)
		{
			Helpers::BoxHandler::handleError(
				System::String::Format(
					L"B³¹d bazy danych: {0}" + System::Environment::NewLine,
					ex.getErrorCode()
				)
			);
		}
}

void Program::DataReadWrite::DatabaseConnection::loadFromDatabase()
{
	if (!ProgramState::isRemote) return;
	sql::Statement* statement = this->conn->createStatement();

	sql::ResultSet* resultStores = statement->executeQuery("SELECT * FROM compartments");

	List<Compartment^>^ storeList = gcnew List<Compartment^>;
	List<Relation^>^ storeRelList = gcnew List<Relation^>;

	while (ProgramState::masterStorage->getContents()->Count > 0)
	{
		ProgramState::masterStorage->remove(ProgramState::masterStorage->getContents()[0]);
	}

	while (resultStores->next())
	{
		Compartment^ store = gcnew Compartment(
			marshal_as<System::String^>(
				string_utf8(resultStores->getString("name").asStdString())
			),
			marshal_as<System::String^>(
				string_utf8(resultStores->getString("description").asStdString())
			)
		);

		System::String^ id
			= msclr::interop::marshal_as<System::String^>(resultStores->getString("uuid").asStdString());
		store->__forceGUID(id);
		System::String^ parent 
			= msclr::interop::marshal_as<System::String^>(resultStores->getString("parent").asStdString());

		storeList->Add(store);

		Relation^ rel = gcnew Relation;
		rel->child = System::Guid::Parse(id);
		rel->parent = parent;

		storeRelList->Add(rel);
	}

	sql::ResultSet* resultItems = statement->executeQuery("SELECT * FROM items");

	List<Item^>^ itemList = gcnew List<Item^>;
	List<Relation^>^ itemRelList = gcnew List<Relation^>;

	while (resultItems->next())
	{
		Item^ item = gcnew Item(
			marshal_as<System::String^>(
				string_utf8(resultItems->getString("name").asStdString())
			),
			marshal_as<System::String^>(
				string_utf8(resultItems->getString("description").asStdString())
			),
			resultItems->getInt("quantity")
		);

		System::String^ id
			= msclr::interop::marshal_as<System::String^>(resultItems->getString("uuid").asStdString());
		item->__forceGUID(id);
		item->setAlertLevel( resultItems->getInt("alertLevel") );
		item->setDecayDate(
			System::DateTime::Parse(
				msclr::interop::marshal_as<System::String^>(resultItems->getString("expires").asStdString())
			)
		);

		System::String^ parent
			= msclr::interop::marshal_as<System::String^>(resultItems->getString("parent").asStdString());

		itemList->Add(item);

		Relation^ rel = gcnew Relation;
		rel->child = System::Guid::Parse(id);
		rel->parent = parent;

		itemRelList->Add(rel);

	}

	List<CStore^>^ storeCastList = dynamic_cast<List<CStore^>^>(storeList);
	for each (Relation ^ rel in itemRelList)
	{
		IPlaceable^ child = Helpers::FindByGUIDString(rel->child->ToString(), itemList);

		if (child == nullptr) continue;

		CStore^ parent = rel->parent == "root"
			? ProgramState::masterStorage
			: Helpers::FindByGUIDString(rel->parent->ToString(), storeList);

		parent->place(child);
	}

	for each (Relation ^ rel in storeRelList)
	{
		Compartment^ child = Helpers::FindByGUIDString(rel->child->ToString(), storeList);

		CStore^ parent = rel->parent == "root"
			? ProgramState::masterStorage
			: Helpers::FindByGUIDString(rel->parent->ToString(), storeList);

		parent->place(child);
	}

	delete resultItems;
	delete resultStores;
	delete statement;
}

std::string Program::DataReadWrite::wstring_utf8(const std::wstring& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.to_bytes(str);
}

std::wstring Program::DataReadWrite::string_utf8(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.from_bytes(str);
}
