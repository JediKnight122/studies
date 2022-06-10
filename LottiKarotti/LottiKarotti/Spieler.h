#pragma once
#include "Hase.h"
class Spieler
{
	Hase hasen[5];
	std::string m_farbe;

public:
	Spieler(std::string farbe);
	Hase* waehleFigur();
};

