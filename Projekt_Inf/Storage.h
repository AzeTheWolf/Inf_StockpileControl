#pragma once

namespace Program {
	ref class Item;
	interface class IPlaceable;

	ref class CStore
	{
	protected:

		System::Collections::Generic::List<IPlaceable^>^ contents;

	public:
		CStore();
		void place(IPlaceable^ object);
		void remove(IPlaceable^ object);
		virtual System::Collections::Generic::List<Item^>^ getItems();

		System::Collections::Generic::List<IPlaceable^>^ getContents();

		virtual System::Guid^ getUUID();

		System::Collections::Generic::List<IPlaceable^>^ flattenStorage();
	};
}
