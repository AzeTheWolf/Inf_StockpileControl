#include "BoxHandler.h"

using namespace System::Windows::Forms;
using namespace Program::Helpers;

void BoxHandler::handleError(System::String^ message)
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

bool BoxHandler::confirmBox(System::String^ title, System::String^ text, MessageBoxIcon icon)
{
	auto box = MessageBox::Show(text, title, MessageBoxButtons::OKCancel, icon);
	return box == System::Windows::Forms::DialogResult::OK;
}
