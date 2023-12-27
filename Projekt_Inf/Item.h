#pragma once

#include "Storage.h"
#include "IPlaceable.h"

namespace ProjektInf {

	ref class Item : IPlaceable
	{
	protected:
		System::UInt16 quantity;
		System::Int32 decaysOn;
		System::Int32 stockpileAlert = -1;

		System::String^ displayName;
		System::String^ description;

		CStore^ location;

	public:

		Item(System::String^ displayName, System::String^ description, System::UInt16 quantity);
		
		System::UInt16 getQuantity()
		{
			return quantity;
		}

		virtual void decaysIn() {};
		virtual void zero();

		virtual System::String^ getDescription();
		virtual System::String^ getName();

		virtual bool setName(System::String^ name);
		virtual bool setDescription(System::String^ description);

		virtual CStore^ parent();
	};

}