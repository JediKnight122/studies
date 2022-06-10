#pragma once
#include "CSuspect.h"


class CRoom
{
private:
	string roomName;
	string artikel;
	string praeposition;
	CPerson* peopleInRoom[15] = {};
	int iNumberPeopleInRoom = 0;

public:
	CRoom(string pName, string pArtikel, string pPraeposition);
	CRoom();
	void AddPersonToRoom(CPerson* person);
	void RemovePersonFromRoom(CPerson person);
	int GetNumberPeopleInside();
	string GetName();
	string GetArtikel();
	string GetPraeposition();
	string GetNameOfPerson(int numPerson);
	CPerson GetPerson(int numPerson);
	string GetAlibiOfPerson(int numPerson);
};

