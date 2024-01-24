#pragma once
#include "Storage.h"
#include "IPlaceable.h"
#include "Compartment.h"
#include "DataReadWrite.h"

namespace Program {

	using namespace System::Windows::Forms;
	using namespace Program::DataReadWrite;

	ref class ProgramState abstract sealed
	{
	public:
		static CStore^ masterStorage = gcnew CStore;
		static DatabaseConnection^ dbc = gcnew DatabaseConnection;
		static bool isRemote = false;
		static System::String^ titleTemplate = L"Magazyn {0}";

		static bool confirmBox(System::String^ title, System::String^ text, MessageBoxIcon icon)
		{
			auto box = MessageBox::Show(text, title, MessageBoxButtons::OKCancel, icon);
			return box == System::Windows::Forms::DialogResult::OK;
		}

		static System::Void handleError(System::String^ message)
		{
			auto box = MessageBox::Show(
				System::String::Format(
					L"{0} Kliknij OK aby kontynuowaæ, lub Anuluj aby zakoñczyæ program",
					message
				),
				L"Aplikacja napotka³a niespodziewany b³¹d!", 
				MessageBoxButtons::OKCancel,
				MessageBoxIcon::Error
			);

			if (box == System::Windows::Forms::DialogResult::Cancel)
			{
				Application::Exit();
			}
		}

		static System::Collections::Generic::List<IPlaceable^>^ flattenStorage(CStore^ root)
		{
			System::Collections::Generic::List<IPlaceable^>^ list
				= gcnew System::Collections::Generic::List<IPlaceable^>;

			for each (IPlaceable ^ element in root->getContents())
			{
				list->Add(element);
				if (element->GetType()->Name == L"Compartment")
				{
					Compartment^ compartment = dynamic_cast<Compartment^>(element);

					list->AddRange(ProgramState::flattenStorage(compartment));
				}
			}
			return list;
		}
	};

}
