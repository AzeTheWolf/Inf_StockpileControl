#include "Storage.h"
#include "IPlaceable.h"

using namespace ProjektInf;

ProjektInf::CStore::CStore()
{
	this->contents = gcnew System::Collections::Generic::List<IPlaceable^>();
}

void CStore::place(IPlaceable^ object)
{
	//if (this->contents->BinarySearch(object) < 0)
	{
		this->contents->Add(object);
	}
}

void CStore::remove(IPlaceable^ item)
{
	this->contents->Remove(item);
}

void ProjektInf::CStore::sendTo(IPlaceable^ item, CStore^ other)
{
	other->place(item);
	this->remove(item);
}
