#include "Hase.h"



void Hase::ErreicheZiel()
{
    m_ImZiel = true;
    m_InSpiel = false;
}

void Hase::SetzeFeldNr(int feldNr)
{
    m_feldNr = feldNr;
}

bool Hase::InSpiel()
{
    return m_InSpiel;
}

bool Hase::ImZiel()
{
    return m_ImZiel;
}

int Hase::GetFeldNr()
{
    return m_feldNr;
}

Hase:: Hase(std::string name, std::string farbe)
{
    m_name = name;
    m_farbe = farbe;
}

Hase::Hase()
{
}

void Hase::EntferneHaseAusSpiel()
{
    m_InSpiel = false;
   
}

std::string Hase::GetFarbe()
{
    return m_farbe;
}
std::string Hase::GetName()
{
    return m_name;
}

