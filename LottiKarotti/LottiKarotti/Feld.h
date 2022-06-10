#pragma once
#include "Hase.h"
#include <iostream>

class Feld
{
	

protected:
	std::string m_feldTyp;
	Hase* m_figurAufFeld = nullptr;
	int m_feldNr;

public:
	virtual void SetzeFigurAufFeld(Hase *figur);
	void EntferneFigurVonFeld();
	virtual std::string GetFeldTyp()=0;
	Feld(int feldNr);
	bool IstBesetzt();
};

