#include "mcsystem.h"

MCSystem::MCSystem()
{
    dao = new DataAccessObject();

    dao->initializeTable();

    CollectionType *collectionType1 = new CollectionType("CD");
    collectionType1->generateID();
    CollectionType *collectionType2 = new CollectionType("DVD");
    collectionType2->generateID();
    CollectionType *collectionType3 = new CollectionType("Blue-ray");
    collectionType3->generateID();
    dao->addCollectionType(collectionType1);
    dao->addCollectionType(collectionType2);
    dao->addCollectionType(collectionType3);


    DataType *dataType1 = new DataType("IMAGES");
    dataType1->generateID();
    DataType *dataType2 = new DataType("AUDIO");
    dataType2->generateID();
    DataType *dataType3 = new DataType("VIDEO");
    dataType3->generateID();
    dao->addDataType(dataType1);
    dao->addDataType(dataType2);
    dao->addDataType(dataType3);


    Category *category1 = new Category("Engineering and Technology");
    category1->generateID();
    Category *category2 = new Category("History");
    category2->generateID();
    Category *category3 = new Category("Film and media studies");
    category3->generateID();
    Category *category4 = new Category("Psychology");
    category4->generateID();
    Category *category5 = new Category("Images");
    category5->generateID();
    Category *category6 = new Category("Photograph and maps");
    category6->generateID();
    Category *category7 = new Category("General");
    category7->generateID();
    Category *category8 = new Category("Business and Economics");
    category8->generateID();
    dao->addCategory(category1);
    dao->addCategory(category2);
    dao->addCategory(category3);
    dao->addCategory(category4);
    dao->addCategory(category5);
    dao->addCategory(category6);
    dao->addCategory(category7);
    dao->addCategory(category8);

    Status *status1 = new Status("STOREROOM");
    status1->generateID();
    Status *status2 = new Status("LIBRARY");
    status2->generateID();
    Status *status3 = new Status("BORROWED");
    status3->generateID();
    Status *status4 = new Status("LOST");
    status4->generateID();
    dao->addStatus(status1);
    dao->addStatus(status2);
    dao->addStatus(status3);
    dao->addStatus(status4);


    PersonType *personType1 = new PersonType("STUDENT");
    personType1->generateID();
    PersonType *personType2 = new PersonType("LECTURER");
    personType2->generateID();
    PersonType *personType3 = new PersonType("STAFF");
    personType3->generateID();
    dao->addPersontype(personType1);
    dao->addPersontype(personType2);
    dao->addPersontype(personType3);


    Department *department1 = new Department("IT");
    department1->generateID();
    Department *department2 = new Department("COMMERCE");
    department2->generateID();
    Department *department3 = new Department("PROFCOMM");
    department3->generateID();
    dao->addDepartment(department1);
    dao->addDepartment(department2);
    dao->addDepartment(department3);

    loadDataFromDB();

//    Borrower *borrower1 = new Borrower("Phuoc",getPersonType("","STUDENT")->getID(),getDepartment("","IT")->getID(),"0909343414");
//    borrower1->generateID();
//    Borrower *borrower2 = new Borrower("Thinh",getPersonType("","LECTURER")->getID(),getDepartment("","COMMERCE")->getID(),"01234567");
//    borrower2->generateID();
//    dao->addBorrower(borrower1);
//    dao->addBorrower(borrower2);


//    MultimediaCollection *mc1 = new MultimediaCollection(getCollectionType("","DVD")->getID(),getDataType("","VIDEO")->getID(),getCategory("","General")->getID(),"Title1","Version1","Publisher1",1992,180);
//    mc1->generateID();
//    MultimediaCollection *mc2 = new MultimediaCollection(getCollectionType("","CD")->getID(),getDataType("","IMAGES")->getID(),getCategory("","History")->getID(),"Title2","Version2","Publisher2",2000,240);
//    mc2->generateID();
//    dao->addMultimediaCollection(mc1);
//    dao->addMultimediaCollection(mc2);


//    MCInstance *mcIns1 = new MCInstance("MCI_1",getStatus("","STOREROOM")->getID(),"MC_1");
//    MCInstance *mcIns2 = new MCInstance("MCI_2",getStatus("","LIBRARY")->getID(), "MC_2");
//    dao->addMCInstance(mcIns1);
//    dao->addMCInstance(mcIns2);


//    loadDataFromDB();

//    cout<< "CurrentID: " << borrowers->at(1)->getCurrentID() << endl;
//    cout<< "CurrentID: " << borrowerDepartment->at(1)->getCurrentID() << endl;

}

void MCSystem::loadDataFromDB()
{
    collectionType = dao->getAllCollectionType();
    dataType = dao->getAllDataType();
    category = dao->getAllCategory();
    borrowingStatus = dao->getAllStatus();
    borrowerType = dao->getAllPersontype();
    borrowerDepartment = dao->getAllDepartment();
    borrowingRecord = dao->getAllBorrowingRecord();

//    cout << "size: " << borrowingRecord->size() << endl;
//    cout << "borrowing record " << borrowingRecord->at(0).first << endl;

    borrowers = dao->getAllBorrower();
    mc = dao->getAllMultimediaCollection();
    instances = dao->getAllMCInstance();

}

CollectionType* MCSystem::getCollectionType(string key,string value)
{
    CollectionType *temp;
    for(unsigned int i = 0; i < collectionType->size() ; i++)
    {
        if(key.compare(collectionType->at(i)->getID()) == 0 || value.compare(collectionType->at(i)->getName()) == 0)
        {
            temp = collectionType->at(i);
            break;
        }
    }

    return temp;
}

DataType* MCSystem::getDataType(string key, string value)
{
    DataType *temp;
    for(unsigned int i = 0; i < dataType->size() ; i++)
    {
        if(key.compare(dataType->at(i)->getID()) == 0 || value.compare(dataType->at(i)->getName()) == 0)
        {
            temp = dataType->at(i);
            break;
        }
    }

    return temp;
}

Category* MCSystem::getCategory(string key, string value)
{
    Category *temp;
    for(unsigned int i = 0; i < category->size() ; i++)
    {
        if(key.compare(category->at(i)->getID()) == 0 || value.compare(category->at(i)->getName()) == 0)
        {
            temp = category->at(i);
            break;
        }
    }

    return temp;
}

Status* MCSystem::getStatus(string key,string value)
{
    Status *temp;
    for(unsigned int i = 0; i < borrowingStatus->size() ; i++)
    {
        if(key.compare(borrowingStatus->at(i)->getID()) == 0 || value.compare(borrowingStatus->at(i)->getName()) == 0)
        {
            temp = borrowingStatus->at(i);
            break;
        }
    }

    return temp;
}

PersonType* MCSystem::getPersonType(string key,string value)
{
    PersonType *temp;
    for(unsigned int i = 0; i < borrowerType->size() ; i++)
    {
        if(key.compare(borrowerType->at(i)->getID()) == 0 || value.compare(borrowerType->at(i)->getName()) == 0)
        {
            temp = borrowerType->at(i);
            break;
        }
    }

    return temp;
}

Department* MCSystem::getDepartment(string key,string value)
{
    Department *temp;
    for(unsigned int i = 0; i < borrowerDepartment->size() ; i++)
    {
        if(key.compare(borrowerDepartment->at(i)->getID()) == 0 || value.compare(borrowerDepartment->at(i)->getName()) == 0)
        {
            temp = borrowerDepartment->at(i);
            break;
        }
    }

    return temp;
}

MCInstance* MCSystem::getInstance(string barcode)
{
    MCInstance *temp;
    for(unsigned int i = 0; i < instances->size(); i++)
    {
        if(barcode.compare(instances->at(i)->getBarcode()) == 0)
        {
            temp = instances->at(i);
            break;
        }
    }

    return temp;
}

Borrower* MCSystem::getBorrower(string id)
{
    Borrower *temp;
    for(unsigned int i = 0; i < borrowers->size(); i++)
    {
        if(id.compare(borrowers->at(i)->getID()) == 0)
        {
            temp = borrowers->at(i);
            break;
        }
    }

    return temp;
}

pair<string,string> MCSystem::getBorrowingRecord(string instanceBarcode, string borrowerID)
{
    pair<string,string> temp;
    for(unsigned int i = 0; i < borrowingRecord->size(); i++)
    {
        if(instanceBarcode.compare(borrowingRecord->at(i).first) == 0 || borrowerID.compare(borrowingRecord->at(i).second) == 0)
        {
            temp = borrowingRecord->at(i);
            break;
        }
    }
    return temp;
}

bool MCSystem::validateInstance(string barcode)
{
    bool valid = true;
    for(unsigned int i = 0; i < instances->size(); i++)
    {
        if(barcode.compare(instances->at(i)->getBarcode()) == 0)
        {
            valid = false;
            break;
        }
    }
    return valid;
}



void MCSystem::freeAll()
{
    for(unsigned int i = 0; i < mc->size(); i++)
    {
        delete mc->at(i);
    }
    delete mc;

    for(unsigned int i = 0; i < instances->size(); i++)
    {
        delete instances->at(i);
    }
    delete instances;

    for(unsigned int i = 0; i < borrowers->size(); i++)
    {
        delete borrowers->at(i);
    }
    delete borrowers;

    for(unsigned int i = 0; i < dataType->size(); i++)
    {
        delete dataType->at(i);
    }
    delete dataType;

    for(unsigned int i = 0; i < collectionType->size(); i++)
    {
        delete collectionType->at(i);
    }
    delete collectionType;

    for(unsigned int i = 0; i < category->size(); i++)
    {
        delete category->at(i);
    }
    delete category;

    for(unsigned int i = 0; i < borrowingStatus->size(); i++)
    {
        delete borrowingStatus->at(i);
    }
    delete borrowingStatus;

    for(unsigned int i = 0; i < borrowerType->size(); i++)
    {
        delete borrowerType->at(i);
    }
    delete borrowerType;

    for(unsigned int i = 0; i < borrowerDepartment->size(); i++)
    {
        delete borrowerDepartment->at(i);
    }
    delete borrowerDepartment;

    delete borrowingRecord;

    delete dao;

}

void MCSystem::addCollectionType(CollectionType *newOne)
{
    collectionType->push_back(newOne);
    dao->addCollectionType(newOne);
}

void MCSystem::updateCollectionType(CollectionType *newOne)
{
    deleteCollectionType(newOne->getID());

    collectionType->push_back(newOne);
    dao->updateCollectionType(newOne);
}

void MCSystem::deleteCollectionType(string id)
{
    for (unsigned int i = 0; i < collectionType->size(); i++)
    {
        if(id.compare(collectionType->at(i)->getID()) == 0)
        {
            delete collectionType->at(i);
            collectionType->erase(collectionType->begin() + i);
            break;
        }
    }
}

void MCSystem::addDataType(DataType *newOne)
{
    dataType->push_back(newOne);
    dao->addDataType(newOne);
}

void MCSystem::updateDataType(DataType *newOne)
{
    deleteDataType(newOne->getID());

    dataType->push_back(newOne);
    dao->updateDataType(newOne);
}

void MCSystem::deleteDataType(string id)
{
    for (unsigned int i = 0; i < dataType->size(); i++)
    {
        if(id.compare(dataType->at(i)->getID()) == 0)
        {
            delete dataType->at(i);
            dataType->erase(dataType->begin() + i);
            break;
        }
    }
}

void MCSystem::addCategory(Category *newOne)
{
    category->push_back(newOne);
    dao->addCategory(newOne);
}

void MCSystem::updateCategory(Category *newOne)
{
    deleteCategory(newOne->getID());

    category->push_back(newOne);
    dao->updateCategory(newOne);
}

void MCSystem::deleteCategory(string id)
{
    for (unsigned int i = 0; i < category->size(); i++)
    {
        if(id.compare(category->at(i)->getID()) == 0)
        {
            delete category->at(i);
            category->erase(category->begin() + i);
            break;
        }
    }
}

void MCSystem::addPersonType(PersonType *newOne)
{
    borrowerType->push_back(newOne);
    dao->addPersontype(newOne);
}

void MCSystem::updatePersonType(PersonType *newOne)
{
    deletePersonType(newOne->getID());

    borrowerType->push_back(newOne);
    dao->updatePersontype(newOne);
}

void MCSystem::deletePersonType(string id)
{
    for (unsigned int i = 0; i < borrowerType->size(); i++)
    {
        if(id.compare(borrowerType->at(i)->getID()) == 0)
        {
            delete borrowerType->at(i);
            borrowerType->erase(borrowerType->begin() + i);
            break;
        }
    }
}

void MCSystem::addDepartment(Department *newOne)
{
    borrowerDepartment->push_back(newOne);
    dao->addDepartment(newOne);
}

void MCSystem::updateDepartment(Department *newOne)
{
    deleteDepartment(newOne->getID());

    borrowerDepartment->push_back(newOne);
    dao->updateDepartment(newOne);
}

void MCSystem::deleteDepartment(string id)
{
    for (unsigned int i = 0; i < borrowerDepartment->size(); i++)
    {
        if(id.compare(borrowerDepartment->at(i)->getID()) == 0)
        {
            delete borrowerDepartment->at(i);
            borrowerDepartment->erase(borrowerDepartment->begin() + i);
            break;
        }
    }
}

void MCSystem::addStatus(Status *newOne)
{
    borrowingStatus->push_back(newOne);
    dao->addStatus(newOne);
}

void MCSystem::updateStatus(Status *newOne)
{
    deleteStatus(newOne->getID());

    borrowingStatus->push_back(newOne);
    dao->updateStatus(newOne);
}

void MCSystem::deleteStatus(string id)
{
    for (unsigned int i = 0; i < borrowingStatus->size(); i++)
    {
        if(id.compare(borrowingStatus->at(i)->getID()) == 0)
        {
            delete borrowingStatus->at(i);
            borrowingStatus->erase(borrowingStatus->begin() + i);
            break;
        }
    }
}


void MCSystem::addMC(MultimediaCollection *newOne)
{
    mc->push_back(newOne);
    dao->addMultimediaCollection(newOne);
}

void MCSystem::updateMC(MultimediaCollection *newOne)
{
    deleteMC(newOne->getID());

    mc->push_back(newOne);
    dao->updateMultimediaCollection(newOne);

}

void MCSystem::deleteMC(string id)
{

    for(unsigned int i = 0; i < mc->size(); i++)
    {
        if(id.compare(mc->at(i)->getID()) == 0)
        {
            delete mc->at(i);
            mc->erase(mc->begin() + i);
            break;
        }
    }
}

void MCSystem::addBorrower(Borrower *newOne)
{
    borrowers->push_back(newOne);
    dao->addBorrower(newOne);
}

void MCSystem::updateBorrower(Borrower *newOne)
{
    deleteBorrower(newOne->getID());

    borrowers->push_back(newOne);
    dao->updateBorrower(newOne);

}

void MCSystem::deleteBorrower(string id)
{

    for(unsigned int i = 0; i < borrowers->size(); i++)
    {
        if(id.compare(borrowers->at(i)->getID()) == 0)
        {
            delete borrowers->at(i);
            borrowers->erase(borrowers->begin() + i);
            break;
        }
    }

}


void MCSystem::addMCInstance(MCInstance *newOne)
{
    instances->push_back(newOne);
    dao->addMCInstance(newOne);
}

void MCSystem::updateMCInstance(QString oldbarcode, MCInstance *newOne)
{
    deleteMCInstance(newOne->getBarcode());

    instances->push_back(newOne);
    dao->updateMCInstance(oldbarcode.toStdString(),newOne);

}

void MCSystem::deleteMCInstance(string barcode)
{

    for(unsigned int i = 0; i < instances->size(); i++)
    {
        if(barcode.compare(instances->at(i)->getBarcode()) == 0)
        {
            delete instances->at(i);
            instances->erase(instances->begin() + i);
            break;
        }
    }
}

void MCSystem::deleteBorrowingRecord(string instanceBarcode, string borrowerID)
{

    for(unsigned int i = 0; i < borrowingRecord->size(); i++)
    {
        if(instanceBarcode.compare(borrowingRecord->at(i).first) == 0 || borrowerID.compare(borrowingRecord->at(i).second) == 0)
        {
            borrowingRecord->erase(borrowingRecord->begin() + i);
            break;
        }
    }
}

void MCSystem::borrowing(QString instanceBarcode, QString borrowerID, int borrowingDay)
{
    MCInstance *item = getInstance(instanceBarcode.toStdString());
    Borrower *borrower = getBorrower(borrowerID.toStdString());

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int month = ltm->tm_mon + 1;
    int day = ltm->tm_mday;
    int year = ltm->tm_year + 1900;

    stringstream ssMonth;
    ssMonth << month;
    stringstream ssDay;
    ssDay << day;
    stringstream ssYear;
    ssYear << year;

    string date = ssMonth.str() + "/" + ssDay.str() + "/" + ssYear.str();

    item->setBorrowedDate(date);
    item->setBorrowingDay(borrowingDay);
    item->setBorrowingTime(item->getBorrowingTime()+1);
    item->setStatus(getStatus("","BORROWED")->getID());

    borrower->setBorrowedItems(borrower->getBorrowedItems()+1);

    dao->updateMCInstance(instanceBarcode.toStdString(),item);
    dao->updateBorrower(borrower);

    pair<string,string> record = make_pair(instanceBarcode.toStdString(),borrowerID.toStdString());

    borrowingRecord->push_back(record);

    dao->addBorrowingRecord(instanceBarcode,borrowerID);
}

void MCSystem::returning(QString instanceBarcode, bool late)
{
    string borrowerID = getBorrowingRecord(instanceBarcode.toStdString(),"").second;

    MCInstance *item = getInstance(instanceBarcode.toStdString());
    Borrower *borrower = getBorrower(borrowerID);

    item->setBorrowedDate("");
    item->setBorrowingDay(0);
    item->setStatus(getStatus("","LIBRARY")->getID());

    if(late)
        borrower->setLateReturnedItems(borrower->getLateReturnedItems()+1);

    dao->updateMCInstance(instanceBarcode.toStdString(),item);
    dao->updateBorrower(borrower);

    deleteBorrowingRecord(instanceBarcode.toStdString(),borrowerID);

    dao->deleteBorrowingRecord(instanceBarcode,borrowerID.c_str());

}

int MCSystem::calculateDay(string date_start,string date_end){

    string temp;

    string month_start = date_start.substr(0,date_start.find_first_of('/'));
    temp = date_start.substr(date_start.find_first_of('/')+1,date_start.length()-1);
    string day_start = temp.substr(0,temp.find_first_of('/'));
    temp = temp.substr(temp.find_first_of('/')+1,temp.length()-1);
    string year_start = temp;

    string month_end = date_end.substr(0,date_end.find_first_of('/'));
    temp = date_end.substr(date_end.find_first_of('/')+1,date_end.length()-1);
    string day_end = temp.substr(0,temp.find_first_of('/'));
    temp = temp.substr(temp.find_first_of('/')+1,temp.length()-1);
    string year_end = temp;


    int i_year_start = stoi(year_start);
    int i_year_end = stoi(year_end);
    int i_month_start = stoi(month_start);
    int i_month_end = stoi(month_end);
    int i_day_start = stoi(day_start);
    int i_day_end = stoi(day_end);

    if(i_month_start > 12 || i_month_start < 1 || i_month_end > 12 || i_month_end < 1 || i_day_start < 0 || i_day_end < 0)
        return - 1;

    if(i_month_end == 1 || i_month_end == 3 || i_month_end == 5 || i_month_end == 7 || i_month_end == 8 || i_month_end == 10 || i_month_end == 12){
        if(i_day_end > 31)
            return -1;
    }
    else if(i_month_end == 2)
    {
        if(i_day_end > 28)
            return -1;
    }
    else
    {
        if(i_day_end > 30)
            return -1;
    }

    if(i_month_start == 1 || i_month_start == 3 || i_month_start == 5 || i_month_start == 7 || i_month_start == 8 || i_month_start == 10 || i_month_start == 12){
        if(i_day_start > 31)
            return -1;
    }
    else if(i_month_start == 2)
    {
        if(i_day_start > 28)
            return -1;
    }
    else
    {
        if(i_day_start > 30)
            return -1;
    }

    if(i_year_start > i_year_end)
        return -1;
    else if(i_year_start == i_year_end ){
        if(i_month_start >  i_month_end)
            return - 1;
        else if(i_month_start == i_month_end && i_day_start > i_day_end)
            return - 1;
    }

    int totalDay = 0;

    while(i_day_end != i_day_start || i_month_end != i_month_start || i_year_end != i_year_start)
    {
//        cout << i_month_end << "-" << i_day_end << "-" << i_year_end << endl;
        if(i_day_end == 1)
        {
            i_month_end--;

            if(i_month_end == 0)
            {
                i_month_end = 12;
                i_year_end--;
            }

            if(i_month_end == 1 || i_month_end == 3 || i_month_end == 5 || i_month_end == 7 || i_month_end == 8 || i_month_end == 10 || i_month_end == 12)
            {
                i_day_end = 31;
            }
            else if(i_month_end == 2)
            {
                i_day_end = 28;
            }
            else
                i_day_end = 30;
        }
        else
            i_day_end--;

        totalDay++;
    }

    return totalDay;
}


int MCSystem::isLate(string borrowing_date, int borrowingDay)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int month = ltm->tm_mon + 1;
    int day = ltm->tm_mday;
    int year = ltm->tm_year + 1900;

    stringstream ssMonth;
    ssMonth << month;
    stringstream ssDay;
    ssDay << day;
    stringstream ssYear;
    ssYear << year;

    string returning_date = ssMonth.str() + "/" + ssDay.str() + "/" + ssYear.str();
    int range = calculateDay(borrowing_date,returning_date);

    if(range > borrowingDay)
        return range - borrowingDay;
    else
        return 0;


}
