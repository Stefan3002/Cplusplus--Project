//
// Created by Stefan on 19.06.2022.
//

#ifndef PROIECT_PP_C___SUPERUSER_H
#define PROIECT_PP_C___SUPERUSER_H
#include <string>
using namespace std;
#include "contact.h"

class superUser: public contact {
private:
    string parola;
public:
    superUser(string Nume = "", string Prenume = "", string NrTelefon = "", string Email = "", string Eticheta = "", string CurrentUser = "", bool fav = false, string parola = "");
    friend ostream& operator << (ostream& COUT, superUser& s);
    ostream& getInfo(ostream& COUT);
    void setParola(string const parola){
        this->parola = parola;
    }
};


#endif //PROIECT_PP_C___SUPERUSER_H
