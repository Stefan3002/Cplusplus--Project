//
// Created by Stefan on 18.05.2022.
//

#include "contact.h"
#include <iostream>
using namespace std;

void contact::init(string Nume, string Prenume, string NrTelefon, string Email, string Eticheta, string CurrentUser, bool fav) {
    this->Nume = Nume;
    this->Prenume = Prenume;
    this->NrTelefon = NrTelefon;
    this->Email = Email;
    this->Eticheta = Eticheta;
    this->CurrentUser = CurrentUser;
    this->fav = fav;
}

contact::contact(string Nume, string Prenume, string NrTelefon, string Email, string Eticheta, string CurrentUser, bool fav) {
    init(Nume, Prenume, NrTelefon, Email, Eticheta, CurrentUser, fav);
}

ostream &operator<<(ostream &COUT, contact &c) {
    c.getInfo(COUT);
    return COUT;
}

bool operator<(contact &c1, contact &c2) {
    if(c1.getNume() != c2.getNume())
        return c1.getNume() < c2.getNume();
    else
        return c1.getPrenume() < c2.getPrenume();
}

ostream& contact::getInfo(ostream &COUT) {
    COUT<<this->Nume<<" "<<this->Prenume<<endl<<this->NrTelefon<<endl<<this->Email<<endl<<this->Eticheta;
    return COUT;
}
