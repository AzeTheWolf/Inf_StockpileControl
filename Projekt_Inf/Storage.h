#pragma once

namespace ProjektInf {
	interface class IPlaceable;
	ref class CStore
	{
	protected:

		System::Collections::Generic::List<IPlaceable^>^ contents;

	public:
		CStore();
		void place(IPlaceable^ object);
		void remove(IPlaceable^ item);
		void sendTo(IPlaceable^ item, CStore^ other);

		System::Collections::Generic::List<IPlaceable^>^ getContents()
		{
			return this->contents;
		}
	};
}
