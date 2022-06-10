#pragma once
#include "CPerson.h"

class CSuspect : public CPerson
{
protected:
	CSuspect* alibi;
public:
	CSuspect(string pName, int iStartfeld, int movChance);
	CSuspect();
	int GetRoomNr();
	void SetRoomNumber(int newRoomNumber);
	void SayGreeting(); // ToDo: Implemenieren
	void SetAlibi(CSuspect* pAlibi);
	virtual string  GetAlibiName() override;
};
