//
// Created by Stefan on 19.06.2022.
//

#ifndef PROIECT_PP_C___OPERATIIPEPERSOANE_H
#define PROIECT_PP_C___OPERATIIPEPERSOANE_H

#include <vector>
#include "contact.h"

void ModificarePersoane(int &nr, string CurrentUser, vector <contact> &Agenda);
void StergePersoana(int &nr, string CurrentUser, vector <contact> &Agenda);
void AdaugaPersoana(int &nr, string &CurrentUser, vector <contact> &Agenda);
#endif //PROIECT_PP_C___OPERATIIPEPERSOANE_H
