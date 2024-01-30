#include "ComponentMutator.h"
#include "Item.h"
#include "Compartment.h"
#include "Finders.h"
#include "ProgramState.h"
#include "BoxHandler.h"

using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace Program::Helpers;
using namespace Program;

List<TreeNode^>^ ComponentMutator::_flattenTree(TreeNode^ root)
{
	List<TreeNode^>^ list = 
		gcnew List<TreeNode^>;

	for each (TreeNode ^ element in root->Nodes)
	{
		if (element->Tag->GetType()->Name == L"Item")
		{
			list->Add(element);
		}
		else if (element->Tag->GetType()->Name == L"Compartment")
		{
			list->AddRange(ComponentMutator::_flattenTree(element));
		}
	}

	return list;
}

void ComponentMutator::removeFromListView(ListView^ component, Item^ item)
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

TreeNode^ ComponentMutator::createTreeNode(IPlaceable^ item, bool isStore)
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

ListViewItem^ ComponentMutator::createListItem(Item^ item)
{
	ListViewItem^ listItem = gcnew ListViewItem;
	listItem->Text = item->getName();
	listItem->SubItems->Add(item->getQuantity().ToString());
	listItem->SubItems->Add(item->getDecayDate().Year < 9999 ? item->getDecayDate().ToShortDateString() : L"-");
	listItem->SubItems->Add(L"");
	listItem->SubItems->Add(item->getDescription());
	listItem->SubItems->Add(item->getAlertLevel().ToString());
	listItem->Tag = item;

	return listItem;
}

void ComponentMutator::removeAllItems(System::Windows::Forms::TreeNode^ root)
{
	List<TreeNode^>^ list = ComponentMutator::_flattenTree(root);

	for each (TreeNode ^ node in list)
	{
		if (node->Tag->GetType()->Name == L"Item")
		{
			node->Remove();
		}
	}
}

void ComponentMutator::regenerateTree(System::Windows::Forms::TreeView^ tree)
{
	tree->BeginUpdate();

	TreeNode^ root = tree->Nodes[0];
	root->Nodes->Clear();
	ComponentMutator::addChildrenToNode(root, ProgramState::masterStorage->getContents());

	tree->EndUpdate();
}

void ComponentMutator::regenerateList(System::Windows::Forms::ListView^ list)
{
	list->Items->Clear();
	System::Collections::Generic::List<Item^>^ itemList = ProgramState::masterStorage->getItems();

	list->BeginUpdate();
	for each (Item ^ item in itemList)
	{
		ListViewItem^ listItem = ComponentMutator::createListItem(item);

		if (item->getQuantity() <= item->getAlertLevel())
		{
			listItem->ForeColor = System::Drawing::Color::Red;
		}

		if (item->getDecayDate() < System::DateTime::Now)
		{
			listItem->BackColor = System::Drawing::Color::DarkOrange;
		}
		else if (item->getDecayDate() < System::DateTime::Now.AddDays(5))
		{
			listItem->BackColor = System::Drawing::Color::Yellow;
		}

		list->Items->Add(listItem);
	}
	list->EndUpdate();
}

void ComponentMutator::addChildrenToNode(System::Windows::Forms::TreeNode^ parent, System::Collections::Generic::List<IPlaceable^>^ elements)
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
				Helpers::BoxHandler::handleError(
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

