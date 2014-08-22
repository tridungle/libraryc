#ifndef BORROWER_H
#define BORROWER_H

#include "persontype.h"
#include "department.h"

using namespace std;

class Borrower
{
private:
    static int currentID;
    string ID;
    string name;
    string borrowerTypeID;
    string borrowerDepartmentID;
    string mobileNumber;
    int borrowedItems;
    int lateReturnedItems;

public:
    Borrower(string nameVal,string borrowerTypeIDVal, string borrowerDepartmentIDVal, string mobileNumberVal)
        : name(nameVal), borrowerTypeID(borrowerTypeIDVal), borrowerDepartmentID(borrowerDepartmentIDVal) ,mobileNumber(mobileNumberVal)

    {
        borrowedItems = 0;
        lateReturnedItems = 0;
    }

//    static int getCurrentID(){
//        return currentID;
//    }
    void generateID();

    static void setCurrentID(int currentIDVal){
        currentID = currentIDVal;
    }

    static int getCurrentID()
    {
        return currentID;
    }

    string getID(){
        return ID;
    }

    void setID(string IDVal){
        ID = IDVal;
    }

    string getName(){
        return name;
    }

    void setName(string nameVal){
        name = nameVal;
    }

    string getBorrowerTypeID(){
        return borrowerTypeID;
    }

    void setBorrowerTypeID(string borrowerTypeIDVal){
        borrowerTypeID = borrowerTypeIDVal;
    }

    string getBorrowerDepartmentID(){
        return borrowerDepartmentID;
    }

    void setBorrowerDepartmentID(string borrowerDepartmentIDVal){
        borrowerDepartmentID = borrowerDepartmentIDVal;
    }

    string getMobielNumber(){
        return mobileNumber;
    }

    void setMobileNumber(string mobileNumberVal){
        mobileNumber = mobileNumberVal;
    }

    int getBorrowedItems(){
        return borrowedItems;
    }

    void setBorrowedItems(int borrowedItemsVal){
        borrowedItems = borrowedItemsVal;
    }

    int getLateReturnedItems(){
        return lateReturnedItems;
    }

    void setLateReturnedItems(int lateReturnedItemsVal){
        lateReturnedItems = lateReturnedItemsVal;
    }

};

#endif // BORROWER_H
