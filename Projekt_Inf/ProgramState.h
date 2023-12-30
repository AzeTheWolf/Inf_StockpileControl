#pragma once
#include "Storage.h"

namespace ProjektInf {

	using namespace System::Windows::Forms;

	ref class ProgramState abstract sealed
	{
	public:
		static CStore^ masterStorage = gcnew CStore;

		static bool confirmBox(System::String^ title, System::String^ text, MessageBoxIcon icon)
		{
			auto box = MessageBox::Show(text, title, MessageBoxButtons::OKCancel, icon);
			return box == System::Windows::Forms::DialogResult::OK;
		}
	};

}
