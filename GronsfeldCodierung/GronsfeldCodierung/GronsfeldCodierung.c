// GronsfeldCodierung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#pragma warning(disable:4996)
#include <stdio.h>


int SuchePositionVonBImAlph(char c) {
    
    c -= 65;
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

void SpeichereCodierteBotschaftInDatei(char* acBot) {
    FILE* pTargetfile;
    pTargetfile = fopen("Botschaft_Codiert.txt", "w");
    if (pTargetfile) {
        fprintf(pTargetfile, acBot);
        fclose(pTargetfile);
        printf("\n******\nDie codierte Datei wurde gespeichert.\n");
    }
}

void SpeichereDecodierteBotschaftInDatei(char* acBot) {
    FILE* pTargetfile;
    pTargetfile = fopen("Botschaft.txt", "w");
    if (pTargetfile) {
        fprintf(pTargetfile, acBot);
        fclose(pTargetfile);
        printf("\n******\nDie decodierte Datei wurde gespeichert.\n");
    }
}

void CodiereZeichenkette(char* ac, char* codewort) {
    MacheZeichenketteGrossProzedur(ac);
    MacheZeichenketteGrossProzedur(codewort);
    int i=0, k = 0;

    while (ac[i] != 0)
    {
        if (ac[i] >= 'A' && ac[i] <= 'Z') {
            ac[i] += SuchePositionVonBImAlph(codewort[k]);
            if (ac[i] >= 91) ac[i] -= 26;
        }
        i++;
        k++;
        if (codewort[k] == 0) k = 0;
    }

    SpeichereCodierteBotschaftInDatei(ac);
    
}

void DecodiereZeichenkette(char* ac, char* codewort) {
    MacheZeichenketteGrossProzedur(ac);
    MacheZeichenketteGrossProzedur(codewort);
    int i = 0, k = 0;

    while (ac[i] != 0)
    {
        if (ac[i] >= 'A' && ac[i] <= 'Z') {
            
                ac[i] -= SuchePositionVonBImAlph(codewort[k]);
                if (ac[i] <= 64) ac[i] += 26;
            }

            i++;
            k++;
            if (codewort[k] == 0) k = 0;
        } 
    
    SpeichereDecodierteBotschaftInDatei(ac);
}


int main()
{
    int iEingabe = 0;
    printf("******************\Willkommen zum Gronsfeldcodierer!\nSoll codiert(0) oder decodiert(1) werden?\n");
    scanf("%i", &iEingabe);
    
    FILE* pfile;
    char acBotschaft[500];
    char codeWort[] = { "ABCDEFHG" };

    if (iEingabe == 0) {

        pfile = fopen("Botschaft.txt", "r+");

        if (pfile) {
            fgets(acBotschaft, 500, pfile);
            printf("Eingelesene Botschaft:\n %s\n", acBotschaft);
            fclose(pfile);
            CodiereZeichenkette(acBotschaft, codeWort);
            printf("Codierte Botschaft: \n%s\n", acBotschaft);
        }
        else perror("fopen");
        

    }
    else {

        pfile = fopen("Botschaft_Codiert.txt", "r+");

        if (pfile) {
            fgets(acBotschaft, 500, pfile);
            printf("Eingelesene Botschaft:\n %s\n", acBotschaft);
            fclose(pfile);
            DecodiereZeichenkette(acBotschaft, codeWort);
            printf("Decodierte Botschaft: \n%s\n", acBotschaft);
        }
        else perror("fopen");



    }
    return 0;

}

