//
// Created by Stefan on 19.06.2022.
//

#include "cautaPersoana.h"
#include <iostream>
#include <fstream>
#include "Login.h"

using namespace std;

void cautaPersoana(superUser superUser, vector<contact> Agenda){
    bool OK = 0;
    string Nume;
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

    bool found = false;
    for(auto i: Agenda)
        if(i.getNume() == Nume) {
            found = true;
            cout<<"--------------------------"<<endl;
            cout << i << endl;
        }
    if(!found)
        cout<<"0 contacte gasite."<<endl;
}


void superUserInfo(superUser& superUser){
    cout<<"Acestea sunt informatile mele:"<<endl;
    cout<<superUser<<endl;
    cout<<"Vrei sa modifici parola? y/n"<<endl;
    char Alegerec;
    do {
        fflush(stdin);
        cout<<"----------->Optiune:"<<endl;
        cin>>Alegerec;
    }while(Alegerec != 'y' && Alegerec != 'n');
    if(Alegerec == 'y') {
        ofstream iesire("users2.txt");
        ifstream intrare("user.txt");
        string username,pass;
        while(intrare>>username){
            intrare>>pass;

            if(username != superUser.getNume())
                iesire<<username<<endl<<pass<<endl;
        }
        ofstream iesire2("user.txt", ofstream::trunc);
        createAccount(superUser, superUser.getNume());
        ifstream intrare2("users2.txt");
        ofstream iesire3("user.txt", ofstream::app);
        iesire3<<endl;
        while(intrare2>>username){
            intrare2>>pass;
            iesire3<<username<<endl<<pass<<endl;
        }
    }

}