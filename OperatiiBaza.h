//
// Created by Stefan on 20.05.2022.
//

#ifndef PROIECT_PP_C___OPERATIIBAZA_H
#define PROIECT_PP_C___OPERATIIBAZA_H

#include <vector>
#include "contact.h"
#include "superUser.h"

void StergePersoana();
void AdaugaPersoana();
int ScrieOptiuni(int cuIntampinare, vector <contact> &Agenda);
void AfiseazaMeniu(vector <contact> &Agenda, superUser& superUser);
void citireDateUtilizator(string &Nume, string &Prenume, string &Mail, string &NrTelefon, string &Eticheta, string &Fav);
#endif //PROIECT_PP_C___OPERATIIBAZA_H
