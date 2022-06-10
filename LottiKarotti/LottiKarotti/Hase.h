#pragma once
#include <string>


class Hase
{
	int m_feldNr=0;
	bool m_InSpiel = true;
	bool m_ImZiel = false;
	std::string m_name;
	std::string m_farbe;

public:
	Hase(std::string name, std::string farbe);
	Hase();
	void EntferneHaseAusSpiel();
	void ErreicheZiel();
	void SetzeFeldNr(int feldNr);


	  bool InSpiel();
	  bool ImZiel();
	  int GetFeldNr();
	  std::string GetName();
	std::string GetFarbe();
};

