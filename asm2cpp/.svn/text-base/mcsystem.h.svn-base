#ifndef MCSYSTEM_H
#define MCSYSTEM_H

#include <vector>

#include "dataaccessobject.h"

class MCSystem
{
private:
    vector<MultimediaCollection*> *mc;
    vector<MCInstance*> *instances;
    vector<Borrower*> *borrowers;
    vector<DataType*> *dataType;
    vector<CollectionType*> *collectionType;
    vector<Category*> *category;
    vector<Status*> *borrowingStatus;
    vector<PersonType*> *borrowerType;
    vector<Department*> *borrowerDepartment;
    vector<pair<string,string>> *borrowingRecord;

    DataAccessObject *dao;

public:
    MCSystem();

    vector<MultimediaCollection*> * getVtMC(){
        return mc;
    }

    vector<MCInstance*> * getVtInstance(){
        return instances;
    }

    vector<Borrower*> * getVtBorrowers(){
        return borrowers;
    }

    DataAccessObject * getDAO(){
        return dao;
    }

    CollectionType *getCollectionType(string key,string value);

    DataType *getDataType(string key,string value);

    Category *getCategory(string key,string value);

    Status *getStatus(string key,string value);

    PersonType *getPersonType(string key,string value);

    Department *getDepartment(string key,string value);

    MCInstance *getInstance(string barcode);

    Borrower *getBorrower(string id);

    pair<string,string> getBorrowingRecord(string instanceBarcode, string borrowerID);

    vector<CollectionType*> *getVtCollectionType(){
        return collectionType;
    }

    vector<DataType*> *getVtDataType(){
        return dataType;
    }

    vector<Category*> *getVtCategory(){
        return category;
    }

    vector<Status*> *getVtStatus(){
        return borrowingStatus;
    }

    vector<PersonType*> *getVtPersonType(){
        return borrowerType;
    }

    vector<Department*> *getVtDepartment(){
        return borrowerDepartment;
    }

    void loadDataFromDB();

    //6 Tables
    //Collection
    void addCollectionType(CollectionType *newOne);

    void updateCollectionType(CollectionType *newOne);

    void deleteCollectionType(string id);

    //DataType
    void addDataType(DataType *newOne);

    void updateDataType(DataType *newOne);

    void deleteDataType(string id);

    //Category
    void addCategory(Category *newOne);

    void updateCategory(Category *newOne);

    void deleteCategory(string id);

    //PersonType
    void addPersonType(PersonType *newOne);

    void updatePersonType(PersonType *newOne);

    void deletePersonType(string id);

    //Department
    void addDepartment(Department *newOne);

    void updateDepartment(Department *newOne);

    void deleteDepartment(string id);

    //Status
    void addStatus(Status *newOne);

    void updateStatus(Status *newOne);

    void deleteStatus(string id);


    void addMC(MultimediaCollection *newOne);

    void updateMC(MultimediaCollection *newOne);

    void deleteMC(string id);

    void addBorrower(Borrower *newOne);

    void updateBorrower(Borrower *newOne);

    void deleteBorrower(string id);

    void addMCInstance(MCInstance *newOne);

    void updateMCInstance(QString oldbarcode,MCInstance *newOne);

    void deleteMCInstance(string id);

    void deleteBorrowingRecord(string instanceBarcode, string borrowerID);

    void borrowing(QString instanceBarcode, QString borrowerID, int borrowingDay);

    void returning(QString insanceBarcode, bool late);

    bool validateInstance(string barcode);

    int calculateDay(string date_start,string date_end);

    int isLate(string borrowing_date, int borrowingDay);

    void freeAll();


};

extern MCSystem *mc;

#endif // MCSYSTEM_H
