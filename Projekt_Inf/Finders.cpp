#include "Finders.h"

#include "IPlaceable.h"
#include "Storage.h"

using namespace Program;

Helpers::FindListViewItem::FindListViewItem(Object^ tag)
{
	this->Tag = tag;
}

bool Helpers::FindListViewItem::isIn(System::Windows::Forms::ListViewItem^ lvi)
{
	return lvi->Tag == this->Tag;
}

Program::Helpers::FindPlaceableByGUID::FindPlaceableByGUID(System::Guid^ guid)
{
	this->guid = guid;
}

bool Program::Helpers::FindPlaceableByGUID::isIn(IPlaceable^ placeable)
{
	return this->guid == placeable->getUUID();
}

Program::Helpers::FindStoreByGUID::FindStoreByGUID(System::Guid^ guid)
{
	this->guid = guid;
}

bool Program::Helpers::FindStoreByGUID::isIn(CStore^ store)
{
	return this->guid == store->getUUID();
}
