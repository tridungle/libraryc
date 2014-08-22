#ifndef DATAACCESSOBJECT_H
#define DATAACCESSOBJECT_H

#include <QtSql>
#include <QDebug>
#include <QFileInfo>

#include <iostream>
#include "mcinstance.h"
#include "borrower.h"

//Database name
static const string DATABASE_NAME = "multimediacollection.db";

//CRUD Operation
static const string INSERT = "insert";
static const string UPDATE = "update";
static const string READ = "read";
static const string REMOVE = "delete";
static const string SELECT_ALL = "select_all";

//Constant table variables
static const QString COLLECTIONTYPE_TABLE = "CollectionType";
static const QString DATATYPE_TABLE = "DataType";
static const QString CATEGORY_TABLE = "Category";
static const QString STATUS_TABLE = "Status";
static const QString PERSONTYPE_TABLE = "PersonType";
static const QString DEPARTMENT_TABLE = "Department";
static const QString BORROWER_TABLE = "Borrower";
static const QString MC_TABLE = "MultimediaCollection";
static const QString MCINSTANCE_TABLE = "MultimediaCollectionInstance";
static const QString BORROWINGRECORD_TABLE = "BorrowingRecord";


class DataAccessObject
{
    //Error message
    void executeQueryMessage(bool check, string type, string tableName);
    bool executeCreateTable(QSqlQuery qry,QString query, QString tableName);

    void addGenericType(StringObject *genertictype, QString tablename);
    void updateGenericType(StringObject *newOne, QString tableName);
    void deleteGenericType(string id, QString tableName);
    vector<StringObject*> *getAllGeneric(QString tableName);

    void freeVector(vector<StringObject*> *vt);

public:
    QSqlDatabase mydb;
    DataAccessObject();
    void initializeTable();
    void connectionOpen();
    QSqlQueryModel* getModel(const QString &query);

    //CollectionType
    void addCollectionType(StringObject *collectiontype);
    void updateCollectionType(StringObject *newOne);
    void deleteCollectionType(string id);
    vector<CollectionType*> *getAllCollectionType();

    //DataType
    void addDataType(StringObject *dataType);
    void updateDataType(StringObject *newOne);
    void deleteDataType(string id);
    vector<DataType*> *getAllDataType();

    //Category
    void addCategory(StringObject *category);
    void updateCategory(StringObject *newOne);
    void deleteCategory(string id);
    vector<Category*> *getAllCategory();

    //Status
    void addStatus(StringObject *status);
    void updateStatus(StringObject *newOne);
    void deleteStatus(string id);
    vector<Status*> *getAllStatus();

    //Persontype
    void addPersontype(StringObject *personType);
    void updatePersontype(StringObject *newOne);
    void deletePersontype(string id);
    vector<PersonType*> *getAllPersontype();

    //Department
    void addDepartment(StringObject *department);
    void updateDepartment(StringObject *newOne);
    void deleteDepartment(string id);
    vector<Department*> *getAllDepartment();

    //Borrower
    void addBorrower(Borrower *borrower);
    void updateBorrower(Borrower *newOne);
    void deleteBorrower(string ID);
    vector<Borrower*> *getAllBorrower();

    //Multimedia Collection
    void addMultimediaCollection(MultimediaCollection *mc);
    void updateMultimediaCollection(MultimediaCollection *newOne);
    void deleteMultimediaCollection(string ID);
    vector<MultimediaCollection*> *getAllMultimediaCollection();

    //Multimedia Collection Instance
    void addMCInstance(MCInstance *mcIns);
    void updateMCInstance(string ID, MCInstance *newOne);
    void deleteMCInstance(string ID);
    vector<MCInstance*> *getAllMCInstance();

//    Borrowing Record
    void addBorrowingRecord(QString mcInsBarcode, QString borrowerID);
    void deleteBorrowingRecord(QString mcInsBarcode, QString borrowerID);
    vector<pair<string,string>> *getAllBorrowingRecord();


};

#endif // DATAACCESSOBJECT_H
