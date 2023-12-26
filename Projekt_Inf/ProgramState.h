#pragma once
#include "Storage.h"

namespace ProjektInf {

	ref class ProgramState abstract sealed
	{
	public:
		static CStore^ masterStorage = gcnew CStore;
	};

}
