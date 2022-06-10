#pragma once
#include "Feld.h"
class Lochfeld :
    public Feld
{
private: int m_drehungenBisOffen = 3;
       int m_drehungenBisOffenMax = 3;
       bool offen = false;
public:
    Lochfeld(int feldNr, int drehungBisOffen);
    std::string GetFeldTyp() override;
    void NaechsteDrehStufe();
    void FrissFigurAufFeld();
    void SetzeFigurAufFeld(Hase *figur) override;
};

