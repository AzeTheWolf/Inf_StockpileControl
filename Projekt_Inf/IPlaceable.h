#pragma once

namespace Program {
	ref class CStore;
	ref class Item;

    interface class IPlaceable
	{
		virtual void zero();

		virtual System::String^ getName();
		virtual bool setName(System::String^ name);

		virtual System::String^ getDescription();
		virtual bool setDescription(System::String^ description);

		virtual CStore^ parent();
		virtual void setParent(CStore^ parent);

		virtual System::Collections::Generic::List<Item^>^ getItems();
		virtual System::String^ getPath();

		virtual System::Guid^ getUUID();
	};
}
