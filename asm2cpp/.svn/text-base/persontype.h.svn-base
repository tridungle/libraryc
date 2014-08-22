#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include "stringobject.h"

class PersonType : public StringObject
{
private:
    static int currentID;

public:
    PersonType(string value) : StringObject(value)
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

#endif // PERSONTYPE_H
