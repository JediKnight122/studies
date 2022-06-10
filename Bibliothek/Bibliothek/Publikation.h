#pragma once
#include <string>


class Publikation
{
protected:
	std::string name;
	int erscheinungsDatum;
	bool verfuegbar = true;

	//Kunde* besitzer;

public:
	Publikation(std::string name, int erscheinungsJahr);
	virtual const std::string& GetName() const = 0;

	const int& GetErscheinungsDatum() const;
	bool IstVerfuegbar() const;
	void AendereVerfuegbarkeit(bool pVerfuegbar);

	const struct ErscheinungsjahrCompare
	{
		bool operator()(const Publikation& p1, const Publikation& p2)
		{
			return p1.erscheinungsDatum < p2.erscheinungsDatum;
		}
		bool operator()(const Publikation* p1, const Publikation* p2) const
		{
			return p1->GetErscheinungsDatum() < p2->GetErscheinungsDatum();
		}
	};
};

