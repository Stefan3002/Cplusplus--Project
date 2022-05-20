//
// Created by Stefan on 20.05.2022.
//

#include "OperatiiBaza.h"
//
// Created by Stefan on 02.03.2022.
//

#include "Login.h"
#include <string>
#include <vector>
#include <iostream>
#include "preluareDate.h"
#include "OperatiiSpeciale.h"
using namespace std;

int nr = -1;
string CurrentUser;

void adaugaContact(char Nume[], char Prenume[], char NrTelefon[], char Email[], char Eticheta[], int *nr, struct contact Agenda[]){
    FILE *fname = fopen("contacts.txt", "a");
    fprintf(fname,"%s,%s,%s,%s,%s,%s\n",CurrentUser,Nume,Prenume,NrTelefon,Email,Eticheta);
    *nr = *(nr) + 1;
    strcpy(Agenda[*nr].Nume, Nume);
    strcpy(Agenda[*nr].Prenume, Prenume);
    strcpy(Agenda[*nr].NrTelefon, NrTelefon);
    strcpy(Agenda[*nr].Email, Email);
    strcpy(Agenda[*nr].Eticheta, Eticheta);
    fclose(fname);
}

void PrintToatePersoane(struct contact Agenda[]){
    for(int i = 0; i <= nr; i++){
        if(Agenda[i].Nume[strlen(Agenda[i].Nume) - 1] == '*') {
            Agenda[i].Nume[strlen(Agenda[i].Nume) - 1] = '\0';
            printf("<-------******------->\n");
        }
        else
            printf("<-------  ------->\n");
        printf("%s\n", Agenda[i].Nume);
        printf("%s\n", Agenda[i].Prenume);
        printf("%s\n", Agenda[i].NrTelefon);
        if(Agenda[i].Email[0] != '-')
            printf("%s\n", Agenda[i].Email);
        if(Agenda[i].Eticheta[0] != '-')
            printf("%s\n", Agenda[i].Eticheta);
    }

}

void PrintEtichetaPersoane(char Tag[],struct contact Agenda[]){
    short int printed = 0;
    short matches_found = 0;
    for(int i = 0; i < strlen(Tag); i++)
        if(Tag[i] >= 'A' && Tag[i] <= 'Z')
            Tag[i] += 32;
    for(int i = 0; i <= nr; i++) {
        if (strcmp(Agenda[i].Eticheta, Tag) == 0) {
            matches_found++;
            printed = 1;
            if (Agenda[i].Nume[strlen(Agenda[i].Nume) - 1] == '*') {
                Agenda[i].Nume[strlen(Agenda[i].Nume) - 1] = '\0';
                printf("<-------******------->\n");
            } else
                printf("<-------  ------->\n");
            printf("%s\n", Agenda[i].Nume);
            printf("%s\n", Agenda[i].Prenume);
            printf("%s\n", Agenda[i].NrTelefon);
            if(Agenda[i].Email[0] != '-')
                printf("%s\n", Agenda[i].Email);
            if(Agenda[i].Eticheta[0] != '-')
                printf("%s\n", Agenda[i].Eticheta);
        }
    }
    if(!printed){
        printf("!!!!!!!!!!!!!!!!!!!\n");
        printf("0 inregistrari gasite.\n");
        printf("!!!!!!!!!!!!!!!!!!!\n");
    }
    else
        printf("<==>%d inregistrari gasite <==>",matches_found);

}

int divide(int i, int j, struct contact Agenda[]){
    int ii = 0;
    int jj = -1;
    while(i < j){
        if(strcmp(Agenda[i].Nume, Agenda[j].Nume) == 1){
            struct contact aux;
            aux = Agenda[i];
            Agenda[i] = Agenda[j];
            Agenda[j] = aux;
            ii = ii ^ (-jj);
            jj = jj ^ (-ii);
            ii = ii ^ (-jj);
        }
        i += ii;
        j += jj;
    }
    return j;
}

void quicki(int st, int dr, struct  contact Agenda[]){
    if(st < dr){
        int pivot = divide(st,dr,Agenda);
        quicki(st,pivot,Agenda);
        quicki(pivot + 1, dr,Agenda);
    }
}


void PrintAlfabetic(struct contact Agenda[]){
    quicki(0,nr,Agenda);
    for(int i = 0; i <= nr; i++){
        printf("<-------  ------->\n");
        printf("%s\n", Agenda[i].Nume);
        printf("%s\n", Agenda[i].Prenume);
        printf("%s\n", Agenda[i].NrTelefon);
        if(Agenda[i].Email[0] != '-')
            printf("%s\n", Agenda[i].Email);
        if(Agenda[i].Eticheta[0] != '-')
            printf("%s\n", Agenda[i].Eticheta);
    }


}


void PrintPersoane(struct contact Agenda[]){
    printf("<--------Afisare persoane---------->\n\n");
    int alegere = -1;
    char alegerec;
    char Tag[NMAX];
    do{
        printf("1. Toate contactele.\n");
        printf("2. Dupa eticheta.\n");
        printf("3. Alfabetic.\n");
        printf("0. Pentru a reveni la meniul anterior introduceti cifra 0.\n");
        do {
            printf("----------->Optiune: \n");
            fflush(stdin);
            scanf("%c", &alegerec);
            if(isdigit(alegerec))
                alegere = alegerec - '0';
            else
                printf("Introduceti un numar corespunzator.\n");
        }while(alegere == -1);

        switch(alegere){
            case 1:
                PrintToatePersoane(Agenda);
                return;
            case 2:
                printf("\nEticheta: ");
                scanf("%s",Tag);
                PrintEtichetaPersoane(Tag, Agenda);
                return;
            case 3:
                PrintAlfabetic(Agenda);
                return;
            case 0:
                return;
            default:
                printf("Alegere invalida!\n\n");
                PrintPersoane(Agenda);
        }
    }while(alegere != 0);
}

short int go = 0;
short int nr_incercari = 2;

//TRANSLATED STEFAN
int ScrieOptiuni(int cuIntampinare,vector <contact> Agenda){
    nr_incercari--;
    if(!go)
        if(startLogin(CurrentUser))
            go = 1;

    if(go) {
        if(cuIntampinare) {
            cout<<"<=====Bine ati venit!=====>\n";
            cout<<"<----Agenda telefonica!---->\n";
            preluareDate(CurrentUser,Agenda,&nr);
        }

        cout<<"\n\n";
        cout<<"1. Adaugati o persoana\n";
        cout<<"2. Stergeti o persoana\n";
        cout<<"3. Vizualizati lista de persoane\n";
        ///Validari.
        ///Etichete.
        ///Filtrare si sortare.
        ///Campuri obligatorii.
        cout<<"0. Pentru a parasii aplicatia introduceti cifra 0\n";
        return 1;
    }
    else
    if(nr_incercari){
        cout<<"\nIncercare 2/2.\n";
        ScrieOptiuni(cuIntampinare, Agenda);
    }
}

void AdaugaPersoana(struct contact Agenda[]){
    char Nume[20],Prenume[20],Mail[30],NrTelefon[30];
    char Eticheta[NMAX];
    int OK = 1;
    char aux = '-';

    do {
        OK = 1;
        printf("Nume* (Doar litere): \n");
        scanf("%s", Nume);
        for(int i = 0; i < strlen(Nume); i++)
            if(!((Nume[i] >= 'A' && Nume[i] <= 'Z') || (Nume[i] >= 'a' && Nume[i] <= 'z'))) {
                OK = 0;
                printf("Numele trebuie sa contina doar litere.\n");
                break;
            }

        if(Nume[0] == aux) {
            OK = 0;
            printf("Numele este obligatoriu.\n");
        }
    }while(!OK);
    do {
        OK = 1;
        printf("Prenume* (Doar liere): \n");
        scanf("%s", Prenume);
        for(int i = 0; i < strlen(Prenume); i++)
            if(!((Prenume[i] >= 'A' && Prenume[i] <= 'Z') || (Prenume[i] >= 'a' && Prenume[i] <= 'z'))) {
                OK = 0;
                printf("Prenumele trebuie sa contina doar litere.\n");
                break;
            }

        if(Prenume[0] == aux) {
            OK = 0;
            printf("Prenumele este obligatoriu.\n");
        }
    }while(!OK);
    do {
        OK = 1;
        printf("Numar telefon* (Doar cifre): \n");
        scanf("%s", NrTelefon);
        if(strlen(NrTelefon) != 10) {
            OK = 0;
            printf("Numarul trebuie sa contina 10 cifre.\n");
        }
        for(int i = 0; i < strlen(NrTelefon); i++)
            if(!(NrTelefon[i] >= '0' && NrTelefon[i] <= '9')){
                OK = 0;
                printf("Numarul trebuie sa contina doar cifre.\n");
                break;
            }

        if(NrTelefon[0] == aux) {
            OK = 0;
            printf("Numarul de telefon este obligatoriu.\n");
        }
    }while(!OK);
    do {
        OK = 1;
        printf("E-mail: \n");
        scanf("%s", Mail);
        int nrarond = 0;
        int nrpunct = 0;
        for(int i = 0; i < strlen(Mail); i++)
            if(Mail[0] == aux){
                OK = 1;
                break;
            }
            else
            if(Mail[i] == '@')
                nrarond++;
            else
            if(Mail[i] == '.')
                nrpunct++;
        if(Mail[0] != aux && !(nrarond == 1 && nrpunct >= 1)) {
            OK = 0;
            printf("Adresa de email trebuie sa contina simbolul @ si un punct.\n");
        }
    }while(!OK);
    do {
        OK = 1;
        printf("Eticheta: \n");
        scanf("%s", Eticheta);
        for(int i = 0; i < strlen(Eticheta); i++)
            if(Eticheta[0] == aux)
                OK = 1;
            else
            if(!((Eticheta[i] >= 'A' && Eticheta[i] <= 'Z') || (Eticheta[i] >= 'a' && Eticheta[i] <= 'z'))) {
                OK = 0;
                printf("Eticheta trebuie sa contina doar litere.\n");
                break;
            }
    }while(!OK);
    for(int i = 0; i < strlen(Eticheta); i++)
        if(Eticheta[i] >= 'A' && Eticheta[i] <= 'Z')
            Eticheta[i] += 32;

    printf("\nPersoana a fost adaugata cu succes!\n");
    adaugaContact(Nume,Prenume,NrTelefon,Mail,Eticheta,&nr,Agenda);
}

void StergePersoana(struct contact Agenda[]){

    int Alegere = -1;
    char Alegerec;
    do {

        printf("1. Dupa nume\n");
        printf("2. Dupa nr. telefon\n");
        printf("0. Pentru a parasii acest meniu introduceti cifra 0\n");
        do {
            fflush(stdin);
            printf("----------->Optiune: \n");
            scanf("%c", &Alegerec);
            if(isdigit(Alegerec))
                Alegere = Alegerec - '0';
        }while(Alegere == -1);
        char Victima_Nume[20],Victima_Telefon[30];
        int OK;
        switch (Alegere) {
            case 1:
                printf("\nNume cautat: \n");
                scanf("%s",Victima_Nume);
                stergeContact(CurrentUser,Agenda, &nr ,Victima_Nume);
//          StergeNume();
                return;
            case 2:
                do {
                    OK = 1;
                    printf("\nNumar de telefon cautat: \n");
                    scanf("%s", Victima_Telefon);
                    for(int i = 0; i < strlen(Victima_Telefon); i++)
                        if(!(Victima_Telefon[i] >= '0' && Victima_Telefon[i] <= '9')){
                            OK = 0;
                            printf("Numarul trebuie sa contina doar cifre.\n");
                            break;
                        }
                    if(strlen(Victima_Telefon) != 10) {
                        printf("Numarul de telefon trebuie sa contina 10 cifre.\n");
                        OK = 0;
                    }
                }while(!OK);
                stergeContactTelefon(CurrentUser,Agenda, &nr ,Victima_Telefon);
                return;
            case 0:
                printf("\n\n");
                return;
            default:
                printf("Alegere invalida\n");
                StergePersoana(Agenda);

        }
    }while(Alegere == 1 || Alegere == 2);
}


//TRANSLATED STEFAN
void AfiseazaMeniu(vector <contact> Agenda){

    int alegere = -1;
    char alegerec;
    int cuIntampinare = 1;
    do {
        if(ScrieOptiuni(cuIntampinare,Agenda) == 0)
            return;
        do {
            fflush(stdin);
            cout<<"----------->Optiune: \n";
            cin>>alegerec;
            if (isdigit(alegerec))
                alegere = alegerec - '0';
            else
                cout<<"Introduceti un numar corespunzator.\n";
        }while(alegere == -1);
        switch(alegere){
            case 1:
                cuIntampinare = 0;
                cout<<"\n\n<----Adaugare de persoane.---->\n\n";
                AdaugaPersoana(Agenda);
                break;
            case 2:
                cuIntampinare = 0;
                cout<<"\n\n<----Stergere de persoane.---->\n\n";
                StergePersoana(Agenda);
                break;
            case 3:
                cuIntampinare = 0;
                PrintPersoane(Agenda);
                break;
            case 0:
                cout<<"Va multumim ca ati folosit serviciile noastre.";
                exit(0);
            default:
                cout<<"<----Alegere invalida---->\n";
                cuIntampinare = 0;
                continue;
        }

    }while(alegere != 0);

}


