//
// Created by Stefan on 19.06.2022.
//

#include <iostream>
#include "superUser.h"

superUser::superUser(string Nume, string Prenume, string NrTelefon, string Email, string Eticheta, string CurrentUser,
                     bool fav, string parola): contact(Nume,Prenume,NrTelefon,Email,Eticheta,CurrentUser, fav) {
    this->parola = parola;

}

ostream &operator<<(ostream &COUT, superUser &s) {
    s.getInfo(COUT);
    return COUT;
}

ostream &superUser::getInfo(ostream &COUT) {
    contact::getInfo(COUT);
    cout<<this->parola;
    return COUT;
}
