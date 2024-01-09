#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//ProjektInf::MainWindow form;
	Program::MainWindow^ form = gcnew Program::MainWindow;
	Application::Run(form);
	return;
}

