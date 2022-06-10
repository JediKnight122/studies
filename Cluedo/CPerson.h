#pragma once
#include <string>

using namespace std;

class CPerson
	
{

public: 
	virtual string  GetAlibiName() {
		 return "F";
	};

	string GetName();
	bool WantsToMove();

protected:
	string name="???";
	int roomNr;
	int movChancePercent=0;
	
	

};

