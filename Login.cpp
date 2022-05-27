//
// Created by Stefan on 18.05.2022.
//

#include "Login.h"


#include <string>
#include <iostream>
#include <fstream>

using namespace std;
#define NMAX 70

//TRANSLATE STEFAN Verified It WORKS!
void Encrypt(string &text,int key){

    for(int i = 0; i < text.length(); i++)
        text[i] += key;
}
//TRANSLATE STEFAN Verified It WORKS!
void Decrypt(string &text,int key){

    for(int i = 0; i < text.length(); i++)
        text[i] -= key;
}

//TRANSLATE STEFAN Verified It WORKS!
int createAccount(){
    string Username, Password;
    int key = 0;
    char keyc;

   cout<<"<=====Cont nou!=====>\n";
    cout<<"Nume utilizator nou:\n";
    cin>>Username;
    cout<<"Parola noua:\n";
    cin>>Password;
    cout<<"Cheie noua:\n";
    cout<<"Daca cheia introdusa este formata din mai multe cifre se va lua in considerare doar prima cifra.\n";
    do {
//        fflush(stdin);
        cout<<"Cheia ( 1->9 ):\n";
        cin>>keyc;
        if (isdigit(keyc) && keyc >= '1' && keyc <= '9')
            key = keyc - '0';
    }while(!key);

    ///Opening file

    ofstream iesire("user.txt", fstream::app);

    Encrypt(Password,key);

    iesire<<endl<<Username<<endl<<Password;
    cout<<"Utilizator creat cu succes!\n";
    return 1;
}


//TRANSLATE STEFAN Verified It WORKS!
int login(string &CurrentUser){
    string Username = "", Password = "", inputUsername = "", inputPassword = "";

    ifstream intrare("user.txt");
//    if(fname == NULL){
//        cout<<"Nu am putut deschide fisierul...");
//        return 0;
//    }
    string line;

    cout<<"Nume utilizator:\n";
    cin>>inputUsername;

    while(intrare>>line) {
//        if(line[strlen(line) - 1] == '\n')
//            line[strlen(line) - 1] = '\0';

        Username = line;
//        fgets(line,NMAX,fname);

//        if(line[strlen(line) - 1] == '\n')
//            line[strlen(line) - 1] = '\0';
        intrare>>line;
        Password = line;
        if(Username == inputUsername)
            break;
    }
//    fclose(fname);

    //Start input

    int key = 0;
    char keyc;

    cout<<"Parola:\n";
    cin>>inputPassword;
    cout<<"Daca cheia introdusa este formata din mai multe cifre se va lua in considerare doar prima cifra.\n";
    do {
        fflush(stdin);
        cout<<"Cheia ( 1->9 ):\n";
        cin>>keyc;
        if (isdigit(keyc) && keyc >= '1' && keyc <= '9')
            key = keyc - '0';
    }while(!key);



    CurrentUser = inputUsername;

    string DecryptedPass;
    DecryptedPass = Password;
    Decrypt(DecryptedPass,key);

    if(inputUsername == Username)
        if(inputPassword == DecryptedPass)
            return 1;
    cout<<"Combinatie gresita";
    return 0;
}



//TRANSLATE STEFAN
int startLogin(string &CurrentUser){
    char answer = ' ';
    cout<<"<=====Login=====>\n";
    cout<<"\nAveti cont? y/n\n";
    fflush(stdin);
    cin>>answer;
    if(answer == 'y'){
        short int aux = login(CurrentUser);
        return aux;
    }
    else if (answer == 'n')
        return createAccount();
    else{
        cout<<"Alegere invalida!\n";
        startLogin(CurrentUser);
    }
    return 0;
}