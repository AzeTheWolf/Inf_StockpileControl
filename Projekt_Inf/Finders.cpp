#include "Finders.h"

#include "IPlaceable.h"
#include "Storage.h"
#include "Item.h"
#include "Compartment.h"

using namespace Program;

Helpers::FindListViewItem::FindListViewItem(Object^ tag)
{
	this->Tag = tag;
}

bool Helpers::FindListViewItem::isIn(System::Windows::Forms::ListViewItem^ lvi)
{
	return lvi->Tag == this->Tag;
}

Program::Helpers::FindStoreByGUID::FindStoreByGUID(System::String^ guid)
{
	this->guid = guid;
}

bool Program::Helpers::FindStoreByGUID::isIn(CStore^ store)
{
	return this->guid == store->getUUID()->ToString();
}

IPlaceable^ Program::Helpers::FindByGUIDString(System::String^ string, System::Collections::Generic::List<Item^>^ list)
{
	for each (IPlaceable ^ item in list)
	{
		if (item->getUUID()->ToString() == string) return item;
	}
	return nullptr;
}

Compartment^ Program::Helpers::FindByGUIDString(System::String^ string, System::Collections::Generic::List<Compartment^>^ list)
{
	for each (Compartment ^ item in list)
	{
		if (item->getUUID()->ToString() == string) return item;
	}
	return nullptr;
}

CStore^ Program::Helpers::FindByGUIDString(System::String^ string, System::Collections::Generic::List<CStore^>^ list)
{
	for each (CStore ^ item in list)
	{
		if (item->getUUID()->ToString() == string) return item;
	}
	return nullptr;
}