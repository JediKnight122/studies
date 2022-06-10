#include "Buch.h"

const std::string& Buch::GetName() const
{
    return name;
}

Buch::Buch(std::string name, int erscheinungsJahr): Publikation(name, erscheinungsJahr)
{

}







