#ifndef DATATYPE_H
#define DATATYPE_H

#include "stringobject.h"

class DataType : public StringObject
{
private:
    static int currentID;

public:
    DataType(string value) : StringObject(value)
    {

    }

    void generateID();

    static int getCurrentID(){
        return currentID;
    }

    static void setCurrentID(int currentIDVal){
        currentID = currentIDVal;
    }
};

#endif // DATATYPE_H
