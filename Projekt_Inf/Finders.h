#pragma once

namespace Program {
	interface class IPlaceable;
	ref class CStore;
	ref class Item;
	ref class Compartment;
	namespace Helpers
	{
		ref class FindListViewItem
		{
			Object^ Tag;

		public:
			FindListViewItem(Object^ tag);

			bool isIn(System::Windows::Forms::ListViewItem^ lvi);
		};

		ref class FindByGUID
		{
			System::String^ guid;

		public:
			FindByGUID(System::String^ guid);

			bool isInStore(Compartment^ element);
			bool isInItem(Item^ element);
		};

		//IPlaceable^ FindByGUIDString(System::String^ string, System::Collections::Generic::List<Item^>^ list);
		//Compartment^ FindByGUIDString(System::String^ string, System::Collections::Generic::List<Compartment^>^ list);
		//CStore^ FindByGUIDString(System::String^ string, System::Collections::Generic::List<CStore^>^ list);
	}	
}