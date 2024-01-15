#include "ComponentMutator.h"
#include "Item.h"
#include "Compartment.h"
#include "Finders.h"
#include "ProgramState.h"

using namespace System::Windows::Forms;
using namespace Program::Helpers;
using namespace Program;

void Program::ComponentMutator::removeFromListView(ListView^ component, Item^ item)
{
	auto list = component->Items;

	// get all items of given name from list
	array<ListViewItem^>^ lvi = list->Find(item->getName(), false);
	if (lvi->Length < 1) return;

	// find in lvi items with same tag
	ListViewItem^ found = lvi->Find(
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

System::Windows::Forms::TreeNode^ Program::ComponentMutator::createTreeNode(IPlaceable^ item, bool isStore)
{
	TreeNode^ node = gcnew TreeNode();
	node->Text = item->getName();
	node->ToolTipText = item->getDescription();
	node->Tag = item;
	if (isStore)
	{
		node->BackColor = System::Drawing::Color::Gainsboro;
		node->ForeColor = System::Drawing::Color::Green;
	}
	return node;
}

void Program::ComponentMutator::addChildrenToNode(System::Windows::Forms::TreeNode^ parent, System::Collections::Generic::List<IPlaceable^>^ elements)
{
	for each (IPlaceable ^ element in elements)
	{
		if (element->GetType()->Name == L"Item")
		{
			auto node = ComponentMutator::createTreeNode(element, false);
			parent->Nodes->Add(node);
		}
		else if (element->GetType()->Name == L"Compartment")
		{
			Compartment^ compartment = dynamic_cast<Compartment^>(element);
			if (compartment == nullptr)
			{
				ProgramState::handleError(
					System::String::Format(L"Element {0} nie zawiera prawid³owego wskaŸnika", 
						element->getName())
				);
				return;
			}
			auto node = ComponentMutator::createTreeNode(element, true);
			ComponentMutator::addChildrenToNode(node, compartment->getContents());
			parent->Nodes->Add(node);
		}
	}
}

