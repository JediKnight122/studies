#pragma once
#include "Publikation.h"
class Buch :
    public Publikation
{
public:
	const std::string& GetName() const override;
	Buch(std::string name, int erscheinungsJahr);
};