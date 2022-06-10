#include "GameManager.h"
#include "CSuspect.h"
#include "CRoom.h"


GameManager::GameManager() {
	suspectList = new CSuspect * [maxSuspects] { nullptr };
	roomList = new CRoom[maxRooms];
}
GameManager::~GameManager() {
	for (uint8_t i = 0; i < maxSuspects; ++i)
		delete suspectList[i];
	delete[] suspectList;
	delete[] roomList;
}

void GameManager::Init() {

	//Alle Suspects erzeugen
	CSuspect* frauWeiss = new CSuspect("Frau Weiss", 2, 45);
	CSuspect* oberstVonGatow = new CSuspect("Oberst von Gatow", 1, 78);
	CSuspect* frauWiesental = new CSuspect("Frau Wiesental", 3, 42);
	CSuspect* hausmeister = new CSuspect("Hausmeister", 4, 8);
	CSuspect* baroninVonPorz = new CSuspect("Baronin Von Porz", 6, 90);
	CSuspect* sirAnton = new CSuspect("Sir Anton",5, 69);
	CSuspect* reverendGruen = new CSuspect("Reverend Gruen",7, 30);


	suspectList[0] = frauWeiss;
	suspectList[1] = oberstVonGatow;
	suspectList[2] = frauWiesental;
	suspectList[3] = hausmeister;
	suspectList[4] = baroninVonPorz;
	suspectList[5] = sirAnton;
	suspectList[6] = reverendGruen;

	//Alle Raeume erzeugen
	CRoom* salon = new CRoom("Salon", "den", "im");
	CRoom* hall = new CRoom("Halle", "die", "in der");
	CRoom* buero = new CRoom("Buero", "das", "im");
	CRoom* library = new CRoom("Yoga-Bibliothek", "die", "in der");
	CRoom* billiardroom = new CRoom("Billiardzimmer", "das", "im");
	CRoom* veranda = new CRoom("Veranda", "die", "auf der");
	CRoom* livingroom = new CRoom("Wohnzimmer", "das", "im");
	CRoom* kitchen = new CRoom("Kueche", "die", "in der");
	CRoom* dininghall = new CRoom("Esszimmer", "das", "im");


	roomList[0] = *salon;
	roomList[1] = *hall;
	roomList[2] = *buero;
	roomList[3] = *library;
	roomList[4] = *billiardroom;
	roomList[5] = *veranda;
	roomList[6] = *livingroom;
	roomList[7] = *kitchen;
	roomList[8] = *dininghall;


	//Den Räumen werden die Personen hinzugefügt, die dort starten.
	roomList[frauWeiss->GetRoomNr()].AddPersonToRoom(frauWeiss);
	roomList[frauWiesental->GetRoomNr()].AddPersonToRoom(frauWiesental);
	roomList[oberstVonGatow->GetRoomNr()].AddPersonToRoom(oberstVonGatow);
	roomList[hausmeister->GetRoomNr()].AddPersonToRoom(hausmeister);
	roomList[reverendGruen->GetRoomNr()].AddPersonToRoom(reverendGruen);
	roomList[baroninVonPorz->GetRoomNr()].AddPersonToRoom(baroninVonPorz);
	roomList[sirAnton->GetRoomNr()].AddPersonToRoom(sirAnton);

	SelectMurderer();
	murderer = suspectList[murderNr];

	for (int k=6, i = 0; i <= 6; i++) {
		if (k == murderNr) k--;
		suspectList[i]->SetAlibi(suspectList[k]);
		k--;
		if (k < 0) {
			do {
				k = rand() % 6;
			} while (k == murderNr);
		}
	}
};

string GameManager::GetRoomName(int pRoomNumber) {
	return roomList[pRoomNumber].GetName();
};

string GameManager::GetRoomArtikel(int pRoomNumber) {
	return roomList[pRoomNumber].GetArtikel();
};

string GameManager::GetRoomPraeposition(int pRoomNumber) {
	return roomList[pRoomNumber].GetPraeposition();
};

string GameManager::GetPersonName(int pRoomNumber, int pPersonNumber) {
	return roomList[pRoomNumber].GetNameOfPerson(pPersonNumber);
};

bool GameManager::CheckIfIsMurder(int iSuspectNumber) {
	if (suspectList[iSuspectNumber]->GetName()==murderer->GetName()) {
		return true;
	}
	else return false;
}

string GameManager::GetAlibiName(int pRoomNumber, int pPersonNumber) {
	return roomList[pRoomNumber].GetAlibiOfPerson(pPersonNumber);
};

int GameManager::GetNumPeopleInRoom(int pRoomNumber) {
	return roomList[pRoomNumber].GetNumberPeopleInside();
}

string GameManager::MoveAI(int playerRoomNumber) {
	string personMoveLog="";

	for (int i = 0;  i <= 6; i++)
	{
		if (suspectList[i]->WantsToMove()) {

			if (playerRoomNumber == suspectList[i]->GetRoomNr()) {
				personMoveLog += suspectList[i]->GetName() + " hat " + roomList[playerRoomNumber].GetArtikel()+" "+roomList[playerRoomNumber].GetName() + " verlassen.\n";
			}
			int newRoomNr;

			do {
				newRoomNr = rand() % 8 + 1;

			} while (newRoomNr == suspectList[i]->GetRoomNr());

			roomList[suspectList[i]->GetRoomNr()].RemovePersonFromRoom(*suspectList[i]);
			roomList[newRoomNr].AddPersonToRoom(suspectList[i]);
			suspectList[i]->SetRoomNumber(newRoomNr);

			if (playerRoomNumber == newRoomNr) {
				personMoveLog += suspectList[i]->GetName() + " hat " + roomList[playerRoomNumber].GetArtikel()+" "+roomList[playerRoomNumber].GetName() + " betreten.\n";
			}
		}
	}
	return personMoveLog;
};


void GameManager::SelectMurderer() {
	murderNr = rand() % 6;
}

GameManager::GameManager(int numPlayers) {

};
