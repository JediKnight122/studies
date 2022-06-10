#pragma once
#include <string>

#include "CSuspect.h"
#include "CRoom.h"

class GameManager
{
public:
	constexpr static uint8_t maxSuspects = 7;
	constexpr static uint8_t maxRooms = 9;
private:
	CSuspect** suspectList;
	CRoom* roomList;
	int murderNr;
	CSuspect* murderer;

public:
	GameManager();
	~GameManager();

	void Init();
	std::string GetRoomName(int pRoomNumber);
	std::string GetRoomArtikel(int pRoomNumber);
	std::string GetRoomPraeposition(int pRoomNumber);
	int GetNumPeopleInRoom(int pRoomNumber);
	std::string GetPersonName(int pRoomNumber, int pPersonNumber);
	std::string GetAlibiName(int pRoomNumber, int pPersonNumber);
	std::string MoveAI(int playerRoomNumber);
	bool CheckIfIsMurder(int iSuspectNumber);
	GameManager(int numPlayers);
	void SelectMurderer();

};