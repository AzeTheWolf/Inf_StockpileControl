#pragma once

#include "IPlaceable.h"
#include "Storage.h"

namespace ProjektInf {

	ref class Compartment : public CStore, IPlaceable
	{
	protected:
		System::String^ displayName;
		System::String^ description;
	public:
		Compartment(System::String^ displayName, System::String^ description);
		virtual void zero();
		virtual void decaysIn() {};

		virtual System::String^ getName();
		virtual bool setName(System::String^ name);

		virtual System::String^ getDescription();
		virtual bool setDescription(System::String^ description);
	};

}