#include "DVD.h"

const std::string& DVD::GetName() const
{
	return name;
}

DVD::DVD(std::string name, int erscheinungsJahr): Publikation(name, erscheinungsJahr)
{
}
