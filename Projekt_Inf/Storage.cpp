#include "Storage.h"
#include "IPlaceable.h"
#include "Item.h"

using namespace ProjektInf;

ProjektInf::CStore::CStore()
{
	this->contents = gcnew System::Collections::Generic::List<IPlaceable^>();
}

void CStore::place(IPlaceable^ object)
{
	//if (this->contents->BinarySearch(object) < 0)
	{
		this->contents->Add(object);
		object->setParent(this);
	}
}

void CStore::remove(IPlaceable^ object)
{
	this->contents->Remove(object);
	object->setParent(nullptr);
}

void ProjektInf::CStore::sendTo(IPlaceable^ item, CStore^ other)
{
	other->place(item);
	this->contents->Remove(item);
}

System::Collections::Generic::List<Item^>^ ProjektInf::CStore::getItems()
{
	auto list = gcnew System::Collections::Generic::List<Item^>;
	for each (Item ^ item in this->contents)
	{
		list->AddRange(item->getItems());
	}

	return list;
}