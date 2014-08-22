#include "status.h"

int Status::currentID = 0;

void Status::generateID(){
    stringstream ss;
    ss << ++currentID;
    ID = "S_" + ss.str();
}
