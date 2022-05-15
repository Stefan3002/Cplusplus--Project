//
// Created by Stefan on 16.03.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NMAX 70

void Encrypt(char text[],int key){

for(int i = 0; i < strlen(text); i++)
//    if((int) (text[i]) + key > 122)
//        text[i] = (text[i] + key) % 122 + 96;
//    else
        text[i] += key;
}

void Decrypt(char text[],int key){

    for(int i = 0; i < strlen(text); i++)
//        if((int) (text[i]) - key < 97)
//            text[i] = (123 + (text[i] - 97) - key);
//        else
            text[i] -= key;
}


int createAccount(){

    char Username[NMAX],Password[NMAX];
    FILE * fname;

    int key = 0;
    char keyc;

    printf("<=====Cont nou!=====>\n");
    printf("Nume utilizator nou:\n");
    scanf("%s",Username);
    printf("Parola noua:\n");
    scanf("%s",Password);
    printf("Cheie noua:\n");
    printf("Daca cheia introdusa este formata din mai multe cifre se va lua in considerare doar prima cifra.\n");
    do {
        fflush(stdin);
        printf("Cheia ( 1->9 ):\n");
        scanf("%c", &keyc);
        if (isdigit(keyc) && keyc >= '1' && keyc <= '9')
            key = keyc - '0';
    }while(!key);

    ///Opening file

    fname = fopen("user.txt","a");
    if(fname == NULL){
        printf("Nu am putut deschide fisierul...");
        return 0;
    }

    Encrypt(Password,key);

    fprintf(fname,"%s\n%s\n",Username,Password);
    fflush(fname);
    fclose(fname);
    printf("Utilizator creat cu succes!\n");
    return 1;
}



int login(char CurrentUser[]){
    char Username[NMAX] = " ",Password[NMAX] = " ";
    char inputUsername[NMAX] = " ",inputPassword[NMAX] = " ";
    FILE * fname;
    fname = fopen("user.txt","r");
    if(fname == NULL){
        printf("Nu am putut deschide fisierul...");
        return 0;
    }
    char line[NMAX];

    printf("Nume utilizator:\n");
    scanf("%s",inputUsername);

    while(fgets(line,NMAX,fname)) {
        if(line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';

        strcpy(Username,line);
        fgets(line,NMAX,fname);

        if(line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';

        strcpy(Password,line);
        if(strcmp(Username,inputUsername) == 0)
            break;
    }
    fclose(fname);

    //Start input

    int key = 0;
    char keyc;

    printf("Parola:\n");
    scanf("%s",inputPassword);
    printf("Daca cheia introdusa este formata din mai multe cifre se va lua in considerare doar prima cifra.\n");
    do {
        fflush(stdin);
        printf("Cheia ( 1->9 ):\n");
        scanf("%c", &keyc);
        if (isdigit(keyc) && keyc >= '1' && keyc <= '9')
            key = keyc - '0';
    }while(!key);



    strcpy(CurrentUser, inputUsername);

    char DecryptedPass[NMAX];
    strcpy(DecryptedPass,Password);
    Decrypt(DecryptedPass,key);

    if(strcmp(inputUsername,Username) == 0)
        if(strcmp(inputPassword,DecryptedPass) == 0)
            return 1;
    printf("Combinatie gresita");
    return 0;
}




int startLogin(char CurrentUser[]){
    char answer = ' ';
    printf("<=====Login=====>\n");
    printf("\nAveti cont? y/n\n");
    fflush(stdin);
    scanf("%c",&answer);
    if(answer == 'y'){
        short int aux = login(CurrentUser);
        return aux;
    }
    else if (answer == 'n')
        return createAccount();
    else{
        printf("Alegere invalida!\n");
        startLogin(CurrentUser);
    }
    return 0;
}