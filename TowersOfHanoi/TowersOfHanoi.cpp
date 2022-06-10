// TowersOfHanoi.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#define AnzahlRinge 3
#define getName(var)  #var

void BewegeStein(int StartStapel[], int AnzahlElementeStartStapel, int Zielstapel[], int AnzahlElementeZielStapel);
bool PruefeSiegKondition(int Zielstapel[]);
void SchiebeStein(int iAnzSteine, char a, char b, char c);

int BestimmteAnzahlElementeVonFeld(int array[]) {
	int k = 0;
	while (array[k] != 0) k++;
	return k;
}

int main()
{
	//int aA[AnzahlRinge] = {};
	//int aB[AnzahlRinge] = {};
	//int aC[AnzahlRinge] = {};
	//int* arrayPointer;

	//int iAnzahlElementeaA = 0;
	//int iAnzahlElementeaB = 0;
	//int iAnzahlElementeaC = 0;

	//for (int i = AnzahlRinge;  i > 0; i--) {
	//	aA[iAnzahlElementeaA] = i;
	//	
	//	iAnzahlElementeaA++;
	//	
	//
	//}
	
	//SchiebeStein(AnzahlRinge, aA, aB, aC);


	//iAnzahlElementeaA = BestimmteAnzahlElementeVonFeld(aA);
	//iAnzahlElementeaB = BestimmteAnzahlElementeVonFeld(aB);
	//iAnzahlElementeaC = BestimmteAnzahlElementeVonFeld(aC);

	//printf("Auf A liegen:\n");
	//for (int i = 0; i < iAnzahlElementeaA; i++) {
	//	printf("%i\n", aA[i]);
	//}
	//printf("\nAuf B liegen:\n");
	//for (int i = 0; i < iAnzahlElementeaB; i++) {
	//	printf("%i\n", aB[i]);
	//}
	//for (int i = 0; i < iAnzahlElementeaC; i++) {
	//	printf("%i\n", aC[i]);
	//}

	SchiebeStein(AnzahlRinge, 'a', 'b', 'c');
	printf("Herzlichen Glueckwunsch. \nSie haben die Tuerme von Hanoi nun in dem Sie jeden Schritt vorgesagt bekommen haben, loesen koennen. \nGute Arbeit!");
}



void SchiebeStein(int iAnzSteine, char a, char b, char c) {
	if (iAnzSteine == 1) {
		printf("Bewege den obersten Ring von %c auf %c!\n", a, c);
		getchar();

	}
	else {

		SchiebeStein(iAnzSteine-1, a, c, b);
		SchiebeStein(1, a, b, c);
		SchiebeStein(iAnzSteine-1, b, a, c);
	}
}




bool PruefeSiegKondition(int Zielstapel[]) {
	for (int i = 0; i < AnzahlRinge; i++) {
		if (Zielstapel[i] == 0) return false;
	}
	return true;
}

