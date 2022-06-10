#pragma once
#include "Feld.h"
#include "Zielfeld.h"
#include  "Lochfeld.h"
#include  "Hase.h"
#include "Standardfeld.h"


class Spielbrett
{
private: Feld** spielfeld;

public:
	Spielbrett(int anzahlFelder);
	void SetzeFigurAufFeld(Hase *figur, int feldNr);
	void EntferneFigurVonFeld(int feldNr);
	bool IstFeldBesetzt(int feldNr);
	std::string GetFeldTyp(int feldNr);
	void DreheKarotte();
};

