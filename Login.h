//
// Created by Stefan on 18.05.2022.
//

#ifndef PROIECT_PP_C___LOGIN_H
#define PROIECT_PP_C___LOGIN_H
#include <string>
#include "contact.h"
#include "superUser.h"
using namespace std;

int startLogin(string &CurrentUser, superUser& superUser);
int createAccount(superUser& superUser, string mandatoryName = "");
#endif //PROIECT_PP_C___LOGIN_H
