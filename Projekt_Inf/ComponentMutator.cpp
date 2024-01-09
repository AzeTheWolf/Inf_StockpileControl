#include "ComponentMutator.h"
#include "Item.h"
#include "Finders.h"

using namespace System::Windows::Forms;
using namespace Program::Helpers;

void Program::ComponentMutator::removeFromListView(ListView^ component, Item^ item)
{
	auto list = component->Items;

		// get all items of given name from list
		array<ListViewItem^>^ lvi = list->Find(item->getName(), false);
		if (lvi->Length < 1) return;

		// find in lvi items with same tag
		ListViewItem^ found =
			lvi->Find(
				lvi, 
				gcnew System::Predicate<ListViewItem^>(
					gcnew FindListViewItem(item), &FindListViewItem::isIn
				)
			);

		// if not found (default LVI^ has no tag)
		if (found->Tag == item)
		{
			component->Items->Remove(found);
		}
}
