#include "CPerson.h"


string CPerson::GetName() {
	return name;
};

bool CPerson::WantsToMove() {
	int num = rand() % 100 + 1;
	if (num >= movChancePercent) return true;
	else return false;
};