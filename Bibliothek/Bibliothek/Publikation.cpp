#include "Publikation.h"


const int& Publikation::GetErscheinungsDatum() const
{
	return erscheinungsDatum;
}

bool Publikation::IstVerfuegbar() const
{
	return verfuegbar;
}

void Publikation::AendereVerfuegbarkeit(bool pVerfuegbar)
{
	verfuegbar = pVerfuegbar;
}


//Kunde* Publikation::GetBesitzer() const
//{
//	return  besitzer;
//}
//
//void Publikation::SetBesitzer(Kunde& kunde)
//{
//		besitzer = &kunde;
//}
//
//void Publikation::ResetBesitzer()
//{
//	besitzer = nullptr;
//}

Publikation::Publikation(std::string name, int erscheinungsJahr)
{
	this->name = name;
	this->erscheinungsDatum = erscheinungsJahr;
}

