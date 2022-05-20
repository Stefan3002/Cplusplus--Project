#include <iostream>
#include "OperatiiBaza.h"
#include "contact.h"
#include <string>
#include <fstream>
#include <vector>
#define NMAX 70
using namespace std;



int main() {
//    string PATH = "contacts.txt";
//    ifstream intrare(PATH);
//    int nrtotal = 0;

//    while(intrare>>PATH) {
////            printf("Nu s-a gasit fisierul.\n");
//        printf("Introduceti adresa fisierului.\n");
//        scanf("%s", PATH);
//        if (PATH[strlen(PATH) - 1] == '\n')
//            PATH[strlen(PATH) - 1] = '\0';
//        fname = fopen(PATH, "r");
//    }

//    string line;
//    while(intrare>>line)
//        nrtotal++;
//    fclose(fname);
//    printf("======%d=====", *nr);

//    printf("%d",nrtotal);

//    struct contact Agenda[nrtotal];
    vector <contact> Agenda;
    AfiseazaMeniu(Agenda);

    return 0;
}
