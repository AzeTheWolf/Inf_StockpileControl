#include "DataReadWrite.h"
#include "Item.h"
#include "ProgramState.h"
#include "IPlaceable.h"
#include "Item.h"
#include "Compartment.h"
#include "Storage.h"

#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/prepared_statement.h>

#include <msclr/marshal_cppstd.h>

using namespace Program;
using namespace Program::DataReadWrite;
using namespace System::Xml::Serialization;
using namespace System::Collections::Generic;
using namespace System::IO;


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
			parent->place(item);
		}
		else if (element->type == ElementType::COMPARTMENT)
		{
			Compartment^ store = gcnew Compartment(
				element->displayName,
				element->description
			);

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
		ProgramState::handleError(
			System::String::Format(L"Nie mo¿na otworzyæ pliku: {0}", ex->FileName)
		);
		return;
	}
}

Program::DataReadWrite::DatabaseConnection::DatabaseConnection()
{
	try
	{
	this->driver = sql::mysql::get_mysql_driver_instance();
	this->conn = this->driver->connect("tcp://localhost:3306/stockpilemanager", "usr", "passwd");
	}
	catch (sql::SQLException& e)
	{
		ProgramState::handleError(msclr::interop::marshal_as<System::String^>(e.what()));
	}

}

Program::DataReadWrite::DatabaseConnection::~DatabaseConnection()
{
	delete this->conn;
	delete this->driver;
}

void DatabaseConnection::putDatabaseItemRecord(System::String^ name, System::String^ description, System::UInt16 quantity)
{
	sql::PreparedStatement* statement;
	statement = this->conn->prepareStatement("INSERT INTO items VALUES(NULL, ?, ?, ?)");
	statement->setString(1, msclr::interop::marshal_as<std::string>(name));
	statement->setString(2, msclr::interop::marshal_as<std::string>(description));
	statement->setInt(3, quantity);

	statement->execute();
	delete statement;
}
