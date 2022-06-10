#include "CSuspect.h"



CSuspect::CSuspect(string pName, int iStartfeld, int moveChance) {
	name = pName;
	roomNr = iStartfeld;
	movChancePercent = moveChance;
}

CSuspect::CSuspect() {

};

int CSuspect::GetRoomNr() {
	return roomNr;
};

void CSuspect::SayGreeting() {}

void CSuspect::SetRoomNumber(int newRoomNumber) {
	roomNr = newRoomNumber;
}
string CSuspect::GetAlibiName() {
	return alibi->GetName();
}


void CSuspect::SetAlibi(CSuspect *pAlibi) {
	alibi=pAlibi;
}

