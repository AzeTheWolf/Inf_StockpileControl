#pragma once

namespace ProjektInf {
	ref class CStore;

    interface class IPlaceable
	{
		virtual void zero();
		virtual void decaysIn();

		virtual System::String^ getName();
		virtual bool setName(System::String^ name);

		virtual System::String^ getDescription();
		virtual bool setDescription(System::String^ description);

		virtual CStore^ parent();
		virtual void setParent(CStore^ parent);

		virtual System::Collections::Generic::List<IPlaceable^>^ getItems();
	};
}
