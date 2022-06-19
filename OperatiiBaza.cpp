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
#include <algorithm>
#include "preluareDate.h"
#include "contact.h"
#include "superUser.h"
#include "cautaPersoana.h"
#include "operatiiPePersoane.h"
using namespace std;

int nr = -1;
string CurrentUser;


//TRANSLATED RADU
void PrintToatePersoane(vector <contact> Agenda){
    for(auto i:Agenda){
//        Contacte favorite
        if(i.getFav())
        {
            system("color 90");
            cout<<"<-------******------->"<<endl;
        }
        else
            cout<<"<-------  ------->"<<endl;
        cout<< i.getNume()<<endl;
        cout<< i.getPrenume()<<endl;
        cout<< i.getNrTelefon()<<endl;
        if(i.getEmail()[0] != '-')
            cout<<i.getEmail()<<endl;
        if(i.getEticheta()[0] != '-')
            cout<< i.getEticheta()<<endl;
        system("color 07");
    }

}
//TRANSLATED RADU
void PrintEtichetaPersoane(string Tag,vector <contact> Agenda){
    short int printed = 0;
    short matches_found = 0;
    for(int i = 0; i < Tag.length(); i++)
        if(Tag[i] >= 'A' && Tag[i] <= 'Z')
            Tag[i] += 32;
    for(auto i:Agenda){
//        cout<<"-----------------------"<<i<<"----------------"<<endl;
//        cout<<Tag<<"="<<i.getEticheta()<<"="<<endl;
        if (i.getEticheta() == Tag) {
            matches_found++;
            printed = 1;
            if (i.getFav()) {
                cout<<"<-------******------->\n";
            } else
                cout<<"<-------  ------->\n";
            cout<<i<<endl;
        }
    }
    if(!printed){
        cout<<"!!!!!!!!!!!!!!!!!!!"<<endl;
        cout<<"0 inregistrari gasite."<<endl;
        cout<<"!!!!!!!!!!!!!!!!!!!"<<endl;
    }
    else
        cout<<"<==>"<<matches_found<<"inregistrari gasite <==>"<<endl;

}
bool sort_helper(contact c1, contact c2){
    if(c2.getFav())
        if(c1.getFav())
            if(c1.getNume() < c2.getNume())
                return true;
            else
                return false;
            else return true;

    else
        if(c1.getNume() < c2.getNume())
            return true;
}
//TRANSLATED RADU
void PrintAlfabetic(vector <contact> &Agenda)
{
    sort(Agenda.begin(), Agenda.end(), sort_helper);
    for(auto i:Agenda){
        if(i.getFav())
        {
            system("color 90");
            cout<<"<-------******------->"<<endl;
        }
        else
            cout<<"<-------  ------->"<<endl;
        cout<< i.getNume()<<endl;
        cout<< i.getPrenume()<<endl;
        cout<< i.getNrTelefon()<<endl;
        if(i.getEmail()[0] != '-')
            cout<< i.getEmail()<<endl;
        if(i.getEticheta()[0] != '-')
            cout<< i.getEticheta()<<endl;
        system("color 07");
    }
}

//TRANSLATED RADU
void PrintPersoane(vector <contact> Agenda){

    int alegere = -1;
    char alegerec;
    string Tag;
    do{
        cout<<"1. Toate contactele."<<endl;
        cout<<"2. Dupa eticheta."<<endl;
        cout<<"3. Alfabetic."<<endl;
        cout<<"0. Pentru a reveni la meniul anterior introduceti cifra 0."<<endl;
        do {
            cout<<"----------->Optiune: "<<endl;
            cin>>alegerec;
            if(isdigit(alegerec))
                alegere = alegerec - '0';
            else
                cout<<"Introduceti un numar corespunzator."<<endl;
        }while(alegere == -1);

        switch(alegere){
            case 1:
                PrintToatePersoane(Agenda);
                return;
            case 2:
                cout<<endl<<"Eticheta: ";
                cin>>Tag;
                PrintEtichetaPersoane(Tag, Agenda);
                return;
            case 3:
                PrintAlfabetic(Agenda);
                return;
            case 0:
                return;
            default:
                cout<<"Alegere invalida!"<<endl<<endl;
                PrintPersoane(Agenda);
        }
    }while(alegere != 0);
}

short int go = 0;
short int nr_incercari = 2;

//TRANSLATED STEFAN it works!
int ScrieOptiuni(int cuIntampinare,vector <contact> &Agenda, superUser &superUser){

    nr_incercari--;
    if(!go)
        if(startLogin(CurrentUser, superUser))
            go = 1;

    if(go) {
        system("color 8F");

        if(cuIntampinare) {
            cout<<"<=====Bine ati venit!=====>\n";
            cout<<"<----Agenda telefonica!---->\n";
            preluareDate(CurrentUser,Agenda,nr);
        }

        cout<<"\n\n";
        cout<<"1. Adaugati o persoana\n";
        cout<<"2. Stergeti o persoana\n";
        cout<<"3. Vizualizati lista de persoane\n";
        cout<<"4. Modificati o inregistrare\n";
        cout<<"5. Informatile mele\n";
        cout<<"6. Cauta persoana\n";
        cout<<"0. Pentru a parasii aplicatia introduceti cifra 0\n";
        system("color 07");
        return 1;
    }
    else
    if(nr_incercari){
        cout<<"\nIncercare 2/2.\n";
        ScrieOptiuni(cuIntampinare, Agenda, superUser);
    }

}
void citireDateUtilizator(string &Nume, string &Prenume, string &Mail, string &NrTelefon, string &Eticheta, string &Fav){

    int OK = 1;
    char aux = '-';

    do {
        OK = 1;
        cout<<"Nume* (Doar litere):"<<endl;
        cin>>Nume;
        for(int i = 0; i < Nume.length(); i++)
            if(!((Nume[i] >= 'A' && Nume[i] <= 'Z') || (Nume[i] >= 'a' && Nume[i] <= 'z'))) {
                OK = 0;
                cout<<"Numele trebuie sa contina doar litere."<<endl;
                break;
            }

        if(Nume[0] == '-') {
            OK = 0;
            cout<<"Numele este obligatoriu."<<endl;
        }
    }while(!OK);
    do {
        OK = 1;
        cout<<"Prenume* (Doar liere):"<<endl;
        cin>>Prenume;
        for(int i = 0; i < Prenume.length(); i++)
            if(!((Prenume[i] >= 'A' && Prenume[i] <= 'Z') || (Prenume[i] >= 'a' && Prenume[i] <= 'z'))) {
                OK = 0;
                cout<<"Prenumele trebuie sa contina doar litere."<<endl;
                break;
            }

        if(Prenume[0] == '-') {
            OK = 0;
            cout<<"Prenumele este obligatoriu."<<endl;
        }
    }while(!OK);
    do {
        OK = 1;
        cout<<"Numar telefon* (Doar cifre):"<<endl;
        cin>>NrTelefon;
        if(NrTelefon.length() != 10) {
            OK = 0;
            cout<<"Numarul trebuie sa contina 10 cifre."<<endl;
        }
        for(int i = 0; i < NrTelefon.length(); i++)
            if(!(NrTelefon[i] >= '0' && NrTelefon[i] <= '9')){
                OK = 0;
                cout<<"Numarul trebuie sa contina doar cifre."<<endl;
                break;
            }

        if(NrTelefon[0] == '-') {
            OK = 0;
            cout<<"Numarul de telefon este obligatoriu."<<endl;
        }
    }while(!OK);
    do {
        OK = 1;
        cout<<"E-mail:"<<endl;
        cin>>Mail;
        int nrarond = 0;
        int nrpunct = 0;
        for(int i = 0; i < Mail.length(); i++)
            if(Mail[0] == '-'){
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
            cout<<"Adresa de email trebuie sa contina simbolul @ si un punct."<<endl;
        }
    }while(!OK);
    do {
        OK = 1;
        cout<<"Eticheta:"<<endl;
        cin>>Eticheta;
        for(int i = 0; i < Eticheta.length(); i++)
            if(Eticheta[0] == '-')
                OK = 1;
            else
            if(!((Eticheta[i] >= 'A' && Eticheta[i] <= 'Z') || (Eticheta[i] >= 'a' && Eticheta[i] <= 'z'))) {
                OK = 0;
                cout<<"Eticheta trebuie sa contina doar litere."<<endl;
                break;
            }
    }while(!OK);
    do{
        OK = 1;
        cout<<"Favourite y/n?"<<endl;
        cin>>Fav;
        if(Fav != "y" && Fav != "n") {
            cout<<"Raspundeti cu y/n."<<endl;
            OK = 0;
        }
    }while(!OK);
    for(int i = 0; i < Eticheta.length(); i++)
        if(Eticheta[i] >= 'A' && Eticheta[i] <= 'Z')
            Eticheta[i] += 32;

}


//TRANSLATED STEFAN
void AfiseazaMeniu(vector <contact> &Agenda, superUser &superUser){

    int alegere = -1;
    char alegerec;
    int cuIntampinare = 1;
    do {
        if(ScrieOptiuni(cuIntampinare,Agenda, superUser) == 0)
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
                AdaugaPersoana(nr, CurrentUser, Agenda);
                break;
            case 2:
                cuIntampinare = 0;
                cout<<"\n\n<----Stergere de persoane.---->\n\n";
                StergePersoana(nr, CurrentUser, Agenda);
                break;
            case 3:
                cuIntampinare = 0;
                cout<<"<--------Afisare persoane---------->"<<endl<<endl;
                PrintPersoane(Agenda);
                break;
            case 4:
                cuIntampinare = 0;
                cout<<"<--------Modificare persoane---------->"<<endl<<endl;
                ModificarePersoane(nr, CurrentUser, Agenda);
                break;
            case 5:
                cuIntampinare = 0;
                cout<<"<--------Informatile mele---------->"<<endl<<endl;
                superUserInfo(superUser);
                break;
            case 6:
                cuIntampinare = 0;
                cout<<"<--------Cauta persoana---------->"<<endl<<endl;
                cautaPersoana(superUser, Agenda);
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


