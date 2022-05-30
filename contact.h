//
// Created by Stefan on 18.05.2022.
//

#ifndef PROIECT_PP_C___CONTACT_H
#define PROIECT_PP_C___CONTACT_H
#include <string>
using namespace std;

class contact {
private:
    string Nume,Prenume,NrTelefon;
    string Email,Eticheta;
    string CurrentUser;
    bool fav;
    void init(string Nume, string Prenume, string NrTelefon, string Email, string Eticheta, string CurrentUser, bool fav);
public:
    contact(string Nume, string Prenume, string NrTelefon, string Email, string Eticheta, string CurrentUser = "", bool fav = false);
    friend ostream& operator << (ostream& COUT, contact& c);
    friend bool operator < (contact& c1, contact& c2);

    string getNume(){
        return this->Nume;
    }
    string getPrenume(){
        return this->Prenume;
    }
    string getEmail(){
        return this->Email;
    }
    string getNrTelefon(){
        return this->NrTelefon;
    }
    string getEticheta(){
        return this->Eticheta;
    }
    string getCurrentUser(){
        return this->CurrentUser;
    }
    bool getFav(){
        return this->fav;
    }
};


#endif //PROIECT_PP_C___CONTACT_H
