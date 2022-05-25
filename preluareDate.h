//
// Created by Stefan on 25.05.2022.
//

#ifndef PROIECT_PP_C___PRELUAREDATE_H
#define PROIECT_PP_C___PRELUAREDATE_H
#define NMAX 70
#include "contact.h"
#include <vector>

void preluareDate(string CurrentUser,vector <contact> Agenda, int &nr);
void stergeContact(string CurrentUser,vector <contact> Agenda, int &nr, string TargetName);
void stergeContactTelefon(string CurrentUser,vector <contact> Agenda, int &nr, string TargetTelefon);
#endif //PROIECT_PP_C___PRELUAREDATE_H
