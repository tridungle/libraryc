#include "original.h"
#include <QApplication>
#include "mcsystem.h"


MCSystem *mc;
using namespace std;

//void createNewCollection()
//{
//    stringstream ss;
//    mc->getDAO()->connectionOpen();

//    string itype;
//    string idatatype;
//    string ititle;
//    string iversion;
//    string ipublisher;
//    string irecordedYear;
//    int nrecordedYear;
//    string iduration;
//    int nduration;
//    string icategory;

//    cout << "\n========CREATING NEW COLLECTION========\n\n";
//    cout << "Entering new type: ";
//    cin >> itype;

//    CollectionType *ct = new CollectionType(itype);
//    mc->getDAO()->addCollectionType(ct);

//    cout << "Entering new datatype: ";
//    cin >> idatatype;

//    DataType *dt = new DataType(itype);
//    mc->getDAO()->addDataType(dt);

//    cout << "Entering new title: ";
//    cin >> ititle;

//    cout << "Entering new version: ";
//    cin >> iversion;

//    cout << "Entering new publisher: ";
//    cin >> ipublisher;

//    cout << "Entering new recordedYear: ";
//    cin >> irecordedYear;
//    ss << irecordedYear;
//    ss >> nrecordedYear;

//    cout << "Entering new duration(in sec): ";
//    cin >> iduration;
//    ss << iduration;
//    ss >> nduration;

//    cout << "Entering category: ";
//    cin >> icategory;

//    Category *cate = new Category(icategory);
//    mc->getDAO()->addCategory(cate);

//    mc->loadDataFromDB();
//    MultimediaCollection *mc1 = new MultimediaCollection(mc->getCollectionType(itype),mc->getDataType(idatatype),mc->getCategory(icategory),
//                                                              ititle,iversion,ipublisher,nrecordedYear,nduration);
//    mc->getDAO()->addMultimediaCollection(mc1);
//    cout << "\n\n\n";
//}

//void createNewBorrower()
//{
//    stringstream ss;
//    mc->getDAO()->connectionOpen();

//    string borrowerName;
//    string borrowerType;
//    string borrowerDepartment;
//    string borrowerMobileNumber;

//    cout << "\n========CREATING NEW BORROWER========\n\n";
//    cout << "Entering new borrower name: ";
//    cin >> borrowerName;

//    cout << "Entering new borrower type: ";
//    cin >> borrowerType;

//    PersonType *pt = new PersonType(borrowerType);
//    mc->getDAO()->addPersontype(pt);

//    cout << "Entering new borrower department: ";
//    cin >> borrowerDepartment;

//    Department *d = new Department(borrowerDepartment);
//    mc->getDAO()->addDepartment(d);

//    cout << "Entering new borrower mobile number: ";
//    cin >> borrowerMobileNumber;

//    mc->loadDataFromDB();
//    Borrower *borrower1 = new Borrower(borrowerName,mc->getPersonType(borrowerType),mc->getDepartment(borrowerDepartment),borrowerMobileNumber);
//    mc->getDAO()->addBorrower(borrower1);
//    cout << "\n\n\n";
//}

//void createNewInstance()
//{
//    stringstream ss;
//    mc->getDAO()->connectionOpen();

//    string mcInsBarcode;
//    string mcInsStatus;
//    string mcInsBorrowedDate;
//    string mcInsMCID;

//    int numberOfCopies = 0;

//    cout << "\n========CREATING NEW MC COPY========\n\n";

//    cout << "Entering new mc copy status: ";
//    cin >> mcInsStatus;

//    Status *s = new Status(mcInsStatus);
//    mc->getDAO()->addStatus(s);

//    cout << "Entering new mc copy borrowed date: ";
//    cin >> mcInsBorrowedDate;

//    cout << "Entering multimedia collection id: ";
//    cin >> mcInsMCID;

//    cout << "Entering number of copies: ";
//    cin >> numberOfCopies;

//    int count = 1;

//    mc->loadDataFromDB();
//    while(numberOfCopies > 0)
//    {
//        cout << "Copy number " << count++ << endl;
//        cout << "Entering new mc copy barcode: ";
//        cin >> mcInsBarcode;

//        MCInstance *mcIns = new MCInstance(mcInsBarcode,mc->getStatus(mcInsStatus),mcInsBorrowedDate,mcInsMCID);
//        mc->getDAO()->addMCInstance(mcIns);
//        numberOfCopies--;
//        delete mcIns;
//    }

//    cout << "\n\n\n";
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mc = new MCSystem();
    Original o;
    o.show();

    a.exec();
    mc->freeAll();
    delete mc;
    return 0;
}
