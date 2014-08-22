#ifndef CATEGORY_H
#define CATEGORY_H

#include "stringobject.h"

class Category : public StringObject
{
private:
    static int currentID;

public:
    Category(string value) : StringObject(value)
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

#endif // CATEGORY_H
