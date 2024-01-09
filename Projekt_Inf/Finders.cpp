#include "Finders.h"

using namespace Program;

Helpers::FindListViewItem::FindListViewItem(Object^ tag)
{
	this->Tag = tag;
}

bool Helpers::FindListViewItem::isIn(System::Windows::Forms::ListViewItem^ lvi)
{
	return lvi->Tag == this->Tag;
}
