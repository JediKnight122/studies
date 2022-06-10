#pragma once
#include "Publikation.h"
class DVD :
    public Publikation
{
public:
	const std::string& GetName() const override;
	DVD(std::string name, int erscheinungsJahr);
};

