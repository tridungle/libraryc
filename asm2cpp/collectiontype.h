#ifndef COLLECTIONTYPE_H
#define COLLECTIONTYPE_H

#include "stringobject.h"

class CollectionType : public StringObject
{
private:
    static int currentID;

public:
    CollectionType(string value) : StringObject(value)
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

#endif // COLLECTIONTYPE_H
