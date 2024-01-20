#pragma once

#include "IPlaceable.h"

namespace Program {
	ref class CStore;

	ref class Item : Program::IPlaceable
	{
	private:
		System::Guid^ uuid;
	protected:
		System::UInt16 quantity;
		System::DateTime decaysOn;
		System::UInt16 stockpileAlert = 0;

		System::String^ displayName;
		System::String^ description;

		CStore^ location;
	public:

		Item(System::String^ displayName, System::String^ description, System::UInt16 quantity);
		
		virtual void zero();

		virtual System::String^ getDescription();
		virtual System::String^ getName();
		virtual System::UInt16 getQuantity();
		System::DateTime getDecayDate();
		System::UInt16 getAlertLevel();

		virtual bool setName(System::String^ name);
		virtual bool setDescription(System::String^ description);
		virtual bool setQuantity(System::UInt16 quantity);
		bool setDecayDate(System::DateTime date);
		void setAlertLevel(System::UInt16 qty);

		virtual CStore^ parent();
		virtual void setParent(CStore^ parent);

		virtual System::Collections::Generic::List<Item^>^ getItems();
		virtual System::String^ getPath();

		virtual System::Guid^ getUUID();
	};

}