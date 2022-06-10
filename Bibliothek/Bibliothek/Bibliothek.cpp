
#include <iostream>
#include <map>
#include "Kunde.h"
#include "Publikation.h"
#include "Bestand.h"

std::map<int, Kunde> kunden;
constexpr int ausweisStartNummer = 1000;
int aktiveKundenNummer = -1;
Bestand bestand;


void AddeNeuenKunden(std::string name)
{
    int neueAusweisNr = ausweisStartNummer + kunden.size();
    kunden.insert_or_assign(neueAusweisNr,Kunde(neueAusweisNr, name));
}

bool StelleLeihantrag(Kunde& kunde, Publikation* werk) {
    //if (werk->GetBesitzer() != nullptr) return false;

    if (kunde.LeiheElement(werk)) werk->AendereVerfuegbarkeit(false); //Wenn Kunde Platz hat -> beide Verweise setzen
    else return false;
    return true;
}

void GibWerkZurück(Kunde& kunde, Publikation* werk) {
    kunde.GibElementZurueck(werk);
    werk->AendereVerfuegbarkeit(true);
    //kunde.
}

int MainUserInput()
{
	int input = 0;
    std::cout << "Was moechten Sie tun?" << std::endl;
    std::cout << "1. Neuen Kunden registieren" << std::endl;
    std::cout << "2. Einloggen" << std::endl;
    std::cout << "3. Nach Publikation suchen" << std::endl;
    std::cout << "4. Buch entleihen" << std::endl;
    std::cout << "5. Buch zurueckgeben" << std::endl;
    std::cout << "->" << std::endl;

    std::cin >> input;

    if (input > 5)  return MainUserInput();
    else return input;

    

}

Publikation* SucheWerk()
{
    std::cout << "Wie lautet der Titel des Werks, dass Sie suchen?" << std::endl;
    std::string buchNameInput;
    getchar();
    std::getline(std::cin, buchNameInput);

    Publikation* gefundenesWerk = bestand.SucheWerk(buchNameInput);

    if (gefundenesWerk != nullptr) {
        std::cout << "Das gesuchte Werk ist im Bestand vorhanden." << std::endl;
        if (gefundenesWerk->IstVerfuegbar())
        {
            std::cout << "-> Das Werk ist verfuegbar." << std::endl;
            return gefundenesWerk;
        }
            std::cout << "-> Das Werk ist zurzeit entliehen." << std::endl;

    }
    else {
        std::cout << "Das gesuchte Werk ist nicht Teil des Bestands." << std::endl;
    }
    return nullptr;
}
void Leihvorgang()
{
    Publikation* auszuleihendesWerk = SucheWerk();

    if (auszuleihendesWerk != nullptr)
    {
        std::cout << "Dieses Werk jetzt ausleihen? 1= Ja, 0 = Nein" << std::endl;
        int input = 0;
        std::cin >> input;
        switch (input)
        {
        case 1:
            if (StelleLeihantrag(kunden.find(aktiveKundenNummer)->second, auszuleihendesWerk))
            {
                std::cout << "Erfolg!" << std::endl;
            }
            else {
                std::cout << "Leihvorgang fehlgeschlagen. Sie haben bereits die maximale Anzahl an Publikationen ausgeliehen." << std::endl;
                std::cout << "-> Geben Sie ein Werk zurueck, wenn Sie ein anderes ausleihen moechten." << std::endl;
            }

            break;

        default:
            std::cout << "Leihvorgang abgebrochen." << std::endl;
            break;
        }
    }
}

void Rueckgabevorgang()
{
	
}
void MainLoop()
{
    bool aktiv = true;

    while (aktiv) {
        int state = MainUserInput();

        switch (state)
        {
        case 1:
        {
            std::cout << "Einen neuen Nutzer registrieren..." << std::endl << " Bitte Name eingeben." << std::endl;
            std::string nameInput;

            getchar();
            std::getline(std::cin, nameInput);

            AddeNeuenKunden(nameInput);
            std::cout << "Neuer Kunde wurde registriert: " << nameInput << std::endl;
            std::cout << "Vergebene Kundennummer: " << kunden.size() - 1 << std::endl;


            break;
        }
        case 2:
        {
            std::cout << "Einloggen..." << std::endl << " Bitte ID eingeben." << std::endl;
            int input2;
            std::cin >> input2;

            if (input2 > kunden.size())
            {
                std::cout << "Diese ID ist nicht vergeben." << std::endl;
                MainUserInput();
            }
            else
            {
                aktiveKundenNummer = input2 + ausweisStartNummer;
                std::cout << "Eingeloggt als: " << kunden.find(aktiveKundenNummer)->second.GetName() << std::endl;

            }
            break;
        }
        case 3:
        {
            SucheWerk();
            break;
        }
        case 4:
        {
            if (aktiveKundenNummer == -1)
            {
                std::cout << "Um ein Buch zu entleihen, muss ein User eingeloggt sein." << std::endl;
                break;
            }

            Leihvorgang();

        }
            break;
        case 5:
            if (aktiveKundenNummer == -1)
            {
                std::cout << "Um ein Buch zurueckzugeben, muss ein User eingeloggt sein." << std::endl;
            }

            Rueckgabevorgang();

            break;

        default:
            break;
        }
        std::cout << std::endl;
    }
}
int main()
{
    MainLoop();
  
   

    
    
}

