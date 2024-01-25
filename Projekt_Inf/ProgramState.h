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
	};

}
