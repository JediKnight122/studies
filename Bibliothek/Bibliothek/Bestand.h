#pragma once
#include <set>

#include "Publikation.h"

#include "Buch.h"

class Bestand
{
	std::multiset<Publikation*,  Publikation::ErscheinungsjahrCompare> werkListe;

private:
	void ErstelleBestand();
public:
	Bestand();
	Publikation* SucheWerk(std::string pName);
};

