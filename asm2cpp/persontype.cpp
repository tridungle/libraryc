#include "persontype.h"

int PersonType::currentID = 0;

void PersonType::generateID(){
    stringstream ss;
    ss << ++currentID;
    ID = "PT_" + ss.str();
}
