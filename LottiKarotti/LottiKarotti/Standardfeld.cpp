#include "Standardfeld.h"
std::string Standardfeld::GetFeldTyp()
{
	return m_feldTyp;
}

Standardfeld::Standardfeld(int feldNr): Feld(feldNr)
{
	m_feldTyp = "ein normales Feld";
}
