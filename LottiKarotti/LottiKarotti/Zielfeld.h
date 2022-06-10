#pragma once
#include "Feld.h"
class Zielfeld :
    public Feld
{
public:
    Zielfeld(int feldNr);
    void SetzeFigurAufFeld(Hase *figur) override;
    std::string GetFeldTyp() override;
};

