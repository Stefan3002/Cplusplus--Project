#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OperatiiBaza.h"
#define NMAX 70
struct contact{
    char Nume[NMAX];
    char Prenume[NMAX];
    char NrTelefon[NMAX];
    char Email[NMAX];
    char Eticheta[NMAX];
};

int main() {
    char PATH[NMAX * 2] = "contacts.txt";
    int nrtotal = 0;
        FILE *fname = NULL;
        fname = fopen(PATH,"r");

        while(fname == NULL) {
//            printf("Nu s-a gasit fisierul.\n");
            printf("Introduceti adresa fisierului.\n");
            scanf("%s", PATH);
            if (PATH[strlen(PATH) - 1] == '\n')
                PATH[strlen(PATH) - 1] = '\0';
            fname = fopen(PATH, "r");
        }

        char line[NMAX];
        while(fgets(line,NMAX,fname))
            nrtotal++;
        fclose(fname);
//    printf("======%d=====", *nr);

//    printf("%d",nrtotal);

    struct contact Agenda[nrtotal];
    AfiseazaMeniu(Agenda);
    return 0;
}
