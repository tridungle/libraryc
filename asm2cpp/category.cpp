#include "category.h"

int Category::currentID = 0;

void Category::generateID(){
    stringstream ss;
    ss << ++currentID;
    ID = "C_" + ss.str();
}
