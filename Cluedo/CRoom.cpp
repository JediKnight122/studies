#include "CRoom.h"
#include <string.h>

void CRoom::AddPersonToRoom(CPerson *person) {
	peopleInRoom[iNumberPeopleInRoom] = person;
	iNumberPeopleInRoom++;
}

void CRoom::RemovePersonFromRoom(CPerson person) {
	CPerson* newPeopleInRoom[15];

	for (int k=0, i = 0; i <= iNumberPeopleInRoom-1; i++) {
		CPerson p = *peopleInRoom[i];
		if (p.GetName() != person.GetName()) {
			(newPeopleInRoom[k]) = peopleInRoom[i];
			k++;
		}
	}

	iNumberPeopleInRoom--;
	if (iNumberPeopleInRoom < 0) iNumberPeopleInRoom = 0;

	for (int i = 0; i <= iNumberPeopleInRoom; i++) {
		peopleInRoom[i] = newPeopleInRoom[i];
	}
	
}

string CRoom::GetName() {
	return roomName;
}

string CRoom::GetNameOfPerson(int numPerson) {
	CPerson p = *peopleInRoom[numPerson];
	return p.GetName();
}
string CRoom::GetAlibiOfPerson(int numPerson) {
	peopleInRoom[numPerson]->WantsToMove();
	return peopleInRoom[numPerson]->GetAlibiName();
}

int CRoom::GetNumberPeopleInside() {
	return iNumberPeopleInRoom;
}

CRoom::CRoom(string pName, string pArtikel, string pPraeposition) {
	roomName = pName;
	artikel = pArtikel;
	praeposition = pPraeposition;
}

string CRoom::GetArtikel() {
	return artikel;
}
string CRoom::GetPraeposition() {
	return praeposition;
}

CPerson CRoom::GetPerson(int numPerson) {
	return *peopleInRoom[numPerson];
}
CRoom::CRoom() {

}