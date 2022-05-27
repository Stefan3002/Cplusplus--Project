//
// Created by Stefan on 25.05.2022.
//

#include "preluareDate.h"
//
// Created by Stefan on 17.03.2022.
//
#include <iostream>


#include "contact.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;
#define NMAX 70

//struct contact{
//    char Nume[NMAX];
//    char Prenume[NMAX];
//    char NrTelefon[NMAX];
//    char Email[NMAX];
//    char Eticheta[NMAX];
//};
//struct contact2{
//    char currentUser[NMAX];
//    char Nume[NMAX];
//    char Prenume[NMAX];
//    char NrTelefon[NMAX];
//    char Email[NMAX];
//    char Eticheta[NMAX];
//};

//TRANSLATE STEFAN Verified It WORKS!
void preluareDate(string CurrentUser,vector <contact> &Agenda, int &nr){
    string PATH = "contacts.txt";
    int nrtotal = 0;
    ifstream intrare(PATH);
    string line,User;

    vector <string> tokens;
    int start = 0;
    while(getline(intrare,line)) {
        start = 0;
        nrtotal++;
        nr++;
        for (int i = 0; i < line.length(); i++)
            if (line[i] == ';') {
                tokens.push_back(line.substr(start, i - start));
                start = i + 1;
            }
        tokens.push_back(line.substr(start, line.length() - start));

        string Nume, Prenume, NrTelefon, Email, Eticheta;


        User = tokens[0];
        Nume = tokens[1];
        Prenume = tokens[2];
        NrTelefon = tokens[3];
        Email = tokens[4];
        Eticheta = tokens[5];
        if(User == CurrentUser){
            contact c(Nume,Prenume,NrTelefon,Email,Eticheta,User);
            Agenda.push_back(c);
        }
        else
            nr--;

        tokens.clear();
    }
}

//TRANSLATE STEFAN
void preluareDateOtherUsers(string CurrentUser,vector <contact> Agenda, int &nr){
    int nrtotal = 0;
    string PATH = "contacts.txt";

//    FILE *fname = NULL;
//    fname = fopen(PATH,"r");
//
//    while(fname == NULL) {
////            printf("Nu s-a gasit fisierul.\n");
//        printf("Introduceti adresa fisierului.\n");
//        scanf("%s", PATH);
//        if (PATH[strlen(PATH) - 1] == '\n')
//            PATH[strlen(PATH) - 1] = '\0';
//        fname = fopen(PATH, "r");
//    }
    ifstream intrare(PATH);

//    char line[NMAX];
//    char User[NMAX];
    string line,User;

    vector <string> tokens;
    int start = 0;
    while(getline(cin,line)) {
        nrtotal++;
        nr++;
        for (int i = 0; i < line.length(); i++)
            if (line[i] == ';') {
                tokens.push_back(line.substr(start, i - start));
                start = i + 1;
            }
        tokens.push_back(line.substr(start, line.length() - start));

        string Nume, Prenume, NrTelefon, Email, Eticheta, CurrentUserContact;

        CurrentUserContact = tokens[0];
        Nume = tokens[1];
        Prenume = tokens[2];
        NrTelefon = tokens[3];
        Email = tokens[4];
        Eticheta = tokens[5];

        if(CurrentUserContact != CurrentUser){
            contact c(Nume,Prenume,NrTelefon,Email,Eticheta,CurrentUserContact);
            Agenda.push_back(c);
        }
        else
            nr--;

        tokens.clear();
    }

//    while(fgets(line,NMAX,fname)){
//        if (line[strlen(line) - 1] == '\n')
//            line[strlen(line) - 1] = '\0';
//        *nr = *(nr) + 1;
//        l = 0;
//        p = strtok(line,sp);
//        while(p){
//            switch (l) {
//                case 0:
//                    strcpy(Agenda[*nr].currentUser,p);
//                    break;
//                case 1:
//                    strcpy(Agenda[*nr].Nume,p);
//                    break;
//                case 2:
//                    strcpy(Agenda[*nr].Prenume,p);
//                    break;
//                case 3:
//                    strcpy(Agenda[*nr].NrTelefon,p);
//                    break;
//                case 4:
//                    strcpy(Agenda[*nr].Email,p);
//                    break;
//                case 5:
//                    strcpy(Agenda[*nr].Eticheta,p);
//                    break;
//
//            }
//            l++;
//            p = strtok(NULL, sp);
//        }
//
//        if(strcmp(Agenda[*nr].currentUser,CurrentUser) == 0)
//            *nr = *(nr) - 1;
//    }
//    fclose(fname);
}

void preluareDateOtherUsersTel(string CurrentUser,vector <contact> &Agenda, int &nr){
    string PATH = "contacts.txt";

    ifstream intrare(PATH);

    string line,User;

    vector <string> tokens;

    while(getline(intrare,line)) {
        int start = 0;

        nr++;
        for (int i = 0; i < line.length(); i++)
            if (line[i] == ';') {
                tokens.push_back(line.substr(start, i - start));
                start = i + 1;
            }
        tokens.push_back(line.substr(start, line.length() - start));

        string Nume, Prenume, NrTelefon, Email, Eticheta, CurrentUserContact;

        CurrentUserContact = tokens[0];
        Nume = tokens[1];
        Prenume = tokens[2];
        NrTelefon = tokens[3];
        Email = tokens[4];
        Eticheta = tokens[5];

        if(NrTelefon!= CurrentUser){
            contact c(Nume,Prenume,NrTelefon,Email,Eticheta,CurrentUserContact);
            Agenda.push_back(c);
        }
        else
            nr--;

        tokens.clear();
    }

}

//
//void stergeContact(char CurrentUser[],struct contact Agenda[], int *nr ,char TargetName[]) {
//
//    int k = 0;
//    struct contact aux[NMAX];
//
//    FILE *fname = fopen(PATH, "r");
//    FILE *fname2 = fopen("contacts2.txt", "w");
//    char line[NMAX];
//
//    for(int i = 0; i <= *nr; i++)
//        if(strcmp(Agenda[i].Nume ,TargetName) == 0)
//            aux[k++] = Agenda[i];
//
//    if(k > 0) {
//        int choice = -1;
//        char choicec;
//        do {
//
//
//            for (int i = 0; i < k; i++) {
//                printf("<-------  ------->\n");
//                printf("--%d--\n", i);
//                printf("%s\n", aux[i].Nume);
//                printf("%s\n", aux[i].Prenume);
//                printf("%s\n", aux[i].NrTelefon);
//                printf("%s\n", aux[i].Email);
//                printf("%s\n", aux[i].Eticheta);
//            }
//            printf("Alegere: 0 -> %d\n", k - 1);
//            fflush(stdin);
//            scanf("%c", &choicec);
//            if(isdigit(choicec) && choicec >= '0' && choicec <= (k - 1) + '0')
//                choice = choicec - '0';
//        }while(choice == -1);
//        for(int i = 0; i <= *nr; i++)
//            if(!(strcmp(Agenda[i].Nume ,TargetName) == 0 && strcmp(Agenda[i].Prenume, aux[choice].Prenume) == 0 && strcmp(Agenda[i].NrTelefon, aux[choice].NrTelefon) == 0))
//                fprintf(fname2,"%s,%s,%s,%s,%s,%s\n",CurrentUser,Agenda[i].Nume,Agenda[i].Prenume,Agenda[i].NrTelefon,Agenda[i].Email,Agenda[i].Eticheta);
//
//    }
//
//    struct contact2 otherUsersContacts[NMAX];
//    int nr2 = -1;
////    printf("%s",CurrentUser);
//    preluareDateOtherUsers(CurrentUser,otherUsersContacts, &nr2);
//    for(int i = 0; i <= nr2; i++)
////        printf("%s,%s,%s,%s,%s,%s\n",otherUsersContacts[i].currentUser,otherUsersContacts[i].Nume,otherUsersContacts[i].Prenume,otherUsersContacts[i].NrTelefon,otherUsersContacts[i].Email,otherUsersContacts[i].Eticheta);
//        fprintf(fname2,"%s,%s,%s,%s,%s,%s\n",otherUsersContacts[i].currentUser,otherUsersContacts[i].Nume,otherUsersContacts[i].Prenume,otherUsersContacts[i].NrTelefon,otherUsersContacts[i].Email,otherUsersContacts[i].Eticheta);
//
////    Replace the initial file
//    if(k > 0) {
//        fclose(fname2);
//        fclose(fname);
//        fname2 = fopen("contacts2.txt", "r");
//        fname = fopen("contacts.txt", "w");
//        while (fgets(line, NMAX, fname2))
//            fprintf(fname, line);
//
//
//        fclose(fname2);
//        fclose(fname);
//
//        *nr = -1;
//        preluareDate(CurrentUser, Agenda, nr);
//    }
//    else
//        printf("<----0 contacte gasite---->\n\n");
//}
//
//void stergeContactTelefon(char CurrentUser[],struct contact Agenda[], int *nr ,char TargetTelefon[]) {
//
//    int k = 0;
//    struct contact aux[NMAX];
//
//    FILE *fname = fopen(PATH, "r");
//    FILE *fname2 = fopen("contacts2.txt", "w+");
//    char line[NMAX];
//    char User[NMAX];
//
//    for(int i = 0; i <= *nr; i++)
//        if(strcmp(Agenda[i].NrTelefon ,TargetTelefon) == 0)
//            aux[k++] = Agenda[i];
//
//    if(k > 0) {
//        int choice = -1;
//        char choicec;
//        do{
//            for (int i = 0; i < k; i++) {
//                printf("<-------  ------->\n");
//                printf("--%d--\n", i);
//                printf("%s\n", aux[i].Nume);
//                printf("%s\n", aux[i].Prenume);
//                printf("%s\n", aux[i].NrTelefon);
//                printf("%s\n", aux[i].Email);
//                printf("%s\n", aux[i].Eticheta);
//            }
//            printf("Alegere: 0 -> %d\n", k - 1);
//            fflush(stdin);
//            scanf("%c", &choicec);
//            if (isdigit(choicec) && choicec >= '0' && choicec <= (k - 1) + '0')
//                choice = choicec - '0';
//        }while(choice == -1);
//        for(int i = 0; i <= *nr; i++)
//            if(!(strcmp(Agenda[i].NrTelefon ,TargetTelefon) == 0 && strcmp(Agenda[i].Prenume, aux[choice].Prenume) == 0 && strcmp(Agenda[i].Nume, aux[choice].Nume) == 0))
//                fprintf(fname2,"%s,%s,%s,%s,%s,%s\n",CurrentUser,Agenda[i].Nume,Agenda[i].Prenume,Agenda[i].NrTelefon,Agenda[i].Email,Agenda[i].Eticheta);
//
//    }
//    struct contact2 otherUsersContacts[NMAX];
//    int nr2 = -1;
////    printf("%s",CurrentUser);
//    preluareDateOtherUsers(CurrentUser,otherUsersContacts, &nr2);
//    for(int i = 0; i <= nr2; i++)
////        printf("%s,%s,%s,%s,%s,%s\n",otherUsersContacts[i].currentUser,otherUsersContacts[i].Nume,otherUsersContacts[i].Prenume,otherUsersContacts[i].NrTelefon,otherUsersContacts[i].Email,otherUsersContacts[i].Eticheta);
//        fprintf(fname2,"%s,%s,%s,%s,%s,%s\n",otherUsersContacts[i].currentUser,otherUsersContacts[i].Nume,otherUsersContacts[i].Prenume,otherUsersContacts[i].NrTelefon,otherUsersContacts[i].Email,otherUsersContacts[i].Eticheta);
//
//
//
////    Replace the initial file
//    if(k > 0) {
//        fclose(fname2);
//        fclose(fname);
//        fname2 = fopen("contacts2.txt", "r");
//        fname = fopen("contacts.txt", "w+");
//        while (fgets(line, NMAX, fname2))
//            fprintf(fname, line);
//
//
//        fclose(fname2);
//        fclose(fname);
//
//        *nr = -1;
//        preluareDate(CurrentUser, Agenda, nr);
//    }
//    else
//        printf("<----0 contacte gasite---->\n\n");
//}
//
