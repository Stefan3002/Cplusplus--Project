//
// Created by Stefan on 17.03.2022.
//
#define NMAX 70

struct contact{
    char Nume[NMAX];
    char Prenume[NMAX];
    char NrTelefon[NMAX];
    char Email[NMAX];
    char Eticheta[NMAX];
};


#ifndef LABORATOR_1_2_PRELUAREDATE_H
#define LABORATOR_1_2_PRELUAREDATE_H
void preluareDate(char CurrentUser[],struct contact Agenda[], int *nr);
void stergeContact(char CurrentUser[],struct contact Agenda[], int *nr, char TargetName[]);
void stergeContactTelefon(char CurrentUser[],struct contact Agenda[], int *nr, char TargetTelefon[]);
#endif //LABORATOR_1_2_PRELUAREDATE_H
