#include "OperatiiBaza.h"
#include "contact.h"
#include "superUser.h"
#include <vector>
using namespace std;
int main() {
//    system("color %");
    vector <contact> Agenda;
    superUser superUser;
    AfiseazaMeniu(Agenda, superUser);

    return 0;
}



