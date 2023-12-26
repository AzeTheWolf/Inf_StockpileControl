#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//ProjektInf::MainWindow form;
	ProjektInf::MainWindow^ form = gcnew ProjektInf::MainWindow;
	Application::Run(form);
	return;
}

