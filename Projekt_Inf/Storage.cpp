#include "Storage.h"
#include "IPlaceable.h"
#include "Item.h"
#include "Compartment.h"

using namespace Program;

Program::CStore::CStore()
{
	this->contents = gcnew System::Collections::Generic::List<IPlaceable^>();
}

void CStore::place(IPlaceable^ object)
{
	this->contents->Add(object);
	object->setParent(this);
}

void CStore::remove(IPlaceable^ object)
{
	this->contents->Remove(object);
	object->setParent(nullptr);
}

System::Collections::Generic::List<Item^>^ Program::CStore::getItems()
{
	auto list = gcnew System::Collections::Generic::List<Item^>;
	for each (IPlaceable ^ item in this->contents)
	{
		list->AddRange(item->getItems());
	}

	return list;
}

System::Collections::Generic::List<IPlaceable^>^ Program::CStore::getContents()
{
	return this->contents;
}

System::Guid^ Program::CStore::getUUID()
{
	return nullptr;
}

System::Collections::Generic::List<IPlaceable^>^ Program::CStore::flattenStorage()
{
	System::Collections::Generic::List<IPlaceable^>^ list
		= gcnew System::Collections::Generic::List<IPlaceable^>;

	for each (IPlaceable ^ element in this->contents)
	{
		list->Add(element);
		if (element->GetType()->Name == L"Compartment")
		{
			Compartment^ compartment = dynamic_cast<Compartment^>(element);

			list->AddRange(compartment->flattenStorage());
		}
	}
	return list;
}
