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

Program::Helpers::FindByGUID::FindByGUID(System::String^ guid)
{
	this->guid = guid;
}

bool Program::Helpers::FindByGUID::isInStore(Compartment^ element)
{
	return this->guid == element->getUUID()->ToString();
}

bool Program::Helpers::FindByGUID::isInItem(Item^ element)
{
	return this->guid == element->getUUID()->ToString();
}