#pragma once
#include "Feld.h"
class Standardfeld :
    public Feld
{
public: Standardfeld(int feldNr);
      std::string GetFeldTyp() override;
};

