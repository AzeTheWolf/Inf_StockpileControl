#pragma once

namespace ProjektInf {

    interface class IPlaceable
	{
		virtual void zero();
		virtual void decaysIn();

		virtual System::String^ getName();
		virtual bool setName(System::String^ name);

		virtual System::String^ getDescription();
		virtual bool setDescription(System::String^ description);
	};
}
