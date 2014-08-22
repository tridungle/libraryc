#ifndef mcIDINSTANCE_H
#define mcIDINSTANCE_H

#include <ctime>

#include "multimediacollection.h"
#include "status.h"

class MCInstance
{
private:
    string barcode;
    string statusID;
    int borrowingTime;
    string borrowedDate;
    int borrowingDay;
    string mcID;

public:
    MCInstance(string barcodeVal, string statusIDVal, string mcIDVal)
        : barcode(barcodeVal), statusID(statusIDVal), mcID(mcIDVal)
    {
        borrowingTime = 0;
        borrowingDay = 0;
        borrowedDate = "";
    }

    string getBarcode(){
        return barcode;
    }

    void setBarcode(string barcodeVal){
        barcode = barcodeVal;
    }

    string getStatus(){
        return statusID;
    }

    void setStatus(string statusIDVal){
        statusID = statusIDVal;
    }

    int getBorrowingTime(){
        return borrowingTime;
    }

    void setBorrowingTime(int borrowingTimeVal){
        borrowingTime = borrowingTimeVal;
    }

    string getBorrowedDate(){
        return borrowedDate;
    }

    void setBorrowedDate(string borrowedDateVal){
        borrowedDate = borrowedDateVal;
    }

    int getBorrowingDay(){
        return borrowingDay;
    }

    void setBorrowingDay(int borrowingDayVal){
        borrowingDay = borrowingDayVal;
    }

    string getMCID(){
        return mcID;
    }

    void setMCID(string mcIDVal){
        mcID = mcIDVal;
    }

};

#endif // mcIDINSTANCE_H
