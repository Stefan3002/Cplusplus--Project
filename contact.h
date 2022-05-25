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
    void init(string Nume, string Prenume, string NrTelefon, string Email, string Eticheta, string CurrentUser);
public:
    contact(string Nume, string Prenume, string NrTelefon, string Email, string Eticheta, string CurrentUser = "");
    friend ostream& operator << (ostream& COUT, contact& c);

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
};


#endif //PROIECT_PP_C___CONTACT_H
