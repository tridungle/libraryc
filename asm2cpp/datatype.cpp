#include "datatype.h"

int DataType::currentID = 0;

void DataType::generateID(){
    stringstream ss;
    ss << ++currentID;
    ID = "DT_" + ss.str();
}
