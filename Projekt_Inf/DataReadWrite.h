#pragma once

#include <mysql_connection.h>
#include <mysql_driver.h>

namespace Program
{
	ref class Item;
	interface class IPlaceable;
	ref class CStore;
	ref class Compartment;

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
			static void
				_deconvertAndPlace(System::Collections::Generic::List<PlaceableData^>^ input, CStore^ parent);
		public:
			static System::String^ path = nullptr;

			static void write();
			static void read(System::String^ path);
		};


		ref class DatabaseConnection sealed
		{
		private:
			sql::mysql::MySQL_Driver* driver;
			sql::Connection* conn;
			bool isClosed = true;
		public:
			~DatabaseConnection();

			void openConnection();
			void closeConnection();

			void putDatabaseItemRecord(Item^ item);
			void delDatabaseItemRecord(Item^ item);
			void putDatabaseStoreRecord(Compartment^ store);
			void delDatabaseStoreRecord(Compartment^ store);

			void emptyDatabaseItemTable();
			void emptyDatabaseStoreTable();

			void updateDatabaseItemEntry(System::String^ col, System::String^ value, System::Guid^ uuid);

			void purge(Compartment^ store);
		};
	}
}

