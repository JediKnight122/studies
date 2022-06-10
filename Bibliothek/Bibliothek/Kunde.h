#pragma once
#include <map>
#include <string>
#include "Publikation.h"

class Kunde
{
private:
	std::string name;
	int ausweisNr;
	int anzahlAusgeliehendeElemente;
	std::map<std::string, Publikation*> ausgelieheneElemente;


public:
	Kunde(int nr, std::string pName);
	bool LeiheElement(Publikation* element);
	void GibElementZurueck(Publikation* element);
	std::string GetName();
};

