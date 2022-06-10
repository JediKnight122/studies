// LottiKarotti.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <stdlib.h>
#include "Spielbrett.h"
#include "Spieler.h"

bool spielAktiv = true;

int activePlayer = 0;
const int numberOfPlayers = 4;
const int spielFeldLaenge = 25;

Spieler spielerListe[numberOfPlayers] = { Spieler("blaue"), Spieler("rote"), Spieler("gelbe"), Spieler("gruene") };

Spielbrett spielbrett(spielFeldLaenge);

int GetMovementCard()
{
	int movementCount = rand() % 48;
	if (movementCount <= 24) return 1;
	else if (movementCount <= 33) return 2;
	else if (movementCount <= 36) return 3;
	else return 0;
}

void NextRound()
{
	std::cout << "Spieler " << activePlayer + 1 << " ist am Zug.\n";

	int moveNumber = GetMovementCard();

	if (moveNumber == 0)
	{
		//Möhre drehen
		std::cout << "***\nDie Karotte dreht sich.\n***\n";
		spielbrett.DreheKarotte();
	}
	else
	{
		//Einen Hasen bewegen

		Hase* aktiveFigur = spielerListe[activePlayer].waehleFigur();
		if(aktiveFigur==nullptr)
		{
			std::cout << "Oje! Der Spieler hat keine Hasen mehr und ist somit raus.\n";
			return;
		}
		int aktuellesFeld = aktiveFigur->GetFeldNr();

		std::cout << "Er darf " << moveNumber << " Felder gehen.\n";

		for (int i = 1; i <= moveNumber; i++)
		{
			if (aktuellesFeld + moveNumber >= spielFeldLaenge)
			{
				moveNumber = spielFeldLaenge - aktuellesFeld;
				break;
			}
			else if (spielbrett.IstFeldBesetzt(aktuellesFeld + i)) {
				moveNumber++;
				std::cout << "Feld " << aktuellesFeld + i << " ist besetzt von: es wird uebersprungen.\n";
			}
		}

		int neueFeldNr = aktuellesFeld + moveNumber;

		if (neueFeldNr > 24) neueFeldNr = 24;


		std::cout << "Der " << aktiveFigur->GetFarbe() << " Hase " << aktiveFigur->GetName() << " ist von Feld " << aktuellesFeld << " auf Feld " << neueFeldNr << " gesprungen.\n -> Es ist  " << spielbrett.GetFeldTyp(neueFeldNr) << " \n";

		spielbrett.EntferneFigurVonFeld(aktuellesFeld);
		spielbrett.SetzeFigurAufFeld(aktiveFigur, neueFeldNr);

		aktiveFigur->SetzeFeldNr(neueFeldNr);

		if (aktiveFigur->ImZiel()) {
			std::cout << "Der " << aktiveFigur->GetFarbe() << " Hase " << aktiveFigur->GetName() << " ist im Ziel!\n";
			std::cout << "\n********Der " << aktiveFigur->GetFarbe() << " Spieler gewinnt!********";
			spielAktiv = false;
		}

		activePlayer++;
		if (activePlayer >= numberOfPlayers) activePlayer = 0;

	}
}



int main()
{
	srand(time(NULL));

	while (spielAktiv) {
		NextRound();
		std::cout << "\n";
	}
}

