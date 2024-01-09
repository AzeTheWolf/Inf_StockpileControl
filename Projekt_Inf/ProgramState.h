#pragma once
#include "Storage.h"

namespace Program {

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

		static bool handleError(System::String^ message)
		{
			auto box = MessageBox::Show(
				L"Aplikacja napotka³a niespodziewany b³¹d!", 
				System::String::Format(
					L"{0} Kliknij OK aby kontynuowaæ, lub Anuluj aby zakoñczyæ program", 
					message
				),
				MessageBoxButtons::OKCancel,
				MessageBoxIcon::Error
			);

			if (box == System::Windows::Forms::DialogResult::Cancel)
			{
				Application::Exit();
			}
		}
	};

}
