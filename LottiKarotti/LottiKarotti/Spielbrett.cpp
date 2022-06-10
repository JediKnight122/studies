#include "Spielbrett.h"
#include <iostream>
Spielbrett::Spielbrett(int anzahlFelder) : spielfeld(new Feld*[anzahlFelder])
{
	for (int i = 0; i < anzahlFelder-1; i++)
	{
		if (i%3==0)
		{
			spielfeld[i] = new Lochfeld(i, rand()%6+4);
		}
		else {
			spielfeld[i] = new Standardfeld(i);
		}
	}

	spielfeld[24] = new Zielfeld(24);

	std::cout << typeid(spielfeld[24]).name();
}

void Spielbrett::SetzeFigurAufFeld(Hase *figur, int feldNr)
{
	if (feldNr > 24) feldNr = 24;
	spielfeld[feldNr]->SetzeFigurAufFeld(figur);
}
bool Spielbrett::IstFeldBesetzt(int feldNr)
{
	return spielfeld[feldNr]->IstBesetzt();
}

std::string Spielbrett::GetFeldTyp(int feldNr)
{
	return spielfeld[feldNr]->GetFeldTyp();
}

void Spielbrett::DreheKarotte()
{
	int i = 0;
	while(i<=24) //Kondition Array Ende finden
	{
		if(dynamic_cast<Lochfeld*>(spielfeld[i]) != nullptr)
		{
			auto* lochfeld = dynamic_cast<Lochfeld*>(spielfeld[i]);
			lochfeld->NaechsteDrehStufe();
		}
		i++;
	}
}

void Spielbrett::EntferneFigurVonFeld(int feldNr)
{
	spielfeld[feldNr]->EntferneFigurVonFeld();
}
