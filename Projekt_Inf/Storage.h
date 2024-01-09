#pragma once

namespace Program {
	interface class IPlaceable;
	ref class Item;
	ref class CStore
	{
	protected:

		System::Collections::Generic::List<IPlaceable^>^ contents;

	public:
		CStore();
		void place(IPlaceable^ object);
		void remove(IPlaceable^ object);
		void sendTo(IPlaceable^ item, CStore^ other);
		virtual System::Collections::Generic::List<Item^>^ getItems();

		System::Collections::Generic::List<IPlaceable^>^ getContents()
		{
			return this->contents;
		}
	};
}
