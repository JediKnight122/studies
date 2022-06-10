#include "Lochfeld.h"



Lochfeld::Lochfeld(int feldNr, int drehungBisOffen): Feld((feldNr))
{
	m_feldTyp = "ein Lochfeld";
	m_drehungenBisOffenMax = drehungBisOffen;
}

std::string Lochfeld::GetFeldTyp()
{
	return m_feldTyp;
}

void Lochfeld::NaechsteDrehStufe()
{
	if(offen)
	{
		offen = false;
		m_drehungenBisOffen = m_drehungenBisOffenMax;
	}
	else {
		m_drehungenBisOffen--;

		if (m_drehungenBisOffen <= 0)
		{
			std::cout << "***Achtung! Feld Nummer " << m_feldNr << " ist jetzt offen!***\n";
			offen = true;
			if (m_figurAufFeld != nullptr)
			{
				FrissFigurAufFeld();
			}
			
		}
	}
}

void Lochfeld::FrissFigurAufFeld()
{
	
	std::cout << "Oh nein! Der " <<m_figurAufFeld->GetFarbe() << " Hase " << m_figurAufFeld->GetName() << " ist verloren! Tiefe Trauer erfuellt uns.\n";

	m_figurAufFeld->EntferneHaseAusSpiel();
	m_figurAufFeld = nullptr;
}

void Lochfeld::SetzeFigurAufFeld(Hase *figur)
{
	m_figurAufFeld = figur;
	if (offen) FrissFigurAufFeld();
}

