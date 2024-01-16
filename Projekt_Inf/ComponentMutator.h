#pragma once
#include "IPlaceable.h"

namespace Program
{
	ref class Item;

	ref class ComponentMutator abstract sealed
	{
	private:
		static System::Collections::Generic::List<System::Windows::Forms::TreeNode^>^ _flattenTree(
			System::Windows::Forms::TreeNode^ root
		);
	public:
		static void removeFromListView(System::Windows::Forms::ListView^ component, Item^ item);
		static void addChildrenToNode(
			System::Windows::Forms::TreeNode^ parent,
			System::Collections::Generic::List<IPlaceable^>^ elements
		);

		static System::Windows::Forms::TreeNode^ createTreeNode(IPlaceable^ item, bool isStore);

		static void removeAllItems(System::Windows::Forms::TreeNode^ root);
	};
}

