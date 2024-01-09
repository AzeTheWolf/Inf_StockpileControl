#pragma once

namespace Program {
	namespace Helpers
	{
		ref class FindListViewItem
		{
			Object^ Tag;

		public:
			FindListViewItem(Object^ tag);

			bool isIn(System::Windows::Forms::ListViewItem^ lvi);
		};
	}	
}