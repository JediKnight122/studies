#include "Kunde.h"

Kunde::Kunde(int nr, std::string pName) : name(pName), ausweisNr(nr)
{
}

bool Kunde::LeiheElement(Publikation* element)
{
	if (ausgelieheneElemente.size() == 2) return false;
	ausgelieheneElemente.insert_or_assign(element->GetName(), element);
	
	return true;
}

void Kunde::GibElementZurueck(Publikation* element)
{ 
	if (anzahlAusgeliehendeElemente > 0) anzahlAusgeliehendeElemente--;
	ausgelieheneElemente.erase(ausgelieheneElemente.find(element->GetName()));
}

std::string Kunde::GetName()
{
	return name;
}
