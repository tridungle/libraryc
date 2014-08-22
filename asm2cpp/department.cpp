#include "department.h"

int Department::currentID = 0;

void Department::generateID(){
    stringstream ss;
    ss << ++currentID;
    ID = "D_" + ss.str();
}
