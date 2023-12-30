#include "Item.h"

using namespace ProjektInf;

Item::Item(System::String^ displayName, System::String^ description, System::UInt16 quantity)
{
    this->quantity = (quantity < 0) ? 0 : quantity;
    this->displayName = System::String::IsNullOrEmpty(displayName)
        ? L"Przedmiot"
        : displayName;
    this->description = description;
}

void Item::zero()
{
    this->quantity = 0;
}

System::String^ ProjektInf::Item::getDescription()
{
    return this->description;
}

System::String^ ProjektInf::Item::getName()
{
    return this->displayName;
}

bool ProjektInf::Item::setName(System::String^ name)
{
    if (System::String::IsNullOrWhiteSpace(name)) return false;

    this->displayName = name;
    return true;
}

bool ProjektInf::Item::setDescription(System::String^ description)
{
    if (description == nullptr) return false;

    this->description = description;
    return true;
}

CStore^ ProjektInf::Item::parent()
{
    return this->location;
}

void ProjektInf::Item::setParent(CStore^ parent)
{
    this->location = parent;
}


System::Collections::Generic::List<IPlaceable^>^ ProjektInf::Item::getItems()
{
    auto list = gcnew System::Collections::Generic::List<IPlaceable^>;
    list->Add(this);
    return list;
}
