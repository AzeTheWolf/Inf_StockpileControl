#pragma once

namespace Program
{
	ref class Item;
	interface class IPlaceable;

	namespace DataReadWrite
	{
		public enum ElementType { ITEM, COMPARTMENT };

		[System::Serializable]
		public ref struct PlaceableData
		{
		public:
			System::UInt16 quantity;
			System::DateTime decaysOn;
			System::UInt16 stockpileAlert = 0;

			System::String^ displayName;
			System::String^ description;

			System::Collections::Generic::List<PlaceableData^>^ contents;
			System::UInt16 type;
		};

		ref class FileIO abstract sealed
		{
		private:
			static System::Collections::Generic::List<PlaceableData^>^
				_convert(System::Collections::Generic::List<IPlaceable^>^ input);
		public:
			static void write();
		};
	}
}

