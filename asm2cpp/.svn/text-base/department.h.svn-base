#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "stringobject.h"

class Department : public StringObject
{
private:
    static int currentID;

public:
    Department(string value) : StringObject(value)
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

#endif // DEPARTMENT_H
