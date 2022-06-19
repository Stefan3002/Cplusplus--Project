//
// Created by Stefan on 19.06.2022.
//

#include "operatiiPePersoane.h"
#include "OperatiiBaza.h"
#include "preluareDate.h"
#include <iostream>
#include <fstream>

using namespace std;


//TRANSLATED RADU
void adaugaContact(string &CurrentUser, string Nume, string Prenume, string NrTelefon, string Email, string Eticheta, string Fav, int &nr, vector <contact> &Agenda){
    ofstream iesire("contacts.txt", ofstream::app);
    iesire<<CurrentUser<<";"<<Nume<<";"<<Prenume<<";"<<NrTelefon<<";"<<Email<<";"<<Eticheta<<Fav<<endl;
    contact newContact(Nume, Prenume, NrTelefon, Email, Eticheta, CurrentUser, Fav == "y");
    Agenda.push_back(newContact);
}

void AdaugaPersoana(int &nr, string &CurrentUser, vector <contact> &Agenda){
    string Nume,Prenume,Mail,NrTelefon;
    string Eticheta;
    string Fav;
    citireDateUtilizator(Nume,Prenume,Mail,NrTelefon,Eticheta,Fav);
    cout<<endl<<"Persoana a fost adaugata cu succes!"<<endl;
    adaugaContact(CurrentUser, Nume,Prenume,NrTelefon,Mail,Eticheta,Fav,nr,Agenda);
}


void StergePersoana(int &nr, string CurrentUser, vector <contact> &Agenda){

    int Alegere = -1;
    char Alegerec;
    do {
        cout<<"1. Dupa nume."<<endl;
        cout<<"0. Pentru a parasii acest meniu introduceti cifra 0."<<endl;
        do {
            fflush(stdin);
            cout<<"----------->Optiune:"<<endl;
            cin>>Alegerec;
            if(isdigit(Alegerec))
                Alegere = Alegerec - '0';
        }while(Alegere == -1);
        string Victima_Nume,Victima_Telefon;
        int OK;
        switch (Alegere) {
            case 1:
                cout<<endl<<"Nume cautat:"<<endl;
                cin>>Victima_Nume;
                stergeContact(CurrentUser,Agenda, nr ,Victima_Nume);
                return;
            case 0:
                cout<<"\n\n";
                return;
            default:
                cout<<"Alegere invalida"<<endl;
                StergePersoana(nr, CurrentUser, Agenda);

        }
    }while(Alegere == 1);
}

void ModificarePersoane(int &nr, string CurrentUser, vector <contact> &Agenda){
    int j = 0;
    for(auto i: Agenda) {
        cout<<"---------"<<j<<"----------"<<endl;
        cout << i << endl;
        j++;
        i.getFav() ? cout<<"Favorit: DA" : cout<<"Favorit: NU";
        cout << endl;
    }
    cout<<endl<<"Alegeti numarul inregistrarii pe care doriti sa o modificati: ";
    char optiune;
    int alegere = 0;

    do {
        cout<<endl<<"Optiune: "<<endl;
        cin>>optiune;
        if(isdigit(optiune))
            alegere = optiune - '0';
    }while(alegere >= j);

    cout<<Agenda[alegere]<<endl;
    Agenda[alegere].getFav() ? cout<<"Favorit : DA" : cout<<"Favorit: NU";
    cout<<endl;

    string Nume,Prenume,Mail,NrTelefon;
    string Eticheta;
    string Fav;
    citireDateUtilizator(Nume,Prenume,Mail,NrTelefon,Eticheta,Fav);
    Agenda[alegere].setNume(Nume);
    Agenda[alegere].setPrenume(Prenume);
    Agenda[alegere].setMail(Mail);
    Agenda[alegere].setNrTelefon(NrTelefon);
    Agenda[alegere].setEticheta(Eticheta);
    Agenda[alegere].setFav(Fav == "y");
    cout<<"-----------Contact modificat cu succees!-----------"<<endl;
}

