#include "Zielfeld.h"

Zielfeld::Zielfeld(int feldNr): Feld((feldNr))
{
	m_feldTyp = "das Zielfeld";
	
}

void Zielfeld::SetzeFigurAufFeld(Hase *figur)
{
	figur->ErreicheZiel();
}

std::string Zielfeld::GetFeldTyp()
{
	return m_feldTyp;
}
