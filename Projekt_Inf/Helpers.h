#pragma once

namespace ProjektInf {
	ref class FindListViewItem
	{
		Object^ Tag;

	public:
		FindListViewItem(Object^ tag)
		{
			this->Tag = tag;
		}

		bool isIn(System::Windows::Forms::ListViewItem^ lvi)
		{
			return lvi->Tag == this->Tag;
		}
	};

}