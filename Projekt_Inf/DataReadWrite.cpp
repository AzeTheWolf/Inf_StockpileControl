#include "DataReadWrite.h"
#include "Item.h"
#include "ProgramState.h"
#include "IPlaceable.h"
#include "Item.h"
#include "Compartment.h"

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

void Program::DataReadWrite::FileIO::write()
{
	XmlSerializer^ serializer = 
		gcnew XmlSerializer(List<PlaceableData^>::typeid);

	List<PlaceableData^>^ list
		= FileIO::_convert(ProgramState::masterStorage->getContents());

	StreamWriter^ writer = gcnew StreamWriter(L"data.xml");
	serializer->Serialize(writer, list);
	writer->Close();
}
