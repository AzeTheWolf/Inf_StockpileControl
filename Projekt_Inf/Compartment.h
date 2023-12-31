#pragma once

#include "Storage.h"
#include "IPlaceable.h"

namespace ProjektInf {

	ref class Compartment : public CStore, IPlaceable
	{
	protected:
		System::String^ displayName;
		System::String^ description;
		CStore^ location = nullptr;
	public:
		Compartment(System::String^ displayName, System::String^ description);
		virtual void zero();
		virtual void decaysIn() {};

		virtual System::String^ getName();
		virtual bool setName(System::String^ name);

		virtual System::String^ getDescription();
		virtual bool setDescription(System::String^ description);

		virtual CStore^ parent();
		virtual void setParent(CStore^ parent);

		virtual System::Collections::Generic::List<IPlaceable^>^ getItems();
		virtual System::String^ getPath();
	};

}