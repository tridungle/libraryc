#ifndef STATUS_H
#define STATUS_H

#include "stringobject.h"

class Status : public StringObject
{
private:
    static int currentID;

public:
    Status(string value) : StringObject(value)
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

#endif // STATUS_H
