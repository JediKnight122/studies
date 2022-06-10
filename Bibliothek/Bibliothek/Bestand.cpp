#include "Bestand.h"

#include <iostream>
#include <ostream>

#include "DVD.h"


void Bestand::ErstelleBestand()
{

	werkListe.insert(new Buch(("Herr der Ringe"), 1995));
	werkListe.insert(new Buch(("Star Wars: EP3"), 1925));
	werkListe.insert(new Buch(("FGLE"), 1259));
	werkListe.insert(new Buch(("Lasergladiator"), 2023));
	werkListe.insert(new DVD("Tribute von Panem", 2001));
	werkListe.insert(new DVD("Ups: Die Pannenshow", 2101));
}

Bestand::Bestand()
{
	ErstelleBestand();
}

Publikation* Bestand::SucheWerk(std::string pName)
{
	for (auto* publication : werkListe)
		if (publication->GetName() == pName)
			return publication;

	return nullptr;
}
