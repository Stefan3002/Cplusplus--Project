#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

int count = 0;

typedef struct Proiect_final
{
    char Nume[20], Prenume[20], Mail[30], Companie[50], Domiciliu[50], Telefon[11];

} intrare;
intrare vector_intrari[100];

void Autentificare()
{
    char nume[100], parola[50];
    char NumeParola[100];
    FILE *in = fopen("Autentificare.txt", "r");
    fgets(NumeParola, 100, in);
    printf("-------AUTENTIFICARE-------\n");
    while (1)
    {
        printf("Introduceti numele de utilizator:");
        scanf("%s", nume);
        printf("Introduceti parola:");
        scanf("%s", parola);
        strcat(nume, parola);
        if (strcmp(nume, NumeParola) == 0)
        {
            printf("Autentificare facuta cu succes\n");
            break;
        }
        else
        {
            printf("Numele sau parola nu sunt bune\nIncearca din nou\n");
        }
    }

    fclose(in);
}

void OptiuniMeniu()
{
    printf("\n\n");
    printf("1. Adaugati un contact nou\n");
    printf("2. Stergeti un contact existent\n");
    printf("3. Cauta un contact in agenda\n");
    printf("4. Vizualizati toata lista contactelor\n");
    printf("5. Creeaza o copie de rezerva\n");
    printf("0. Parasiti aplicatia\n");
}

void AdaugaContact()
{
    char input[50];
    printf("Nume: \n");
    scanf("%19s", input);
    strcpy(vector_intrari[count].Nume, input);

    printf("Prenume: \n");
    scanf("%19s", input);
    strcpy(vector_intrari[count].Prenume, input);

    printf("Companie: \n");
    scanf("%49s", input);
    strcpy(vector_intrari[count].Companie, input);

    printf("E-mail: \n");
    scanf("%29s", input);
    strcpy(vector_intrari[count].Mail, input);

    printf("Domiciliu: \n");
    scanf("%49s", input);
    strcpy(vector_intrari[count].Domiciliu, input);

    printf("Telefon: \n");
    scanf("%10s", input);
    strcpy(vector_intrari[count].Telefon, input);

    count++;
    printf("\nContactul a fost adaugat cu succes!\n");
}

void ScrieFisier()
{
    FILE *out = NULL;
    out = fopen("Agenda.csv", "w");
    if (out == NULL)
    {
        perror("ERROR");
        exit(-1);
    }
    fprintf(out, "Nume,Prenume,Mail,Companie,Domiciliu,Telefon\n");
    for (int i = 0; i < count; i++)
    {
        if (strcmp(vector_intrari[i].Nume, "NULL") == 0)
            continue;
        fprintf(out, "%s,", vector_intrari[i].Nume);
        fprintf(out, "%s,", vector_intrari[i].Prenume);
        fprintf(out, "%s,", vector_intrari[i].Mail);
        fprintf(out, "%s,", vector_intrari[i].Companie);
        fprintf(out, "%s,", vector_intrari[i].Domiciliu);
        fprintf(out, "%s,\n", vector_intrari[i].Telefon);
    }

    fclose(out);
}

void StergeContact()
{

    int Alegere, alegere, ok = 0;
    char nume[50];

    printf("\nNume cautat: \n");
    scanf("%s", nume);
    for (int i = 0; nume[i] != '\0'; i++)
    {
        if (nume[i] >= 'a' && nume[i] <= 'z')
        {
            nume[i] = nume[i] - 32;
        }
    }
    for (int i = 0; i < count; i++)
    {
        char nume1[50];
        strcpy(nume1, vector_intrari[i].Nume);
        for (int j = 0; nume1[j] != '\0'; j++)
        {
            if (nume1[j] >= 'a' && nume1[j] <= 'z')
            {
                nume1[j] = nume1[j] - 32;
            }
        }

        if (strcmp(nume, nume1) == 0)
        {
            ok = 1;
            printf("Contactul dorit este: %s %s?", vector_intrari[i].Nume, vector_intrari[i].Telefon);
            printf("\n1. Sterge un contact\n");
            printf("2. Arata alt contact similar\n");
            scanf("%d", &alegere);
            if (alegere == 1)
            {
                strcpy(vector_intrari[i].Nume, "NULL");
                printf("Contactul a fost sters\n");
                break;
            }
            else if (alegere == 2)
            {
                continue;
            }
        }
    }
    if (ok == 1)
    {
        printf("Nu mai sunt alte contacte cu acest nume\n");
    }
    else
    {
        printf("Nu au fost gasite contacte cu numele introdus\n");
    }
}

void CautareContact()
{
    int ok = 0;
    char nume[50];
    printf("Introduceti numele cautat:");
    scanf("%s", nume);
    printf( "Nume    \t\tPrenume     \t\tMail    \t\tCompanie    \t\tDomiciliu   \t\tTelefon\n");
    for (int i = 0; nume[i] != '\0'; i++)
    {
        if (nume[i] >= 'a' && nume[i] <= 'z')
        {
            nume[i] = nume[i] - 32;
        }
    }
    for (int i = 0; i < count; i++)
    {

        char nume1[50];
        strcpy(nume1, vector_intrari[i].Nume);
        for (int j = 0; nume1[j] != '\0'; j++)
        {
            if (nume1[j] >= 'a' && nume1[j] <= 'z')
            {
                nume1[j] = nume1[j] - 32;
            }
        }

        if (strcmp(nume, nume1) == 0)
        {
            ok = 1;
            int j;
            int len1 = 25 - strlen(vector_intrari[i].Nume);
            int len2 = 25 - strlen(vector_intrari[i].Prenume);
            int len3 = 25 - strlen(vector_intrari[i].Mail);
            int len4 = 25 - strlen(vector_intrari[i].Companie);
            int len5 = 19 - strlen(vector_intrari[i].Domiciliu);
            int len6 = 10 - strlen(vector_intrari[i].Telefon);
            printf("%s",vector_intrari[i].Nume);
            for(j=0;j<len1;j++) printf(" ");

            printf("%s",vector_intrari[i].Prenume);
            for(j=0;j<len2;j++) printf(" ");

            printf("%s",vector_intrari[i].Mail);
            for(j=0;j<len3;j++) printf(" ");

            printf("%s",vector_intrari[i].Companie);
            for(j=0;j<len4;j++) printf(" ");

            printf("%s",vector_intrari[i].Domiciliu);
            for(j=0;j<len5;j++) printf(" ");

            printf("%s",vector_intrari[i].Telefon);
            for(j=0;j<len6;j++) printf(" ");

            printf("\n");
        }
    }
    if (ok == 0)
    {
        printf("Contactul %s nu a fost gasit\n", nume);
    }
}

void AfisareContacte()
{

    printf( "Nume    \t\tPrenume     \t\tMail    \t\tCompanie    \t\tDomiciliu   \t\tTelefon\n");
    for (int i = 0; i < count; i++)
    {
        if (strcmp(vector_intrari[i].Nume, "NULL") == 0)
            continue;
            int j;
            int len1 = 25 - strlen(vector_intrari[i].Nume);
            int len2 = 25 - strlen(vector_intrari[i].Prenume);
            int len3 = 25 - strlen(vector_intrari[i].Mail);
            int len4 = 25 - strlen(vector_intrari[i].Companie);
            int len5 = 19 - strlen(vector_intrari[i].Domiciliu);
            int len6 = 10 - strlen(vector_intrari[i].Telefon);
            printf("%s",vector_intrari[i].Nume);
            for(j=0;j<len1;j++) printf(" ");

            printf("%s",vector_intrari[i].Prenume);
            for(j=0;j<len2;j++) printf(" ");

            printf("%s",vector_intrari[i].Mail);
            for(j=0;j<len3;j++) printf(" ");

            printf("%s",vector_intrari[i].Companie);
            for(j=0;j<len4;j++) printf(" ");

            printf("%s",vector_intrari[i].Domiciliu);
            for(j=0;j<len5;j++) printf(" ");

            printf("%s",vector_intrari[i].Telefon);
            for(j=0;j<len6;j++) printf(" ");

            printf("\n");
    }
}

void Backup()
{
    FILE *in = fopen("Agenda_Backup.csv", "w");
    fprintf(in, "Nume,Prenume,Mail,Companie,Domiciliu,Telefon\n");
    
    for (int i = 0; i < count; i++)
    {
        fprintf(in, "%s,", vector_intrari[i].Nume);
        fprintf(in, "%s,", vector_intrari[i].Prenume);
        fprintf(in, "%s,", vector_intrari[i].Mail);
        fprintf(in, "%s,", vector_intrari[i].Companie);
        fprintf(in, "%s,", vector_intrari[i].Domiciliu);
        fprintf(in, "%s,\n", vector_intrari[i].Telefon);
    }
    fclose(in);
}

void AfisareMeniu()
{
    int alegere;
    do
    {
        OptiuniMeniu();
        scanf("%d", &alegere);
        switch (alegere)
        {
        case 1:

            printf("\n\nAdaugare contact.\n\n");
            AdaugaContact();
            break;
        case 2:

            printf("\n\nStergere contact.\n\n");
            StergeContact();
            break;
        case 3:
            printf("\n\nCautare contact.\n\n");
            CautareContact();
            break;
        case 4:
            printf("\n\nToate contactele sunt.\n\n");
            AfisareContacte();
            break;
        case 5:
            Backup();
            break;
        case 0:
            printf("Va multumim ca ati folosit serviciile noastre.");
            break;
        default:
            printf("Alegere invalida\n");
            break;
        }

    } while (alegere != 0);
}

void Initializare()
{
    printf("\nBine ati venit la agenda telefonica!\n");
    FILE *in = NULL;
    in = fopen("Agenda.csv", "a+");
    if (in == NULL)
    {
        perror("ERROR at opening file");
        exit(-1);
    }
    char linie[1000];
    char *p;
    fgets(linie, 1000, in);
    while (fgets(linie, 1000, in) != NULL)
    {
        linie[strlen(linie) - 1] = '\0';
        p = strtok(linie, ",");
        strcpy(vector_intrari[count].Nume, p);
        p = strtok(NULL, ",");
        strcpy(vector_intrari[count].Prenume, p);
        p = strtok(NULL, ",");
        strcpy(vector_intrari[count].Mail, p);
        p = strtok(NULL, ",");
        strcpy(vector_intrari[count].Companie, p);
        p = strtok(NULL, ",");
        strcpy(vector_intrari[count].Domiciliu, p);
        p = strtok(NULL, ",");
        strcpy(vector_intrari[count].Telefon, p);
        count++;
    }
    fclose(in);
}

int main()
{
    Autentificare();
    Initializare();
    AfisareMeniu();
    ScrieFisier();
    return 0;
}