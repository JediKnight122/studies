// Aufgabe8 Mini Funktionen.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <stdio.h>
#include <stdbool.h>

char MacheBuchstabeGrossFunktion(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    return c;
}

void MacheBuchstabeGrossProzedur(char* c) {
    if (*c >= 'a' && *c <= 'z') {
        *c -= 32;
    }
}

void MacheZeichenketteGrossProzedur(char* c) {
    char* cPointer;
    int charLenght;
    for (charLenght = 0; c[charLenght] != '\0'; charLenght++);

    for (int i = 0; i < charLenght; i++) {
        cPointer = &c[i];
        MacheBuchstabeGrossProzedur(cPointer);
    }
}

bool IstPrimzahl(int zahl) {
    for (int i = 2; i < zahl; i++) {
        if (zahl % i == 0) {
            printf("Teiler: %i\n", i);
            return false;
            
        }
    }
    return true;
}

char* DreheZeichenKetteUm(char* ac) {
    int i = 0;
    for (i; ac[i] != '\0'; i++); //Länge des Char Arrays bestimmen
    char acInverted[100];
    for (int k = 0; k <= i; k++) {
        acInverted[k] = ac[i - k];
        printf("%c\n", acInverted[k]);
    }
    //  return acInverted;
    return 0;
}

bool PruefeAufPalyndrom(char* str) {

    MacheZeichenketteGrossProzedur(str);

    int i = 0;
    for (i; str[i] != '\0'; i++); //Länge des Char Arrays bestimmen
    i--;
    for (int k = 0; k <= i; k++, i--) {
        if (str[k] != str[i]) return false;
    }
    return true;

}

int main() {
    if (IstPrimzahl(387))printf("Die Zahl ist eine Primzahl!");
    else printf("Die Zahl ist keine Primzahl.");
    
    return 0;
}