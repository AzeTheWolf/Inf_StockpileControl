#pragma once

namespace Program
{
	ref class Item;

	ref class ComponentMutator sealed
	{
	public:
		static void removeFromListView(System::Windows::Forms::ListView^ component, Item^ item);
	};
}

