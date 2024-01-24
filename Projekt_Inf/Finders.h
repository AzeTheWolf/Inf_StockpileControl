#pragma once

namespace Program {
	interface class IPlaceable;
	ref class CStore;
	namespace Helpers
	{
		ref class FindListViewItem
		{
			Object^ Tag;

		public:
			FindListViewItem(Object^ tag);

			bool isIn(System::Windows::Forms::ListViewItem^ lvi);
		};

		ref class FindPlaceableByGUID
		{
			System::Guid^ guid;

		public:
			FindPlaceableByGUID(System::Guid^ guid);

			bool isIn(IPlaceable^ placeable);
		};

		ref class FindStoreByGUID
		{
			System::Guid^ guid;

		public:
			FindStoreByGUID(System::Guid^ store);

			bool isIn(CStore^ placeable);
		};
	}	
}