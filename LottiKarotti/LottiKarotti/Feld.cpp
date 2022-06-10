#include "Feld.h"

void Feld::SetzeFigurAufFeld(Hase *figur)
{
	m_figurAufFeld = figur;
}

void Feld::EntferneFigurVonFeld()
{
	m_figurAufFeld = nullptr;
}

Feld::Feld(int feldNr)
{
	m_feldNr = feldNr;
}

bool Feld::IstBesetzt()
{
	if (m_figurAufFeld == nullptr) return false;
	else return true;
}

