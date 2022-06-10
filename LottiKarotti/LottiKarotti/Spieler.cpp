#include "Spieler.h"

Hase* Spieler::waehleFigur()
{
	for (int i = 0; i < 5; i++)
	{
		if(hasen[i].InSpiel())
		{
			return &hasen[i];
		}
	}

	return nullptr;

}

Spieler::Spieler(std::string farbe)
{
	m_farbe = farbe;

	hasen[0] = Hase("Bernd", farbe);
	hasen[1] = Hase("Hermine", farbe);
	hasen[2] = Hase("Rolf", farbe);
	hasen[3] = Hase("Briegel", farbe);
	hasen[4] = Hase("Martusa", farbe);
}

