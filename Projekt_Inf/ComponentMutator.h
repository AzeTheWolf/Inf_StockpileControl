#pragma once

namespace Program
{
	ref class Item;

	ref class ComponentMutator sealed
	{
		void removeFromListView(System::Windows::Forms::ListView^ component, Item^ item);
	};
}

