#include "dataaccessobject.h"

DataAccessObject::DataAccessObject()
{

}

void DataAccessObject::connectionOpen()
{
    //Check if database can be opened
    if(mydb.open())
    {
        cout << "Database is opened. Access allowed\n";

    }else
    {
        cout << "ERROR: Cannot open database. System closed !";
        exit(1);
    }
}

QSqlQueryModel* DataAccessObject::getModel(const QString &query)
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    connectionOpen();

    QSqlQuery qry;
    qry.prepare(query);
    qry.exec();
    modal->setQuery(qry);
    mydb.close();
    return modal;
}

void DataAccessObject::initializeTable()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    QString database_name = DATABASE_NAME.c_str();
    mydb.setDatabaseName(database_name);

    connectionOpen();

    //Create database and tables
    QSqlQuery qry;
    QString currentid;
    QString currentdata;
    QString current_table;

    //Create collection type table
    currentid = "id";
    currentdata = "collectiontype";
    current_table="CREATE TABLE IF NOT EXISTS " + COLLECTIONTYPE_TABLE +
            "("+currentid+" VARCHAR(20) PRIMARY KEY, "+currentdata+" VARCHAR(100) );";
    executeCreateTable(qry,current_table,COLLECTIONTYPE_TABLE);

    //Create data type table
    currentid = "id";
    currentdata = "datatype";
    current_table="CREATE TABLE IF NOT EXISTS " + DATATYPE_TABLE +
            "("+currentid+" VARCHAR(20) PRIMARY KEY, "+currentdata+" VARCHAR(100) );";
    executeCreateTable(qry,current_table,DATATYPE_TABLE);

    //Create category table
    currentid = "id";
    currentdata = "category";
    current_table="CREATE TABLE IF NOT EXISTS " + CATEGORY_TABLE +
            "("+currentid+" VARCHAR(20) PRIMARY KEY, "+currentdata+" VARCHAR(100) );";
    executeCreateTable(qry,current_table,CATEGORY_TABLE);

    //Create status table
    currentid = "id";
    currentdata = "status";
    current_table="CREATE TABLE IF NOT EXISTS " + STATUS_TABLE +
            "("+currentid+" VARCHAR(20) PRIMARY KEY, "+currentdata+" VARCHAR(100) );";
    executeCreateTable(qry,current_table,STATUS_TABLE);

    //Create persontype table
    currentid = "id";
    currentdata = "persontype";
    current_table="CREATE TABLE IF NOT EXISTS " + PERSONTYPE_TABLE +
            "("+currentid+" VARCHAR(20) PRIMARY KEY, "+currentdata+" VARCHAR(100) );";
    executeCreateTable(qry,current_table,PERSONTYPE_TABLE);

    //Create department table
    currentid = "id";
    currentdata = "department";
    current_table="CREATE TABLE IF NOT EXISTS " + DEPARTMENT_TABLE +
            "("+currentid+" VARCHAR(20) PRIMARY KEY, "+currentdata+" VARCHAR(100) );";
    executeCreateTable(qry,current_table,DEPARTMENT_TABLE);

    //Create borrower table
    current_table = "CREATE TABLE IF NOT EXISTS " + BORROWER_TABLE
            + "(borrowerid VARCHAR(20) PRIMARY KEY, name VARCHAR(20), type VARCHAR(20), department VARCHAR(20), mobilenumber VARCHAR(20), borroweditems INT, latereturneditems INT );";
    executeCreateTable(qry,current_table,BORROWER_TABLE);

    //Create multimedia collection table
    current_table = "CREATE TABLE IF NOT EXISTS " + MC_TABLE
            + "(multimediacollectionid VARCHAR(20) PRIMARY KEY, type VARCHAR(20), datatype VARCHAR(20), category VARCHAR(20), title VARCHAR(20), version VARCHAR(20), publisher VARCHAR(20), recordedyear INT, duration INT );";
    executeCreateTable(qry,current_table, MC_TABLE);

    //Create multimedia collection instance table
    current_table = "CREATE TABLE IF NOT EXISTS " + MCINSTANCE_TABLE
            + "(barcode VARCHAR(20) PRIMARY KEY, status VARCHAR(20), borrowingtime INT, borroweddate VARCHAR(20), borrowingday INT, multimediacollectionid VARCHAR(20) );";
    executeCreateTable(qry,current_table, MCINSTANCE_TABLE );

    //Create borrowing record table
    current_table = "CREATE TABLE IF NOT EXISTS " + BORROWINGRECORD_TABLE
            + "( instancebarcode VARCHAR(20) , borrowerid VARCHAR(20) );";
    executeCreateTable(qry,current_table, BORROWINGRECORD_TABLE );


    mydb.close();
}

bool DataAccessObject::executeCreateTable(QSqlQuery qry, QString query, QString tableName)
{
    if(qry.exec(query))
    {
        cout << "CREATED/EXISTED TABLE " << tableName.toStdString() << " IN THE DATABASE\n";
        return true;
    }else{
        cout << "ERROR: CANNOT CREATE TABLE " << tableName.toStdString() << " IN THE DATABASE\n";
        return false;
        exit(1);
    }
}

//Display appropriate message to user
void DataAccessObject::executeQueryMessage(bool check, string type, string tableName)
{

    if(check)
    {
        if(type.compare(INSERT) == 0)
        {
            cout << "Inserted into " << tableName << " successfully";
        }else if(type.compare(UPDATE) == 0)
        {
            cout << "Updated into " << tableName << " successfully";
        }else if(type.compare(READ) == 0)
        {
            cout << "Read from " << tableName << " successfully";
        }else if(type.compare(REMOVE) == 0)
        {
            cout << "Delete from " << tableName << " successfully";
        }else if(type.compare(SELECT_ALL) == 0)
        {
            cout << "Select from " << tableName << " successfully";
        }

        cout << "\n";

    }else
    {
        cout << "Failed to perform SQL commands!" << "\n";
    }
}

//Generic add
void DataAccessObject::addGenericType(StringObject *genericType, QString tableName)
{
    connectionOpen();

    QString id = genericType->getID().c_str();
    QString name = genericType->getName().c_str();

    QString query;
    query = "insert into " +tableName+"(id,"+ tableName +") values('"+ id +"','"+ name +"')";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    executeQueryMessage(check,INSERT,tableName.toStdString());
    mydb.close();
}

void DataAccessObject::updateGenericType(StringObject *newOne, QString tableName)
{
    connectionOpen();

    QString name = newOne->getName().c_str();
    QString id = newOne->getID().c_str();

    QString query = "update " + tableName + " set " + tableName + "='"+ name+
            "' where id='" + id + "';";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    executeQueryMessage(check,UPDATE,tableName.toStdString());
    mydb.close();
}


void DataAccessObject::deleteGenericType(string id, QString tableName)
{
    connectionOpen();

    QString query = "delete from " + tableName +
            " where id='" + id.c_str() + "'";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    executeQueryMessage(check,REMOVE,tableName.toStdString());
    mydb.close();
}

vector<StringObject*> *DataAccessObject::getAllGeneric(QString tableName)
{
    vector<StringObject*> *vectorAll = new vector<StringObject*>();

    connectionOpen();

    QString query = "select * from " + tableName;

    QSqlQuery qry;
    bool check;
    if((check = qry.exec(query)))
    {
        while(qry.next())
        {
            StringObject *temp = new StringObject(qry.value(1).toString().toStdString());
            temp->setID(qry.value(0).toString().toStdString());
            vectorAll->push_back(temp);
        }
    }
    executeQueryMessage(check,SELECT_ALL,tableName.toStdString());
    mydb.close();
    return vectorAll;
}

void DataAccessObject::freeVector(vector<StringObject*> *vt)
{
    for(unsigned int i = 0; i < vt->size(); i++)
    {
        delete vt->at(i);
        vt->at(i) = NULL;
    }

    delete vt;
    vt = NULL;

}


/*
 *COLLECTION TYPE
*/
void DataAccessObject::addCollectionType(StringObject *collectionType)
{
    addGenericType(collectionType,COLLECTIONTYPE_TABLE);
}

void DataAccessObject::updateCollectionType(StringObject *newOne)
{
    updateGenericType(newOne,COLLECTIONTYPE_TABLE);
}

void DataAccessObject::deleteCollectionType(string id)
{
    deleteGenericType(id,COLLECTIONTYPE_TABLE);
}

vector<CollectionType*> *DataAccessObject::getAllCollectionType()
{
    vector<StringObject*> *tempgen = getAllGeneric(COLLECTIONTYPE_TABLE);
    vector<CollectionType*> *temp = new vector<CollectionType*>();

    string id;
    int currentID = 0;
    int tempID;


    for(unsigned int i = 0; i < tempgen->size(); i++)
    {
        CollectionType *te = new CollectionType(tempgen->at(i)->getName());
        id = tempgen->at(i)->getID();
        tempID = stoi(id.substr(id.find('_')+1,id.length()-1));
        te->setID(id);
        if (tempID > currentID)
            currentID = tempID;
        temp->push_back(te);
    }

     CollectionType::setCurrentID(currentID);

    freeVector(tempgen);

    return temp;
}

/*
 *DATA TYPE
*/
void DataAccessObject::addDataType(StringObject *dataType)
{
    addGenericType(dataType,DATATYPE_TABLE);
}

void DataAccessObject::updateDataType(StringObject *newOne)
{
    updateGenericType(newOne,DATATYPE_TABLE);
}

void DataAccessObject::deleteDataType(string id)
{
    deleteGenericType(id,DATATYPE_TABLE);
}

vector<DataType*> *DataAccessObject::getAllDataType()
{
    vector<StringObject*> *tempgen = getAllGeneric(DATATYPE_TABLE);
    vector<DataType*> *temp = new vector<DataType*>();

    string id;
    int currentID = 0;
    int tempID;

    for(unsigned int i = 0; i < tempgen->size(); i++)
    {
        DataType *te = new DataType(tempgen->at(i)->getName());
        id = tempgen->at(i)->getID();
        tempID = stoi(id.substr(id.find('_')+1,id.length()-1));
        te->setID(id);
        if (tempID > currentID)
            currentID = tempID;
        temp->push_back(te);
    }

    DataType::setCurrentID(currentID);

    freeVector(tempgen);

    return temp;
}

/*
 *CATEGORY_TABLE
 */

void DataAccessObject::addCategory(StringObject *category)
{
    addGenericType(category,CATEGORY_TABLE);
}

void DataAccessObject::updateCategory(StringObject *newOne)
{
    updateGenericType(newOne,CATEGORY_TABLE);
}

void DataAccessObject::deleteCategory(string id)
{
    deleteGenericType(id,CATEGORY_TABLE);
}

vector<Category*> *DataAccessObject::getAllCategory()
{
    vector<StringObject*> *tempgen = getAllGeneric(CATEGORY_TABLE);
    vector<Category*> *temp = new vector<Category*>();

    string id;
    int currentID = 0;
    int tempID;

    for(unsigned int i = 0; i < tempgen->size(); i++)
    {
        Category *te = new Category(tempgen->at(i)->getName());
        id = tempgen->at(i)->getID();
        tempID = stoi(id.substr(id.find('_')+1,id.length()-1));
        te->setID(id);
        if (tempID > currentID)
            currentID = tempID;
        temp->push_back(te);
    }

    Category::setCurrentID(currentID);

    freeVector(tempgen);

    return temp;
}

/*
 * STATUS_TABLE
 */

void DataAccessObject::addStatus(StringObject *status)
{
    addGenericType(status,STATUS_TABLE);
}

void DataAccessObject::updateStatus(StringObject *newOne)
{
    updateGenericType(newOne,STATUS_TABLE);
}

void DataAccessObject::deleteStatus(string id)
{
    deleteGenericType(id,STATUS_TABLE);
}

vector<Status*> *DataAccessObject::getAllStatus()
{
    vector<StringObject*> *tempgen = getAllGeneric(STATUS_TABLE);
    vector<Status*> *temp = new vector<Status*>();

    string id;
    int currentID = 0;
    int tempID;

    for(unsigned int i = 0; i < tempgen->size(); i++)
    {
        Status *te = new Status(tempgen->at(i)->getName());
        id = tempgen->at(i)->getID();
        tempID = stoi(id.substr(id.find('_')+1,id.length()-1));
        te->setID(id);
        if (tempID > currentID)
            currentID = tempID;
        temp->push_back(te);
    }

    Status::setCurrentID(currentID);

    freeVector(tempgen);

    return temp;
}

/*
 *PERSONTYPE_TABLE
 */

void DataAccessObject::addPersontype(StringObject *personType)
{
    addGenericType(personType,PERSONTYPE_TABLE);
}

void DataAccessObject::updatePersontype(StringObject *newOne)
{
    updateGenericType(newOne,PERSONTYPE_TABLE);
}

void DataAccessObject::deletePersontype(string id)
{
    deleteGenericType(id,PERSONTYPE_TABLE);
}

vector<PersonType*> *DataAccessObject::getAllPersontype()
{
    vector<StringObject*> *tempgen = getAllGeneric(PERSONTYPE_TABLE);
    vector<PersonType*> *temp = new vector<PersonType*>();

    string id;
    int currentID = 0;
    int tempID;


    for(unsigned int i = 0; i < tempgen->size(); i++)
    {
        PersonType *te = new PersonType(tempgen->at(i)->getName());
        id = tempgen->at(i)->getID();
        tempID = stoi(id.substr(id.find('_')+1,id.length()-1));
        te->setID(id);
        if (tempID > currentID)
            currentID = tempID;
        temp->push_back(te);
    }

    PersonType::setCurrentID(currentID);

    freeVector(tempgen);

    return temp;
}

/*
 *DEPARTMENT_TABLE
 */

void DataAccessObject::addDepartment(StringObject *department)
{
    addGenericType(department,DEPARTMENT_TABLE);
}

void DataAccessObject::updateDepartment(StringObject *newOne)
{
    updateGenericType(newOne,DEPARTMENT_TABLE);
}

void DataAccessObject::deleteDepartment(string id)
{
    deleteGenericType(id,DEPARTMENT_TABLE);
}

vector<Department*> *DataAccessObject::getAllDepartment()
{
    vector<StringObject*> *tempgen = getAllGeneric(DEPARTMENT_TABLE);
    vector<Department*> *temp = new vector<Department*>();

    string id;
    int currentID = 0;
    int tempID;

    for(unsigned int i = 0; i < tempgen->size(); i++)
    {
        Department *te = new Department(tempgen->at(i)->getName());
        id = tempgen->at(i)->getID();
        tempID = stoi(id.substr(id.find('_')+1,id.length()-1));
        te->setID(id);
        if (tempID > currentID)
            currentID = tempID;
        temp->push_back(te);
    }

    Department::setCurrentID(currentID);;

    freeVector(tempgen);

    return temp;
}

/*
 *BORROWER_TABLE
 */

void DataAccessObject::addBorrower(Borrower *borrower)
{
    connectionOpen();

    QString borrowerID = borrower->getID().c_str();
    QString borrowerName = borrower->getName().c_str();
    QString borrowerType = borrower->getBorrowerTypeID().c_str();
    QString borrowerDepartment = borrower->getBorrowerDepartmentID().c_str();
    QString borrowerMobileNumber = borrower->getMobielNumber().c_str();
    QString borrowerBorrowedItems = QString::number(borrower->getBorrowedItems());
    QString borrowerLateReturnedItems = QString::number(borrower->getLateReturnedItems());

    QString query;
    query = "insert into "+ BORROWER_TABLE
            +"(borrowerid,name,type,department,mobilenumber,borroweditems,latereturneditems) values('"+ borrowerID +"','"+ borrowerName +"','"+ borrowerType +"','"+ borrowerDepartment +"','"+ borrowerMobileNumber +"',"+ borrowerBorrowedItems +","+ borrowerLateReturnedItems +")";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    executeQueryMessage(check,INSERT,BORROWER_TABLE.toStdString());
    mydb.close();
}

void DataAccessObject::updateBorrower(Borrower *newOne)
{
    connectionOpen();

    QString borrowerID = newOne->getID().c_str();
    QString borrowerName = newOne->getName().c_str();
    QString borrowerType = newOne->getBorrowerTypeID().c_str();
    QString borrowerDepartment = newOne->getBorrowerDepartmentID().c_str();
    QString borrowerMobileNumber = newOne->getMobielNumber().c_str();
    QString borrowerBorrowedItems = QString::number(newOne->getBorrowedItems());
    QString borrowerLateReturnedItems = QString::number(newOne->getLateReturnedItems());

    QString query;
    query = "update "+ BORROWER_TABLE
            +" set name = '" + borrowerName
            +"',type='"+ borrowerType
            +"',department='"+ borrowerDepartment
            +"',mobilenumber='"+ borrowerMobileNumber
            +"',borroweditems="+ borrowerBorrowedItems
            +",latereturneditems="+ borrowerLateReturnedItems
            +" where borrowerid='"+ borrowerID +"';" ;

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    executeQueryMessage(check,UPDATE,BORROWER_TABLE.toStdString());
    mydb.close();
}

void DataAccessObject::deleteBorrower(string ID)
{
    connectionOpen();

    QString query = "delete from " + BORROWER_TABLE +
            " where borrowerid='" + ID.c_str() + "'";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    cout << query.toStdString() << endl;
    executeQueryMessage(check,REMOVE,BORROWER_TABLE.toStdString());
    mydb.close();
}

vector<Borrower*> *DataAccessObject::getAllBorrower()
{
    vector<Borrower*> *vectorAll = new vector<Borrower*>();

    connectionOpen();

    QString query = "select * from " + BORROWER_TABLE;

    QSqlQuery qry;
    bool check;

    int tempID;
    int currentID = 0;

    string borrowerID;
    string borrowerName;
    string borrowerType;
    string borrowerDepartment;
    string borrowerMobileNumber;
    int borrowerBorrowedItems;
    int borrowerReturnedItems;
    if((check = qry.exec(query)))
    {
        while(qry.next())
        {
            borrowerID = qry.value(0).toString().toStdString();
            tempID = stoi(borrowerID.substr(borrowerID.find('_')+1,borrowerID.length()-1));
            if (tempID > currentID)
                currentID = tempID;
            borrowerName = qry.value(1).toString().toStdString();
            borrowerType = qry.value(2).toString().toStdString();
            borrowerDepartment = qry.value(3).toString().toStdString();
            borrowerMobileNumber = qry.value(4).toString().toStdString();
            borrowerBorrowedItems = qry.value(5).toInt();
            borrowerReturnedItems = qry.value(6).toInt();
            Borrower *temp = new Borrower(borrowerName,borrowerType,borrowerDepartment,borrowerMobileNumber);
            temp->setID(borrowerID);
            temp->setBorrowedItems(borrowerBorrowedItems);
            temp->setLateReturnedItems(borrowerReturnedItems);
            vectorAll->push_back(temp);
        }
    }
    Borrower::setCurrentID(currentID);
    executeQueryMessage(check,SELECT_ALL,BORROWER_TABLE.toStdString());
    mydb.close();
    return vectorAll;
}

/*
 *MC_TABLE
 */

void DataAccessObject::addMultimediaCollection(MultimediaCollection *mc)
{
    connectionOpen();

    QString mcID = mc->getID().c_str();
    QString mcType = mc->getCollectionTypeID().c_str();
    QString mcDataType = mc->getDataTypeID().c_str();
    QString mcCategory = mc->getCategoryID().c_str();
    QString mcTitle = mc->getTitle().c_str();
    QString mcVersion = mc->getVersion().c_str();
    QString mcPublisher = mc->getPublisher().c_str();
    QString mcRecordedYear = QString::number(mc->getRecorededYear());
    QString mcDuration = QString::number(mc->getDuration());

    QString query;
    query = "insert into "+ MC_TABLE
            +"(multimediacollectionid,type,datatype,category,title,version,publisher,recordedyear,duration) values('"+ mcID +"','"+ mcType +"','"+ mcDataType +"','"+ mcCategory +"','"+ mcTitle +"','"+ mcVersion +"','"+ mcPublisher +"',"+ mcRecordedYear+ ","+ mcDuration+")";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    executeQueryMessage(check,INSERT,MC_TABLE.toStdString());
    mydb.close();
}

void DataAccessObject::updateMultimediaCollection(MultimediaCollection *newOne)
{
    connectionOpen();

    QString mcID = newOne->getID().c_str();
    QString mcType = newOne->getCollectionTypeID().c_str();
    QString mcDataType = newOne->getDataTypeID().c_str();
    QString mcCategory = newOne->getCategoryID().c_str();
    QString mcTitle = newOne->getTitle().c_str();
    QString mcVersion = newOne->getVersion().c_str();
    QString mcPublisher = newOne->getPublisher().c_str();
    QString mcRecordedYear = QString::number(newOne->getRecorededYear());
    QString mcDuration = QString::number(newOne->getDuration());

    QString query;
    query = "update "+ MC_TABLE
            +" set type ='" + mcType
            +"',datatype='"+ mcDataType
            +"',category='"+ mcCategory
            +"',title='"+ mcTitle
            +"',version='"+ mcVersion
            +"',publisher='"+ mcPublisher
            +"',recordedyear='"+ mcRecordedYear
            +"',duration='"+ mcDuration
            +"' where multimediacollectionid='"+ mcID +"';" ;

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    executeQueryMessage(check,UPDATE,MC_TABLE.toStdString());
    mydb.close();
}

void DataAccessObject::deleteMultimediaCollection(string ID)
{
    connectionOpen();

    QString query = "delete from " + MC_TABLE +
            " where multimediacollectionid='" + ID.c_str() + "'";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    executeQueryMessage(check,REMOVE,MC_TABLE.toStdString());
    mydb.close();
}

vector<MultimediaCollection*> *DataAccessObject::getAllMultimediaCollection()
{
    vector<MultimediaCollection*> *vectorAll = new vector<MultimediaCollection*>();

    connectionOpen();

    QString query = "select * from " + MC_TABLE;

    QSqlQuery qry;
    bool check;

    int tempID;
    int currentID = 0;

    string mcID;
    string mcType;
    string mcDataType;
    string mcCategory;
    string mcTitle;
    string mcVersion;
    string mcPublisher;
    int mcRecordedYear;
    int mcDuration;

    if((check = qry.exec(query)))
    {
        while(qry.next())
        {
            mcID = qry.value(0).toString().toStdString();
            tempID = stoi(mcID.substr(mcID.find('_')+1,mcID.length()-1));
            if (tempID > currentID)
                currentID = tempID;
            mcType = qry.value(1).toString().toStdString();
            mcDataType = qry.value(2).toString().toStdString();
            mcCategory = qry.value(3).toString().toStdString();
            mcTitle = qry.value(4).toString().toStdString();
            mcVersion = qry.value(5).toString().toStdString();
            mcPublisher = qry.value(6).toString().toStdString();
            mcRecordedYear = qry.value(7).toInt();
            mcDuration = qry.value(8).toInt();
            MultimediaCollection *temp = new MultimediaCollection(mcType,mcDataType,mcCategory,mcTitle,mcVersion,mcPublisher,mcRecordedYear,mcDuration);
            temp->setID(mcID);
            vectorAll->push_back(temp);
        }
    }
    MultimediaCollection::setCurrentID(currentID);
    executeQueryMessage(check,SELECT_ALL,MC_TABLE.toStdString());
    mydb.close();
    return vectorAll;
}

/*
 *MCINSTANCE_TABLE
 */

void DataAccessObject::addMCInstance(MCInstance *mcIns)
{
    connectionOpen();

    QString mcInsBarcode = mcIns->getBarcode().c_str();
    QString mcInsStatus = mcIns->getStatus().c_str();
    QString mcInsBorrowingTime = QString::number(mcIns->getBorrowingTime());
    QString mcInsBorrowedDate = mcIns->getBorrowedDate().c_str();
    QString mcInsBorrowingDay = QString::number(mcIns->getBorrowingDay());
    QString mcInsMC = mcIns->getMCID().c_str();

    QString query;
    query = "insert into "+ MCINSTANCE_TABLE
            +"(barcode,status,borrowingtime,borroweddate,borrowingday,multimediacollectionid) values('"+ mcInsBarcode +"','"+ mcInsStatus +"',"+ mcInsBorrowingTime +",'"+ mcInsBorrowedDate +"',"+ mcInsBorrowingDay +",'"+ mcInsMC +"')";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    cout<<query.toStdString()<<endl;
    executeQueryMessage(check,INSERT,MCINSTANCE_TABLE.toStdString());
    mydb.close();
}

void DataAccessObject::updateMCInstance(string oldbarcode,MCInstance *newOne)
{
    connectionOpen();

    QString mcInsBarcode = newOne->getBarcode().c_str();
    QString mcInsStatus = newOne->getStatus().c_str();
    QString mcInsBorrowingTime = QString::number(newOne->getBorrowingTime());
    QString mcInsBorrowedDate = newOne->getBorrowedDate().c_str();
    QString mcInsBorrowingDay = QString::number(newOne->getBorrowingDay());
    QString mcInsMC = newOne->getMCID().c_str();

    QString query;
    query = "update "+ MCINSTANCE_TABLE
            +" set barcode='"+ mcInsBarcode
            +"',status='"+ mcInsStatus
            +"',borrowingtime='"+ mcInsBorrowingTime
            +"',borroweddate='"+ mcInsBorrowedDate
            +"',borrowingday='"+ mcInsBorrowingDay
            +"',multimediacollectionid='"+ mcInsMC
            +"' where barcode='"+ oldbarcode.c_str() +"';" ;

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    cout << query.toStdString() << endl;
    executeQueryMessage(check,UPDATE,MCINSTANCE_TABLE.toStdString());
    mydb.close();
}

void DataAccessObject::deleteMCInstance(string ID)
{
    connectionOpen();

    QString query = "delete from " + MCINSTANCE_TABLE +
            " where Barcode='" + ID.c_str() + "'";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    executeQueryMessage(check,REMOVE,MCINSTANCE_TABLE.toStdString());
    mydb.close();
}


vector<MCInstance*> *DataAccessObject::getAllMCInstance()
{
    vector<MCInstance*> *vectorAll = new vector<MCInstance*>();

    connectionOpen();

    QString query = "select * from " + MCINSTANCE_TABLE;


    QSqlQuery qry;
    bool check;

    string mcInsBarcode;
    string mcInsStatus;
    int mcInsBorrowingTime;
    string mcInsBorrowedDate;
    int mcInsBorrowingDay;
    string mcInsMC;

    if((check = qry.exec(query)))
    {
        while(qry.next())
        {
            mcInsBarcode = qry.value(0).toString().toStdString();
            mcInsStatus = qry.value(1).toString().toStdString();
            mcInsBorrowingTime = qry.value(2).toString().toInt();
            mcInsBorrowedDate = qry.value(3).toString().toStdString();
            mcInsBorrowingDay = qry.value(4).toString().toInt();
            mcInsMC = qry.value(5).toString().toStdString();
            MCInstance *temp = new MCInstance(mcInsBarcode,mcInsStatus,mcInsMC);
            temp->setBorrowingDay(mcInsBorrowingDay);
            temp->setBorrowingTime(mcInsBorrowingTime);
            temp->setBorrowedDate(mcInsBorrowedDate);
            vectorAll->push_back(temp);
        }
    }
    executeQueryMessage(check,SELECT_ALL,MCINSTANCE_TABLE.toStdString());
    mydb.close();
    return vectorAll;
}


/*
 *MCINSTANCE_TABLE
 */

void DataAccessObject::addBorrowingRecord(QString mcInsBarcode, QString borrowerID)
{
    connectionOpen();

    QString query;
    query = "insert into "+ BORROWINGRECORD_TABLE
            +"(instancebarcode,borrowerid) values('"+ mcInsBarcode +"','"+ borrowerID +"')";

    QSqlQuery qry;
    bool check;

    check = qry.exec(query);
    cout<<query.toStdString()<<endl;
    executeQueryMessage(check,INSERT,BORROWINGRECORD_TABLE.toStdString());

    mydb.close();
}

void DataAccessObject::deleteBorrowingRecord(QString mcInsBarcode, QString borrowerID)
{
    connectionOpen();

    QString query = "delete from " + BORROWINGRECORD_TABLE +
            " where instancebarcode='" + mcInsBarcode + "' AND borrowerid='" + borrowerID +"'";

    QSqlQuery qry;
    bool check;
    check = qry.exec(query);
    cout << query.toStdString() << endl;
    executeQueryMessage(check,REMOVE,BORROWINGRECORD_TABLE.toStdString());
    mydb.close();
}

 vector<pair<string,string>>* DataAccessObject::getAllBorrowingRecord()
{
    vector<pair<string,string>> *vectorAll = new vector<pair<string,string>>();

    connectionOpen();

    QString query = "select * from " + BORROWINGRECORD_TABLE;

    QSqlQuery qry;
    bool check;

    string insBarcode;
    string borrowerID;

    if((check = qry.exec(query)))
    {
        while(qry.next())
        {
            insBarcode = qry.value(0).toString().toStdString();
            borrowerID = qry.value(1).toString().toStdString();
            pair<string,string> record = make_pair(insBarcode,borrowerID);

            vectorAll->push_back(record);
        }
    }
    executeQueryMessage(check,SELECT_ALL,BORROWINGRECORD_TABLE.toStdString());
    mydb.close();
    return vectorAll;
}
