#include "Placeable.h"

#include "Storage.h"

using namespace ProjektInf;

Placeable::Placeable(System::String^ displayName, System::String^ description)
{
    this->displayName = displayName;
    this->description = description;
}