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
string PATH = "contacts.txt";

//TRANSLATE STEFAN Verified It WORKS!
void preluareDate(string &CurrentUser,vector <contact> &Agenda, int &nr){

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

        bool Fav = 0;
        User = tokens[0];
        Nume = tokens[1];
        Prenume = tokens[2];
        NrTelefon = tokens[3];
        Email = tokens[4];
        Eticheta = tokens[5];
        if(Eticheta[Eticheta.length() - 1] == 'y') {
            Fav = true;
            Eticheta = Eticheta.substr(0,Eticheta.length() - 1);
        }
        else{
            Fav = false;
            Eticheta = Eticheta.substr(0,Eticheta.length() - 1);
        }
        if(User == CurrentUser){
            contact c(Nume,Prenume,NrTelefon,Email,Eticheta,User,Fav);
            Agenda.push_back(c);
        }
        else
            nr--;

        tokens.clear();
    }
}

//TRANSLATE STEFAN
void preluareDateOtherUsers(string CurrentUser,vector <contact> &Agenda){

    ifstream intrare(PATH);

    string line,User;

    vector <string> tokens;
    int start = 0;

    while(getline(intrare,line)) {
        fflush(stdin);
        start = 0;
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

        tokens.clear();
    }
}


void stergeContact(string CurrentUser,vector <contact> &Agenda, int &nr ,string TargetName) {

    int k = 0;
    ifstream intrare1(PATH);
    ofstream iesire2("contacts2.txt");
    string line;
    vector <contact> aux;
    for(auto i: Agenda)
        if(i.getNume() == TargetName)
            aux.push_back(i);
    k = aux.size() - 1;
    if(k >= 0) {
        int choice = -1;
        char choicec;
        do {
            int p = 0;
            for(auto i: aux) {
                cout << "-----------------" << p << endl << i << endl;
                p++;
            }
            cout<<"Alegere: 0 -> "<<k;
            fflush(stdin);
            cin>>choicec;
            if(isdigit(choicec) && choicec >= '0' && choicec <= k + '0')
                choice = choicec - '0';
        }while(choice == -1);
        for(auto i: Agenda)
            if(!(i.getNume() == TargetName && i.getPrenume() == aux[choice].getPrenume() && i.getNrTelefon() == aux[choice].getNrTelefon()))
                iesire2<<CurrentUser<<";"<<i.getNume()<<";"<<i.getPrenume()<<";"<<i.getNrTelefon()<<";"<<i.getEmail()<<";"<<i.getEticheta()<<endl;

    }

    vector <contact> otherUsersContacts;

    preluareDateOtherUsers(CurrentUser,otherUsersContacts);

    for(auto i: otherUsersContacts)
        iesire2<<i.getCurrentUser()<<";"<<i.getNume()<<";"<<i.getPrenume()<<";"<<i.getNrTelefon()<<";"<<i.getEmail()<<";"<<i.getEticheta()<<endl;

//    Replace the initial file
    if(k >= 0) {
        ifstream intrare2("contacts2.txt");
        ofstream iesire(PATH);
        while (intrare2>>line) {
            iesire << line << endl;
        }
        preluareDate(CurrentUser, Agenda, nr);
    }
    else
        printf("<----0 contacte gasite---->\n\n");
}
