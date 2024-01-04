#include "Item.h"
#include "ProgramState.h"
#include "Compartment.h"

using namespace ProjektInf;

Item::Item(System::String^ displayName, System::String^ description, System::UInt16 quantity)
{
    this->quantity = (quantity < 0) ? 0 : quantity;
    this->displayName = System::String::IsNullOrEmpty(displayName)
        ? L"Przedmiot"
        : displayName;
    this->description = description;

    this->decaysOn = System::DateTime(9999, 1, 1, 0, 0, 0, 0);
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

System::UInt16 Item::getQuantity()
{
    return this->quantity;
}

System::DateTime ProjektInf::Item::getDecayDate()
{
    return this->decaysOn;
}

System::UInt16 ProjektInf::Item::getAlertLevel()
{
    return this->stockpileAlert;
}

bool ProjektInf::Item::setQuantity(System::UInt16 quantity)
{
    this->quantity = quantity;
    
    return true;
}

bool ProjektInf::Item::setDecayDate(System::DateTime date)
{
    this->decaysOn = date;
    
    return true;
}

void ProjektInf::Item::setAlertLevel(System::UInt16 qty)
{
    this->stockpileAlert = qty;
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

System::String^ ProjektInf::Item::getPath()
{
    System::String^ parentPath;
    Compartment^ loc = dynamic_cast<Compartment^>(this->location);

    if (this->location == ProgramState::masterStorage || loc == nullptr)
    {
        parentPath = "";
    }
    else
    {
        parentPath = loc->getPath();
    }
    return System::String::Format(L"{0}/{1}", parentPath, this->displayName);
}
