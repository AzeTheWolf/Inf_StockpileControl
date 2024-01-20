#include "Compartment.h"
#include "ProgramState.h"

using namespace Program;

Compartment::Compartment(System::String^ displayName, System::String^ description)
{
    this->displayName = System::String::IsNullOrWhiteSpace(displayName)
        ? L"Pojemnik"
        : displayName;
    this->description = description;

    this->uuid = System::Guid::NewGuid();
}

void Compartment::zero()
{
    while (this->contents->Count > 0)
    {
        this->remove(this->contents[0]);
    }
}

System::String^ Compartment::getName()
{
    return this->displayName;
}

bool Compartment::setName(System::String^ name)
{
    if (System::String::IsNullOrWhiteSpace(name)) return false;

    this->displayName = name;
    return true;
}

System::String^ Compartment::getDescription()
{
    return this->description;
}

bool Compartment::setDescription(System::String^ description)
{
    if (description == nullptr) return false;

    this->description = description;
    return true;
}

CStore^ Compartment::parent()
{
    return this->location;
}

void Compartment::setParent(CStore^ parent)
{
    this->location = parent;
}

System::String^ Compartment::getPath()
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

System::Guid^ Program::Compartment::getUUID()
{
    return this->uuid;
}


