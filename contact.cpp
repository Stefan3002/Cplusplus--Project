//
// Created by Stefan on 18.05.2022.
//

#include "contact.h"
#include <iostream>
using namespace std;

void contact::init(string Nume, string Prenume, string NrTelefon, string Email, string Eticheta) {
    this->Nume = Nume;
    this->Prenume = Prenume;
    this->NrTelefon = NrTelefon;
    this->Email = Email;
    this->Eticheta = Eticheta;
}

contact::contact(string Nume, string Prenume, string NrTelefon, string Email, string Eticheta) {
    init(Nume, Prenume, NrTelefon, Email, Eticheta);
}

ostream &operator<<(ostream &COUT, contact &c) {
    COUT<<c.Nume<<" "<<c.Prenume<<endl<<c.NrTelefon<<endl<<c.Email<<endl<<c.Eticheta;
    return COUT;
}
