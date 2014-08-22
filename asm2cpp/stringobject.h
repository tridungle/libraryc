#ifndef STRINGOBJECT_H
#define STRINGOBJECT_H

#include <string>
#include <sstream>

using namespace std;

class StringObject
{
protected:
    string ID;
    string name;

public:
    StringObject(string nameVal) : name(nameVal) {}

    string getName(){
        return name;
    }

    void setName(string nameVal){
        name = nameVal;
    }

    string getID(){
        return ID;
    }

    void setID(string IDVal){
        ID = IDVal;
    }


};

#endif // STRINGOBJECT_H
