#include "original.h"


Original::Original(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Original)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->tbMC->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbMC->horizontalHeader()->setStretchLastSection(true);
    ui->tbMC->resizeColumnsToContents();

    ui->tbIns->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbIns->horizontalHeader()->setStretchLastSection(true);
    ui->tbIns->resizeColumnsToContents();

    ui->tbBorrower->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbBorrower->horizontalHeader()->setStretchLastSection(true);
    ui->tbBorrower->resizeColumnsToContents();

    ui->tbOperationInstance->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbOperationInstance->horizontalHeader()->setStretchLastSection(true);
    ui->tbOperationInstance->resizeColumnsToContents();

    ui->tbOperationBorrower->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbOperationBorrower->horizontalHeader()->setStretchLastSection(true);
    ui->tbOperationBorrower->resizeColumnsToContents();

    ui->tbMisc->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbMisc->horizontalHeader()->setStretchLastSection(true);
    ui->tbMisc->resizeColumnsToContents();

    mcQuery = "select mc.multimediacollectionid, mc.title, ct.collectiontype, dt.datatype, c.category, mc.version, mc.publisher, mc.recordedyear, mc.duration from multimediacollection mc, collectiontype ct, datatype dt, category c where (mc.type = ct.id AND mc.datatype = dt.id AND mc.category = c.id)";
    displayTbMC();

    mcInsQuery = "select mcI.barcode, mc.title, s.status, mcI.borrowingtime, mcI.borroweddate, mcI.borrowingday from multimediacollectioninstance mcI, multimediacollection mc,status s where (mcI.status = s.id and mcI.multimediacollectionid = mc.multimediacollectionid)";
    displayTbMCIns();

    borrowerQuery = "select b.borrowerid, b.name, pt.persontype, d.department, b.mobilenumber, b.borroweditems, b.latereturneditems  from borrower b, persontype pt, department d where (b.department = d.id and b.type = pt.id)";
    displayTbBorrower();

    overdueBorrowerQuery = "select b.borrowerid, b.name, pt.persontype, d.department, b.mobilenumber, b.borroweditems, b.latereturneditems, mcI.borroweddate, mcI.borrowingday  from borrower b, persontype pt, department d, multimediacollectioninstance mcI, borrowingrecord br where (b.department = d.id and b.type = pt.id and b.borrowerid = br.borrowerid and mcI.barcode = br.instancebarcode)";
    operationInsQuery = "select mcI.barcode, mc.title, s.status from multimediacollectioninstance mcI, multimediacollection mc, status s where (mcI.multimediacollectionid = mc.multimediacollectionid and mcI.status = s.id)";
    operationBorrowerQuery = "select b.borrowerid, b.name, b.mobilenumber, b.borroweditems from borrower b";

    ui->statusbar->showMessage("Welcome to Neat Librarian!", 5000);
    for (unsigned int i = 0; i < mc->getVtStatus()->size(); i++)
    {
        QString item = mc->getVtStatus()->at(i)->getName().c_str();
        ui->cbInsFilter->addItem(item);
    }
}

Original::~Original()
{
    delete ui;
}

//QSqlQueryModel* Original::getModel(const QString &query)
//{
//    QSqlQueryModel *modal = new QSqlQueryModel();
//    mc->getDAO()->connectionOpen();

//    QSqlQuery *qry = new QSqlQuery(mc->getDAO()->mydb);
//    qry->prepare(query);
//    qry->exec();
//    modal->setQuery(*qry);
//    mc->getDAO()->mydb.close();
//    return modal;
//}

void Original::on_actionExit_triggered()
{
    this->close();

}

void Original::on_btnMCAdd_clicked()
{
    AddCollectionForm acf;

    mc->getDAO()->connectionOpen();
    QSqlQuery qry;

    //set id
    qry.prepare("select * from multimediacollection");
    qry.exec();
    int current = MultimediaCollection::getCurrentID() + 1;
    QString nextId = "MC_" + QString::number(current);
    acf.getIdText()->setText(nextId);

    //Collection
    qry.prepare("select * from CollectionType");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        acf.getCurrentCollectionType()->addItem(tempi);
    }

    //CollectionDatatype
    qry.prepare("select * from DataType");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        acf.getCurrentCollectionDataType()->addItem(tempi);
    }

    //Category
    qry.prepare("select * from Category");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        acf.getCurrentCategory()->addItem(tempi);
    }

    mc->getDAO()->mydb.close();

    acf.setCurrentType("Collection");
    acf.setCurrentAction("add");
    acf.setModal(true);
    acf.exec();
    displayTbMC();
}

QString Original::getLastId(QString tablename)
{
    string tempID;
    QString id;
    int currentID;
    stringstream ss;

    if(tablename.compare(COLLECTIONTYPE_TABLE) == 0)
    {
//        ss << mc->getVtCollectionType()->at(0)->getCurrentID() + 1;
//        tempID = "CT_" + ss.str();
        currentID = CollectionType::getCurrentID() + 1;
        ss << currentID;
        tempID = "CT_" + ss.str();

    }else if(tablename.compare(DATATYPE_TABLE) == 0)
    {
        currentID = DataType::getCurrentID() + 1;
        ss << currentID;
        tempID = "DT_" + ss.str();
    }else if(tablename.compare(CATEGORY_TABLE) == 0)
    {
        currentID = Category::getCurrentID() + 1;
        ss << currentID;
        tempID = "C_" + ss.str();
    }else if(tablename.compare(STATUS_TABLE) == 0)
    {
        currentID = Status::getCurrentID() + 1;
        ss << currentID;
        tempID = "S_" + ss.str();
    }else if(tablename.compare(PERSONTYPE_TABLE) == 0)
    {
        currentID = PersonType::getCurrentID() + 1;
        ss << currentID;
        tempID = "PT_" + ss.str();
    }else if(tablename.compare(DEPARTMENT_TABLE) == 0)
    {
        currentID = Department::getCurrentID() + 1;
        ss << currentID;
        tempID = "D_" + ss.str();
    }

    id = tempID.c_str();

    return id;
}

void Original::displayTbMC()
{

    if(ui->collection_borrower_table->model() != NULL)
    {
        delete ui->collection_borrower_table->model();
        ui->collection_borrower_table->setModel(NULL);
    }
    if(ui->collection_item_table->model() != NULL)
    {
        delete ui->collection_item_table->model();
        ui->collection_item_table->setModel(NULL);
    }

    ui->total_item->setText("");
    ui->total_borrower->setText("");

    int sortingIndex = ui->cbMCSort->currentIndex();
    int filterIndex = ui->cbMCFilter->currentIndex();

    QString sorting ;
    QString filter;
    QString searching = ui->txtMCSearch->text();

    if (sortingIndex == 0)
        sorting = "mc.multimediacollectionid";
    else if(sortingIndex == 1)
        sorting = "ct.collectiontype";
    else if(sortingIndex == 2)
        sorting = "dt.datatype";
    else if(sortingIndex == 3)
        sorting = "c.category";
    else if(sortingIndex == 4)
        sorting = "mc.title";
    else if(sortingIndex == 5)
        sorting = "mc.version";
    else if(sortingIndex == 6)
        sorting = "mc.publisher";
    else if(sortingIndex == 7)
        sorting = "mc.recordedyear";
    else if(sortingIndex == 8)
        sorting = "mc.duration";

    if (filterIndex == 0)
        filter = "mc.multimediacollectionid";
    else if(filterIndex == 1)
        filter = "ct.collectiontype";
    else if(filterIndex == 2)
        filter = "dt.datatype";
    else if(filterIndex == 3)
        filter = "c.category";
    else if(filterIndex == 4)
        filter = "mc.title";
    else if(filterIndex == 5)
        filter = "mc.version";
    else if(filterIndex == 6)
        filter = "mc.publisher";
    else if(filterIndex == 7)
        filter = "mc.recordedyear";
    else if(filterIndex == 8)
        filter = "mc.duration";

    if(ui->tbMC->model() != NULL)
    {
        delete ui->tbMC->model();
        ui->tbMC->setModel(NULL);
    }

    if(searching.compare("") != 0)
    {
        const QString query = mcQuery + " AND " + filter +" LIKE '%"+ searching +"%' ORDER BY "+ sorting;
        ui->tbMC->setModel(mc->getDAO()->getModel(query));
    }
    else
    {
        const QString query = mcQuery + " ORDER BY " + sorting;
        ui->tbMC->setModel(mc->getDAO()->getModel(query));
    }

}

void Original::displayTbOperationInstance()
{
    QString searching = ui->txtOperationInsSearch->text();

    if(ui->tbOperationInstance->model() != NULL)
    {
        delete ui->tbOperationInstance->model();
        ui->tbOperationInstance->setModel(NULL);
    }

    if(searching.compare("") != 0)
    {
        const QString query = operationInsQuery + " AND (mcI.barcode LIKE '%"+ searching +"%' OR mc.title LIKE '%"+ searching +"%')";
        ui->tbOperationInstance->setModel(mc->getDAO()->getModel(query));
    }
}

void Original::displayTbOperationBorrower()
{
    QString searching = ui->txtOperationBorrowerSearch->text();

    if(ui->tbOperationBorrower->model() != NULL)
    {
        delete ui->tbOperationBorrower->model();
        ui->tbOperationBorrower->setModel(NULL);
    }

    if(searching.compare("") != 0)
    {
        const QString query = operationBorrowerQuery + " where (b.borrowerid LIKE '%"+ searching +"%' OR b.name LIKE '%"+ searching +"%' OR b.mobilenumber LIKE '%"+ searching +"%')";
        ui->tbOperationBorrower->setModel(mc->getDAO()->getModel(query));
    }
}


void Original::displayTbMCIns()
{    

    if(ui->item_borrower_table->model() != NULL)
    {
        delete ui->item_borrower_table->model();
        ui->item_borrower_table->setModel(NULL);
    }
    if(ui->item_collection_table->model() != NULL)
    {
        delete ui->item_collection_table->model();
        ui->item_collection_table->setModel(NULL);
    }


    int sortingIndex = ui->cbInsSort->currentIndex();
    int filterIndex = ui->cbInsFilter->currentIndex();

    QString filter = ui->cbInsFilter->currentText();
    QString sorting;
    QString searching = ui->txtInsSearch->text();

    if (sortingIndex == 0)
        sorting = "mcI.barcode";
    else if(sortingIndex == 1)
        sorting = "s.status";
    else if(sortingIndex == 2)
        sorting = "mcI.borrowingtime";
    else if(sortingIndex == 3)
        sorting = "mcI.borroweddate";
    else if(sortingIndex == 4)
        sorting = "mcI.borrowingday";
    else if(sortingIndex == 5)
        sorting = "mc.title";

    int rowCount = ui->tbIns->rowCount();
    int columnCount = ui->tbIns->columnCount();

    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < columnCount; j++)
        {
            delete ui->tbIns->item(0,j);
        }
        ui->tbIns->removeRow(0);
    }

    if(filterIndex == 0)
    {
        ui->txtInsSearch->setEnabled(true);
        QString tempQuery;

        if(searching.compare("") != 0)
            tempQuery = mcInsQuery + " AND mcI.multimediacollectionid LIKE '%"+ searching +"%' ORDER BY "+ sorting;
        else
            tempQuery = mcInsQuery + " ORDER BY "+ sorting;

        const QString query = tempQuery; 

        ui->tbIns->hideColumn(6);

        setDataToTable(query,ui->tbIns);

    }
    else if(filterIndex == 1)
    {
        ui->txtInsSearch->setEnabled(false);
        const QString query = mcInsQuery + " AND s.status ='BORROWED' ORDER BY "+ sorting;

        QSqlQueryModel *model = mc->getDAO()->getModel(query);

        ui->tbIns->showColumn(6);

        int lateDay;
        string borrowedDate;
        int borrowingDay;
        int count = 0;
        for(int i = 0; i < model->rowCount(); i++)
        {
            stringstream ss;
            borrowedDate = model->data(model->index(i,4)).toString().toStdString();
            borrowingDay = model->data(model->index(i,5)).toInt();
            lateDay = mc->isLate(borrowedDate,borrowingDay);
            ss << lateDay;

            if(lateDay > 0)
            {
                cout << "lateday: " << ss.str().c_str() << endl;
                cout << "query: " << query.toStdString() << endl;
                ui->tbIns->insertRow(count);
                cout << "row count: " << ui->tbIns->rowCount() << endl;
                for(int j = 0; j <model->columnCount(); j++)
                {
                    QTableWidgetItem *item = new QTableWidgetItem();
                    item->setText(model->data(model->index(i,j)).toString());
                    ui->tbIns->setItem(count,j,item);
                }
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setText(ss.str().c_str());
                ui->tbIns->setItem(count,6,item);
                count++;
            }
        }
        delete model;
    }
    else
    {
        ui->txtInsSearch->setEnabled(false);
        const QString query = mcInsQuery + " AND s.status ='"+ filter +"' ORDER BY "+ sorting;

        ui->tbIns->hideColumn(6);

        setDataToTable(query,ui->tbIns);

    }
}

void Original::displayTbBorrower()
{
    int sortingIndex = ui->cbBorrowerSort->currentIndex();
    int filterIndex = ui->cbBorrowerFilter->currentIndex();
    QString sorting;
    QString filter;
    QString searching = ui->txtBorrowerSearch->text();

    if (sortingIndex == 0)
        sorting = "b.borrowerid";
    else if(sortingIndex == 1)
        sorting = "b.name";
    else if(sortingIndex == 2)
        sorting = "pt.persontype";
    else if(sortingIndex == 3)
        sorting = "d.department";
    else if(sortingIndex == 4)
        sorting = "b.mobilenumber";
    else if(sortingIndex == 5)
        sorting = "b.borroweditems";
    else if(sortingIndex == 6)
        sorting = "b.latereturneditems";

    if (filterIndex == 0)
        filter = "b.borrowerid";
    else if(filterIndex == 1)
        filter = "b.name";
    else if(filterIndex == 2)
        filter = "pt.persontype";
    else if(filterIndex == 3)
        filter = "d.department";
    else if(filterIndex == 4)
        filter = "b.mobilenumber";
    else if(filterIndex == 5)
        filter = "b.borroweditems";
    else if(filterIndex == 6)
        filter = "b.latereturneditems";

    int rowCount = ui->tbBorrower->rowCount();
    int columnCount = ui->tbBorrower->columnCount();

    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < columnCount; j++)
        {
            delete ui->tbBorrower->item(0,j);
        }
        ui->tbBorrower->removeRow(0);
    }

    rowCount = ui->borrower_item_table->rowCount();
    columnCount = ui->borrower_item_table->columnCount();

    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < columnCount; j++)
        {
            delete ui->borrower_item_table->item(0,j);
        }
        ui->borrower_item_table->removeRow(0);
    }

    ui->lblPreviouslyBorrowed->setText("");
    ui->lblCurrentlyBorrowed->setText("");

    if(filterIndex == 7)
    {

        ui->txtBorrowerSearch->setEnabled(false);
        const QString query = overdueBorrowerQuery + " ORDER BY " + sorting;
        QSqlQueryModel *model = mc->getDAO()->getModel(query);

        int lateDay = 1;
        string borrowedDate;
        int borrowingDay;
        vector<string> *insertedID = new vector<string>;
        bool exist;
        int count = 0;

        for(int i = 0; i < model->rowCount(); i++)
        {
            stringstream ss;
            borrowedDate = model->data(model->index(i,7)).toString().toStdString();
            borrowingDay = model->data(model->index(i,8)).toInt();
            lateDay = mc->isLate(borrowedDate,borrowingDay);
            ss << lateDay;

            insertedID->push_back(model->data(model->index(i,0)).toString().toStdString());
            exist = false;
            for(int t = 0; t < i; t++)
            {
                if(insertedID->at(t).compare(insertedID->at(i)) == 0)
                {
                    exist = true;
                    break;
                }
            }
            if(lateDay > 0 && !exist)
            {
                ui->tbBorrower->insertRow(count);
                for(int j = 0; j <model->columnCount()-2; j++)
                {
                    QTableWidgetItem *item = new QTableWidgetItem();
                    item->setText(model->data(model->index(i,j)).toString());
                    ui->tbBorrower->setItem(count,j,item);
                }
                count++;
            }
        }
        delete model;
        delete insertedID;

    }
    else
    {
        ui->txtBorrowerSearch->setEnabled(true);

        QString tempQuery;
        if(searching.compare("") == 0)
            tempQuery = borrowerQuery + " ORDER BY " + sorting;
        else
            tempQuery = borrowerQuery + " AND "+ filter +" LIKE '%"+ searching +"%' ORDER BY "+ sorting;

        const QString query = tempQuery;

        setDataToTable(query,ui->tbBorrower);

    }
}

void Original::on_cbMisc_activated(const QString &arg1)
{
    if(ui->tbMisc->model() != NULL)
    {
        delete ui->tbMisc->model();
        ui->tbMisc->setModel(NULL);
    }

    if(arg1.compare("CollectionType") == 0)
    {
        misc_value = "CollectionType";
        const QString query  = "select * from CollectionType";
        ui->tbMisc->setModel(mc->getDAO()->getModel(query));

    }else if(arg1.compare("DataType") == 0)
    {
        misc_value = "DataType";
        const QString query = "select * from DataType";
        ui->tbMisc->setModel(mc->getDAO()->getModel(query));
    }else if(arg1.compare("Category") == 0)
    {
        misc_value = "Category";
        const QString query = "select * from Category";
        ui->tbMisc->setModel(mc->getDAO()->getModel(query));
    }else if(arg1.compare("Department") == 0)
    {
        misc_value = "Department";
        const QString query = "select * from Department";
        ui->tbMisc->setModel(mc->getDAO()->getModel(query));
    }else if(arg1.compare("PersonType") == 0)
    {
        misc_value = "PersonType";
        const QString query = "select * from PersonType";
        ui->tbMisc->setModel(mc->getDAO()->getModel(query));
    }else if(arg1.compare("Status") == 0)
    {
        misc_value = "Status";
        const QString query = "select * from Status";
        ui->tbMisc->setModel(mc->getDAO()->getModel(query));

    }else
    {
        misc_value = "";
    }
    QString display_value= misc_value.c_str();
    ui->statusbar->showMessage(display_value,2000);
}

void Original::on_btnMiscAdd_clicked()
{
    //    ui->statusbar->showMessage("CLICKED",2000);
    if(!(misc_value.compare("") == 0))
    {
        MiscAddForm miscAdd;
        QString temptable;

        //Set id
        if(misc_value.compare("CollectionType") == 0)
        {
            temptable = "CollectionType";

        }else if(misc_value.compare("DataType") == 0)
        {
            temptable = "DataType";
        }else if(misc_value.compare("Category") == 0)
        {
            temptable = "Category";
        }else if(misc_value.compare("Department") == 0)
        {
            temptable = "Department";
        }else if(misc_value.compare("PersonType") == 0)
        {
            temptable = "PersonType";
        }else if(misc_value.compare("Status") == 0)
        {
            temptable = "Status";
        }

        QString tempid = getLastId(temptable);
        miscAdd.setTxtMiscID(tempid);

        //Set type for adding query in miscaddform
        miscAdd.setCurrentType(misc_value);
        miscAdd.setCurrentAction("add");
        miscAdd.setModal(true);
        miscAdd.exec();

        //Set id
        if(misc_value.compare("CollectionType") == 0)
        {
            const QString query  = "select * from CollectionType";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("DataType") == 0)
        {
            const QString query = "select * from DataType";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("Category") == 0)
        {
            const QString query = "select * from Category";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("Department") == 0)
        {
            const QString query = "select * from Department";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("PersonType") == 0)
        {
            const QString query = "select * from PersonType";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("Status") == 0)
        {
            const QString query = "select * from Status";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }
    }
}

void Original::on_tbIns_clicked(const QModelIndex &i)
{
 //   cout <<  ui->tbIns->model()->data(index).toString().toStdString() << endl;
    ins_value = ui->tbIns->model()->data(ui->tbIns->model()->index(i.row(),0)).toString().toStdString();

    //Display collection
    mc->getDAO()->connectionOpen();
    QSqlQuery qry;
    qry.prepare("select multimediacollectionid from multimediacollectioninstance where barcode = :barcode ;");
    qry.bindValue(":barcode",ins_value.c_str());
    qry.exec();
    QString multi_id;
    QString ins_value_inqstring = ins_value.c_str();
    while(qry.next())
    {
        multi_id = qry.value(0).toString();
    }

    mc->getDAO()->mydb.close();

    QString co_query = "select mc.multimediacollectionid, mc.title, mc.version from multimediacollection mc where mc.multimediacollectionid = '"+multi_id+ "'";
    QSqlQueryModel* co_query_model = mc->getDAO()->getModel(co_query);

    if(ui->item_collection_table->model() != NULL)
    {
        delete ui->item_collection_table->model();
        ui->item_collection_table->setModel(NULL);
    }

    ui->item_collection_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->item_collection_table->horizontalHeader()->setStretchLastSection(true);
    ui->item_collection_table->resizeColumnsToContents();
    ui->item_collection_table->setModel(co_query_model);

    //Display borrower
    QString bo_query = "select b.borrowerid, b.name, b.mobilenumber from borrower b, borrowingrecord br, multimediacollectioninstance mcI where mcI.barcode = br.instancebarcode and br.borrowerid = b.borrowerid and mcI.barcode = '" + ins_value_inqstring + "'";
    QSqlQueryModel * bo_query_model = mc->getDAO()->getModel(bo_query);

    if(ui->item_borrower_table->model() != NULL)
    {
        delete ui->item_borrower_table->model();
        ui->item_borrower_table->setModel(NULL);
    }

    ui->item_borrower_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->item_borrower_table->horizontalHeader()->setStretchLastSection(true);
    ui->item_borrower_table->resizeColumnsToContents();
    ui->item_borrower_table->setModel(bo_query_model);

}


void Original::on_txtMCSearch_textChanged(const QString &arg1)
{
    displayTbMC();
}

void Original::on_cbMCSort_activated(const QString &arg1)
{
    displayTbMC();
}

void Original::on_cbInsSort_activated(const QString &arg1)
{
    displayTbMCIns();
}

void Original::on_txtInsSearch_textChanged(const QString &arg1)
{
    displayTbMCIns();
}

void Original::on_cbBorrowerSort_activated(const QString &arg1)
{
    displayTbBorrower();
}

void Original::on_txtBorrowerSearch_textChanged(const QString &arg1)
{
    displayTbBorrower();
}


void Original::on_txtOperationInsSearch_textChanged(const QString &arg1)
{
    displayTbOperationInstance();
}

void Original::on_cbMCFilter_activated(const QString &arg1)
{
    displayTbMC();
}

void Original::on_cbInsFilter_activated(const QString &arg1)
{
    displayTbMCIns();
}

void Original::on_cbBorrowerFilter_activated(const QString &arg1)
{
    displayTbBorrower();
}

void Original::on_cbBorrowerFilter_currentIndexChanged(int index)
{


}

void Original::on_tabWidget_currentChanged(int index)
{
    if(index == 0){
        displayTbMC();
    }
    else if(index == 1)
        displayTbMCIns();
    else if(index == 2)
        displayTbBorrower();
    else if(index == 4){
        displayTbOperationBorrower();
        displayTbOperationInstance();
    }
}


void Original::on_tbMC_clicked(const QModelIndex &i)
{

    if(i.row() >= 0)
    {
        mc_value = ui->tbMC->model()->data(ui->tbMC->model()->index(i.row(),0)).toString().toStdString();
        QString thevalue = mc_value.c_str();

        QString theitemquery = "select mcI.barcode,s.status from multimediacollectioninstance mcI, status s where mcI.multimediacollectionid = '" + thevalue + "' AND mcI.status = s.id";
        QSqlQueryModel * modal = mc->getDAO()->getModel(theitemquery);

        if(ui->collection_item_table->model() != NULL)
        {
            delete ui->collection_item_table->model();
            ui->collection_item_table->setModel(NULL);
        }

        ui->collection_item_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->collection_item_table->horizontalHeader()->setStretchLastSection(true);
        ui->collection_item_table->resizeColumnsToContents();      
        ui->collection_item_table->setModel(modal);

        QString theborrowerquery = "select br.borrowerid,b.name,b.mobilenumber from borrower b, multimediacollectioninstance mcI, borrowingrecord br where mcI.multimediacollectionid = '" + thevalue + "' AND mcI.barcode = br.instancebarcode AND br.borrowerid = b.borrowerid";
        modal = mc->getDAO()->getModel(theborrowerquery);

        if(ui->collection_borrower_table->model() != NULL)
        {
            delete ui->collection_borrower_table->model();
            ui->collection_borrower_table->setModel(NULL);
        }

//        ui->collection_borrower_table->setSelectionBehavior(QAbstractItemView::SelectRows);
//        ui->collection_borrower_table->horizontalHeader()->setStretchLastSection(true);
//        ui->collection_borrower_table->resizeColumnsToContents();
        ui->collection_borrower_table->setModel(modal);
        stringstream ssItem;
        ssItem << ui->collection_item_table->model()->rowCount();
        stringstream ssBorrower;
        ssBorrower << ui->collection_borrower_table->model()->rowCount();
        ui->total_item->setText(ssItem.str().c_str());
        ui->total_borrower->setText(ssBorrower.str().c_str());
    }


}

void Original::on_btnMCEdit_clicked()
{
    if(mc_value.compare("") == 0)
    {
        QMessageBox::warning(this, "Warning","No record selected","OK");
        return;
    }
    AddCollectionForm acf;

    mc->getDAO()->connectionOpen();
    QSqlQuery qry;

    //Get all
    QString thequery = "select * from " + MC_TABLE + " where multimediacollectionid = :id ;";
    qry.prepare(thequery);
    QString tempmc_value = mc_value.c_str();
    //setid
    acf.getIdText()->setText(tempmc_value);
    qry.bindValue(":id",tempmc_value);
    qry.exec();

    QString collectiontype;
    QString datatype;
    QString category;
    QString title;
    QString version;
    QString publisher;
    QString recordedYear;
    QString duration;

    stringstream ss;

    while(qry.next())
    {
        collectiontype = qry.value(1).toString();
        datatype = qry.value(2).toString();
        category = qry.value(3).toString();
        title = qry.value(4).toString();
        version = qry.value(5).toString();
        publisher = qry.value(6).toString();
        recordedYear = qry.value(7).toString();
        duration = qry.value(8).toString();
    }
    double total;
    istringstream(duration.toStdString()) >> total;
    double hr = floor(total / 3600);

    double temp_mi = static_cast<int>((total/60))%60;
    double mi = floor(temp_mi);

    double tempse = static_cast<int>(total) % 60;
    double se = tempse;

    //Collection
    qry.prepare("select * from collectiontype");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        acf.getCurrentCollectionType()->addItem(tempi);

    }
    qry.prepare("select * from collectiontype where id = :id;");
    qry.bindValue(":id",collectiontype);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        acf.getCurrentCollectionType()->setCurrentText(tempi);
    }

    //CollectionDatatype
    qry.prepare("select * from datatype");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        acf.getCurrentCollectionDataType()->addItem(tempi);
    }
    qry.prepare("select * from datatype where id = :id;");
    qry.bindValue(":id",datatype);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        acf.getCurrentCollectionDataType()->setCurrentText(tempi);
    }

    //Category
    QString categoryadd;
    qry.prepare("select * from category");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        acf.getCurrentCategory()->addItem(tempi);
        if(tempi.compare(category))
        {
            categoryadd = tempi;
        }
    }
    qry.prepare("select * from category where id = :id;");
    qry.bindValue(":id",category);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        acf.getCurrentCategory()->setCurrentText(tempi);
    }

    //Set title, version, publisher
    acf.getCurrentTitle()->setText(title);
    acf.getCurrentVersion()->setText(version);
    acf.getCurrentPublisher()->setText(publisher);

    //Set year
    int yearadd;
    stringstream(recordedYear.toStdString()) >> yearadd;
    QDate *da = new QDate(yearadd,1,1);
    acf.getCurrentYearRecorded()->setDate(*da);
    delete da;

    //Set duration
    acf.getCurrentHour()->setValue(static_cast<int>(hr));
    acf.getCurrentMinute()->setValue(static_cast<int>(mi));
    acf.getCurrentSecond()->setValue(static_cast<int>(se));

    mc->getDAO()->mydb.close();

    acf.getAddButton()->setText("Update");
    acf.setCurrentType("Collection");
    acf.setModal(true);
    acf.setCurrentAction("edit");
    acf.setCurrentClickId(mc_value);
    acf.exec();

    displayTbMC();
}

void Original::on_btnMiscDelete_clicked()
{
    switch(QMessageBox::warning(this,"Warning","Are you sure you want to delete this record?","Yes","No",0,1))
    {
        case 0:
            mc->getDAO()->connectionOpen();
            QSqlQuery qry;
            QString thetable = misc_value.c_str();
            QString thequery = "delete from " + thetable + " where id = :id ;";
            qry.prepare(thequery);
            qry.bindValue(":id",misc_click.c_str());
            qry.exec();
            QString thedisplay = "select * from " + thetable + ";";

            if(ui->tbMisc->model() != NULL)
            {
                delete ui->tbMisc->model();
                ui->tbMisc->setModel(NULL);
            }

            ui->tbMisc->setModel(mc->getDAO()->getModel(thedisplay));
    }
}

void Original::on_btnMCDelete_clicked()
{
    switch(QMessageBox::warning(this,"Confirmation","Are you sure you want to delete this record?","Delete ","Cancel",0,1))
    {
        case 0:
            mc->deleteMC(mc_value);
            mc->getDAO()->deleteMultimediaCollection(mc_value);
            displayTbMC();
    }

}

void Original::on_txtOperationBorrowerSearch_textChanged(const QString &arg1)
{
    displayTbOperationBorrower();
}

void Original::on_btnOperationBorrowing_clicked()
{

    QModelIndex iBorrower = ui->tbOperationBorrower->currentIndex();
    QModelIndex iIns = ui->tbOperationInstance->currentIndex();

    if(iBorrower.row() != -1 && iIns.row() != -1)
    {
        QString instanceBarcode = ui->tbOperationInstance->model()->data(ui->tbOperationInstance->model()->index(iIns.row(),0)).toString();
        QString borrowerID = ui->tbOperationBorrower->model()->data(ui->tbOperationBorrower->model()->index(iBorrower.row(),0)).toString();
        string statusID = mc->getInstance(instanceBarcode.toStdString())->getStatus();
        if(mc->getStatus(statusID,"")->getName().compare("BORROWED") != 0)
        {
            BorrowingForm brf;
            brf.getTxtItem()->setText(instanceBarcode);
            brf.getTxtBorrower()->setText(borrowerID);
            brf.setModal(true);
            brf.exec();
            ui->txtOperationBorrowerSearch->setText("");
            ui->txtOperationInsSearch->setText("");
            displayTbOperationBorrower();
            displayTbOperationInstance();
        }
        else
            QMessageBox::warning(this, "Warning","This item is already borrowed","OK");
    }
}

void Original::on_btnOperationReturning_clicked()
{
    QModelIndex iIns = ui->tbOperationInstance->currentIndex();

    if(iIns.row() != -1)
    {
        QString instanceBarcode = ui->tbOperationInstance->model()->data(ui->tbOperationInstance->model()->index(iIns.row(),0)).toString();
        string statusID = mc->getInstance(instanceBarcode.toStdString())->getStatus();
        if(mc->getStatus(statusID,"")->getName().compare("BORROWED") == 0)
        {
            switch(QMessageBox::information(this, "Confirmation","Confirm to return this item","Yes","No",0,1))
            {
                case 0:
                    string borrowing_date = mc->getInstance(instanceBarcode.toStdString())->getBorrowedDate();
                    int borrowingDay = mc->getInstance(instanceBarcode.toStdString())->getBorrowingDay();
                    bool late = false;
                    if(mc->isLate(borrowing_date,borrowingDay) > 0)
                    {
                        late = true;
                        QMessageBox::warning(this, "Warning","Late Return!!!","OK",0);
                    }
                    mc->returning(instanceBarcode,late);
            }
            ui->txtOperationBorrowerSearch->setText("");
            ui->txtOperationInsSearch->setText("");
            displayTbOperationBorrower();
            displayTbOperationInstance();

        }
        else
            QMessageBox::warning(this, "Warning","This item is not borrowed yet","OK");
    }
}



void Original::on_btnBorrowerAdd_clicked()
{
    AddBorrower abf;

    mc->getDAO()->connectionOpen();
    QSqlQuery qry;

    //set id
    qry.prepare("select * from borrower");
    qry.exec();
    int current = Borrower::getCurrentID() + 1;
    QString nextId = "B_" + QString::number(current);
    abf.getIdText()->setText(nextId);

    //Type
    qry.prepare("select * from persontype");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        abf.getPersonType()->addItem(tempi);
    }

    //Department
    qry.prepare("select * from department");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        abf.getDepartment()->addItem(tempi);
    }

    mc->getDAO()->mydb.close();

    //Set disable 2 spins
    abf.getBorrowedItem()->setEnabled(false);
    abf.getReturnItem()->setEnabled(false);

    abf.setCurrentAction("add");
    abf.setModal(true);
    abf.exec();
    displayTbBorrower();
}


void Original::on_tbMC_activated(const QModelIndex &index)
{
    cout << "ACTIATED \n";
}

void Original::on_tbBorrower_clicked(const QModelIndex &i)
{
    int currentRow = ui->tbBorrower->currentRow();
    bo_value = ui->tbBorrower->item(currentRow,0)->text().toStdString();
    QString thevalue = bo_value.c_str();
    QString query = "select mcI.barcode,mcI.borroweddate, mcI.borrowingday from borrower b, borrowingrecord br, multimediacollectioninstance mcI where mcI.barcode = br.instancebarcode and br.borrowerid = b.borrowerid and b.borrowerid = '" + thevalue + "'";

    int lateDay = 0;
    string borrowedDate;
    int borrowingDay;

    int rowCount = ui->borrower_item_table->rowCount();
    int columnCount = ui->borrower_item_table->columnCount();

    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < columnCount; j++)
        {
            delete ui->borrower_item_table->item(0,j);
        }
        ui->borrower_item_table->removeRow(0);
    }

    QSqlQueryModel *model = mc->getDAO()->getModel(query);
    for(int i = 0; i < model->rowCount(); i++)
    {
        stringstream ss;
        borrowedDate = model->data(model->index(i,1)).toString().toStdString();
        borrowingDay = model->data(model->index(i,2)).toInt();
        lateDay = mc->isLate(borrowedDate,borrowingDay);

        ss << lateDay;
        ui->borrower_item_table->insertRow(i);
        for(int j = 0; j <model->columnCount(); j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(model->data(model->index(i,j)).toString());
            ui->borrower_item_table->setItem(i,j,item);
        }
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(ss.str().c_str());
        ui->borrower_item_table->setItem(i,3,item);

    }
    delete model;

    stringstream ssCurrently;
    ssCurrently << ui->borrower_item_table->rowCount();
    stringstream ssPreviously;
    ssPreviously << ui->tbBorrower->item(currentRow,5)->text().toInt() - ui->borrower_item_table->rowCount();

    ui->lblPreviouslyBorrowed->setText(ssPreviously.str().c_str());
    ui->lblCurrentlyBorrowed->setText(ssCurrently.str().c_str());


}

void Original::on_btnBorrowerDelete_clicked()
{
    switch(QMessageBox::warning(this,"Confirmation","Are you sure you want to delete this record?","Delete ","Cancel",0,1))
    {
        case 0:
            mc->deleteBorrower(bo_value);
            mc->getDAO()->deleteBorrower(bo_value);
            displayTbBorrower();
    }
}

void Original::on_btnBorrowerEdit_clicked()
{
    if(bo_value.compare("") == 0)
    {
        QMessageBox::warning(this, "Warning","No record selected","OK");
        return;
    }

    AddBorrower abf;

    mc->getDAO()->connectionOpen();
    QSqlQuery qry;

    QString thequery = "select * from " + BORROWER_TABLE + " where borrowerid = :id ;";
    qry.prepare(thequery);
    QString tempBorrowerValue = bo_value.c_str();
    abf.getIdText()->setText(tempBorrowerValue);
    qry.bindValue(":id",tempBorrowerValue);
    qry.exec();

    QString name;
    QString personType;
    QString deparment;
    QString phone;
    QString borrowItem;
    QString returnItem;

    while(qry.next())
    {
        name = qry.value(1).toString();
        personType = qry.value(2).toString();
        deparment = qry.value(3).toString();
        phone = qry.value(4).toString();
        borrowItem = qry.value(5).toString();
        returnItem = qry.value(6).toString();
    }

    stringstream ss;

    int borrowInt;
    istringstream(borrowItem.toStdString()) >> borrowInt;

    int returnInt;
    istringstream(returnItem.toStdString()) >> returnInt;

    //Type
    qry.prepare("select * from persontype");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        abf.getPersonType()->addItem(tempi);
    }
    qry.prepare("select * from persontype where id = :id;");
    qry.bindValue("id",personType);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        abf.getPersonType()->setCurrentText(tempi);
    }

    //Department
    qry.prepare("select * from department");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        abf.getDepartment()->addItem(tempi);
    }
    qry.prepare("select * from department where id = :id;");
    qry.bindValue(":id",deparment);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        abf.getDepartment()->setCurrentText(tempi);
    }

    //Set Name, Phonenumber
    abf.getNameText()->setText(name);
    abf.getPhone()->setText(phone);

    //Set return, borrow
    abf.getBorrowedItem()->setValue(borrowInt);
    abf.getReturnItem()->setValue(returnInt);

    mc->getDAO()->mydb.close();

    //Set disable 2 spins
    abf.getBorrowedItem()->setEnabled(true);
    abf.getReturnItem()->setEnabled(true);

    abf.getClickButton()->setText("Update");
    abf.setCurrentAction("edit");
    abf.setCurrentClickId(bo_value);
    abf.setModal(true);
    abf.exec();
    displayTbBorrower();
}

void Original::on_btnInsAdd_clicked()
{
    AddItem aif;

    mc->getDAO()->connectionOpen();
    QSqlQuery qry;

    //Put value into id MC
    qry.prepare("select multimediacollectionid from multimediacollection");
    qry.exec();
    while(qry.next())
    {
        aif.getMcId()->addItem(qry.value(0).toString());
    }

    //Set status
    qry.prepare("select * from status where status<>'BORROWED' and status<>'LOST';");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        aif.getStatus()->addItem(tempi);
    }

    aif.setModal(true);
    aif.setCurrentAction("add");
    aif.setCurrentClickId(ins_value);
    aif.exec();
    mc->getDAO()->mydb.close();
    displayTbMCIns();
}

void Original::on_btnInsEdit_clicked()
{
    if(ins_value.compare("") == 0)
    {
        QMessageBox::warning(this,"Warning","No record selected","OK",0);
        return;
    }

    AddItem aif;

    mc->getDAO()->connectionOpen();
    QSqlQuery qry;

    QString currentStatusId;
    QString barcodeValue;

    //Put value into id MC
    qry.prepare("select multimediacollectionid from multimediacollection");
    qry.exec();
    while(qry.next())
    {
        aif.getMcId()->addItem(qry.value(0).toString());
    }

    //Set value into MC combobox
    qry.prepare("select barcode,status,multimediacollectionid from multimediacollectioninstance where barcode = :barcode ;");
    qry.bindValue(":barcode", ins_value.c_str());
    qry.exec();
    while(qry.next())
    {
        barcodeValue = qry.value(0).toString();
        currentStatusId = qry.value(1).toString();
        aif.getMcId()->setCurrentText(qry.value(2).toString());
    }

    //Set status
    qry.prepare("select * from status where status<>'BORROWED';");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        aif.getStatus()->addItem(tempi);
    }

    //Set current status
    qry.prepare("select * from status where id = :id");
    qry.bindValue(":id",currentStatusId);
    qry.exec();
    while(qry.next())
    {
        aif.getStatus()->setCurrentText(qry.value(1).toString());
        if(qry.value(1).toString().toStdString().compare("BORROWED") == 0)
        {
            QMessageBox::warning(this,"Warning","Please return the item before editing","OK",0);
            mc->getDAO()->mydb.close();
            return;

        }
    }


    //Set value base on ID
    QString type;
    QString datatype;
    QString title;
    QString version;
    QString publisher;
    QString recordedYear;
    QString duration;
    QString category;

    qry.prepare("select * from multimediacollection where multimediacollectionid = :id");
    qry.bindValue(":id",aif.getMcId()->currentText());
    qry.exec();
    while(qry.next())
    {
        type = qry.value(1).toString();
        datatype = qry.value(2).toString();
        category = qry.value(3).toString();
        title = qry.value(4).toString();
        version = qry.value(5).toString();
        publisher = qry.value(6).toString();
        recordedYear = qry.value(7).toString();
        duration = qry.value(8).toString();
    }

    //Collectiontype
    qry.prepare("select * from collectiontype where id = :id;");
    qry.bindValue(":id",type);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        type = tempi;
    }

    //DataType
    qry.prepare("select * from datatype where id = :id;");
    qry.bindValue(":id",datatype);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        datatype = tempi;
    }

    //Category
    qry.prepare("select * from category where id = :id;");
    qry.bindValue(":id",category);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        category = tempi;
    }

    aif.getUI()->type_text->setText(type);
    aif.getUI()->category_text->setText(category);
    aif.getUI()->title_text->setText(title);
    aif.getUI()->record_text->setText(recordedYear);
    aif.getUI()->datatype_text->setText(datatype);
    aif.getUI()->version_text->setText(version);
    aif.getUI()->publisher_text->setText(publisher);
    aif.getUI()->duration_text->setText(duration);

    //Set copy to 1 and disable
    aif.getCopy()->setEnabled(false);
    aif.getCopy()->setValue(1);

    //Set barcode
    QTableWidgetItem *barcodeItem = new QTableWidgetItem();
    barcodeItem->setText(barcodeValue);
    aif.getBarcodeTable()->setItem(0,0,barcodeItem);
    aif.setOldBarcode(barcodeValue);

    //Change ADD to UPDATE
    aif.getAddButton()->setText("Update");

    aif.setModal(true);
    aif.setCurrentAction("edit");
    aif.setCurrentClickId(ins_value);
    aif.exec();
    displayTbMCIns();
    mc->getDAO()->mydb.close();
}

void Original::on_btnInsDelete_clicked()
{
    //get status
    mc->getDAO()->connectionOpen();
    QSqlQuery qry;

    QString currentStatusId;
    qry.prepare("select status from multimediacollectioninstance where barcode = :barcode ;");
    qry.bindValue(":barcode", ins_value.c_str());
    qry.exec();
    while(qry.next())
    {
        currentStatusId = qry.value(0).toString();
    }

    qry.prepare("select * from status where id = :id ;");
    qry.bindValue(":id",currentStatusId);
    qry.exec();
    while(qry.next())
    {
        if(qry.value(1).toString().toStdString().compare("BORROWED") == 0)
        {
            QMessageBox::warning(this,"Warning","Cannot delete item while borrowing","OK",0);
            mc->getDAO()->mydb.close();
            return;

        }
    }

    switch(QMessageBox::warning(this,"Confirmation","Are you sure you want to delete this record?","Delete ","Cancel",0,1))
    {
        case 0:
            mc->deleteMCInstance(ins_value);
            mc->getDAO()->deleteMCInstance(ins_value);
            displayTbMCIns();
    }
}

void Original::on_tbMisc_clicked(const QModelIndex &i)
{
    misc_click = ui->tbMisc->model()->data(ui->tbMisc->model()->index(i.row(),0)).toString().toStdString();
    if(misc_click.substr(0,1).compare("S") == 0)
    {
        mc->getDAO()->connectionOpen();
        QSqlQuery qry;
        qry.prepare("select status from Status where id = :id ;");
        qry.bindValue(":id",misc_click.c_str());
        qry.exec();
        while(qry.next())
        {
            if(qry.value(0).toString().toStdString().compare("BORROWED") == 0||
                    qry.value(0).toString().toStdString().compare("STOREROOM") == 0 ||
                    qry.value(0).toString().toStdString().compare("LIBRARY") == 0||
                    qry.value(0).toString().toStdString().compare("LOST") == 0)
            {
                this->ui->btnMiscDelete->setEnabled(false);
                this->ui->btnMiscEdit->setEnabled(false);
            }else
            {
                this->ui->btnMiscDelete->setEnabled(true);
                this->ui->btnMiscEdit->setEnabled(true);
            }
        }

    }else
    {
        this->ui->btnMiscDelete->setEnabled(true);
        this->ui->btnMiscEdit->setEnabled(true);
    }
}

void Original::on_btnMiscEdit_clicked()
{
    if(!(misc_value.compare("") == 0))
    {
        MiscAddForm miscAdd;
        QString temptable;

        //Set id
        if(misc_value.compare("CollectionType") == 0)
        {
            temptable = "CollectionType";

        }else if(misc_value.compare("DataType") == 0)
        {
            temptable = "DataType";
        }else if(misc_value.compare("Category") == 0)
        {
            temptable = "Category";
        }else if(misc_value.compare("Department") == 0)
        {
            temptable = "Department";
        }else if(misc_value.compare("PersonType") == 0)
        {
            temptable = "PersonType";
        }else if(misc_value.compare("Status") == 0)
        {
            temptable = "Status";
        }

        mc->getDAO()->connectionOpen();
        QSqlQuery qry;
        QString query = "select * from " + temptable + " where id = :id ;";
        qry.prepare(query);
        qry.bindValue(":id",misc_click.c_str());
        qry.exec();
        while(qry.next())
        {
            miscAdd.setTxtMiscID(qry.value(0).toString());
            miscAdd.getTxtLine()->setText(qry.value(1).toString());
        }

        //Set type for adding query in miscaddform
        mc->getDAO()->mydb.close();
        miscAdd.setCurrentType(misc_value);
        miscAdd.setCurrentAction("edit");
        miscAdd.getAddButton()->setText("Update");
        miscAdd.setModal(true);
        miscAdd.exec();

        //Set id
        if(misc_value.compare("CollectionType") == 0)
        {
            const QString query  = "select * from CollectionType";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("DataType") == 0)
        {
            const QString query = "select * from DataType";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("Category") == 0)
        {
            const QString query = "select * from Category";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("Department") == 0)
        {
            const QString query = "select * from Department";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("PersonType") == 0)
        {
            const QString query = "select * from PersonType";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }else if(misc_value.compare("Status") == 0)
        {
            const QString query = "select * from Status";
            ui->tbMisc->setModel(mc->getDAO()->getModel(query));
        }
    }
}

void Original::on_collection_item_table_clicked(const QModelIndex &index)
{

}

void Original::on_pushButton_clicked()
{
    if(mc_value.compare("") == 0)
    {
        QMessageBox::warning(this,"Warning","No collection selected","OK",0);
        return;
    }
    AddItem aif;

    mc->getDAO()->connectionOpen();
    QSqlQuery qry;

    //Put value into id MC
    qry.prepare("select multimediacollectionid from multimediacollection");
    qry.exec();
    while(qry.next())
    {
        aif.getMcId()->addItem(qry.value(0).toString());
    }

    //Set value into MC combobox
    QString theMC_id = mc_value.c_str();
    qry.prepare("select multimediacollectionid from multimediacollection where multimediacollectionid = :id ;");
    qry.bindValue(":id",theMC_id);
    qry.exec();
    while(qry.next())
    {
        aif.getMcId()->setCurrentText(qry.value(0).toString());
    }

    //Set status
    qry.prepare("select * from status where status<>'BORROWED' and status<>'LOST';");
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        aif.getStatus()->addItem(tempi);
    }

    //Set value base on ID
    QString type;
    QString datatype;
    QString title;
    QString version;
    QString publisher;
    QString recordedYear;
    QString duration;
    QString category;

    qry.prepare("select * from multimediacollection where multimediacollectionid = :id");
    qry.bindValue(":id",aif.getMcId()->currentText());
    qry.exec();
    while(qry.next())
    {
        type = qry.value(1).toString();
        datatype = qry.value(2).toString();
        category = qry.value(3).toString();
        title = qry.value(4).toString();
        version = qry.value(5).toString();
        publisher = qry.value(6).toString();
        recordedYear = qry.value(7).toString();
        duration = qry.value(8).toString();
    }

    //Collectiontype
    qry.prepare("select * from collectiontype where id = :id;");
    qry.bindValue(":id",type);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        type = tempi;
    }

    //DataType
    qry.prepare("select * from datatype where id = :id;");
    qry.bindValue(":id",datatype);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        datatype = tempi;
    }

    //Category
    qry.prepare("select * from category where id = :id;");
    qry.bindValue(":id",category);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        category = tempi;
    }

    aif.getUI()->type_text->setText(type);
    aif.getUI()->category_text->setText(category);
    aif.getUI()->title_text->setText(title);
    aif.getUI()->record_text->setText(recordedYear);
    aif.getUI()->datatype_text->setText(datatype);
    aif.getUI()->version_text->setText(version);
    aif.getUI()->publisher_text->setText(publisher);
    aif.getUI()->duration_text->setText(duration);

    aif.setModal(true);
    aif.setCurrentAction("add");
    aif.setCurrentClickId(ins_value);
    aif.exec();
    displayTbMC();
}

void Original::setDataToTable(const QString query, QTableWidget *table)
{
    QSqlQueryModel *model = mc->getDAO()->getModel(query);
//    cout << query.toStdString().c_str() << endl;
    for(int i = 0; i < model->rowCount(); i++)
    {
        table->insertRow(i);
        for(int j = 0; j <model->columnCount(); j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(model->data(model->index(i,j)).toString());
            table->setItem(i,j,item);
        }
    }
    delete model;
}

void Original::on_actionAbout_triggered()
{

}

void Original::saveFileTbView(QTableView *table, QString header, QString name)
{
    QString fileName = QFileDialog::getSaveFileName(this,tr(name.toStdString().c_str()), QDir::currentPath(), tr("Report (*.html)"));

    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    QString fullHTML = "";

    fullHTML += name
        + "<br/>"
        + "<html>"
        + "<body>"
        + "<table border='1'>"
        + "<tr>"
        + header
        + "</tr>";

    for(int i = 0; i < table->model()->rowCount(); i++)
    {
        fullHTML += "<tr>";
        for(int j = 0; j < table->model()->columnCount(); j++)
        {
            fullHTML += "<td>"
                + table->model()->data(table->model()->index(i,j)).toString()
                + "</td>";
        }
        fullHTML += "</tr>";
    }

    fullHTML += "</body>" ;
    fullHTML += "</html>";

    out << fullHTML;

    file.close();
}

void Original::saveFileTbWidget(QTableWidget *table, QString header, QString name)
{
    QString fileName = QFileDialog::getSaveFileName(this,tr(name.toStdString().c_str()), QDir::currentPath(), tr("Report (*.html)"));

    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    QString fullHTML = "";

    fullHTML += name
        + "<br/>"
        + "<html>"
        + "<body>"
        + "<table border='1'>"
        + "<tr>"
        + header
        + "</tr>";

    for(int i = 0; i < table->rowCount(); i++)
    {
        fullHTML += "<tr>";
        for(int j = 0; j < table->columnCount(); j++)
        {
            fullHTML += "<td>"
                + table->item(i,j)->text()
                + "</td>";
        }
        fullHTML += "</tr>";
    }

    fullHTML += "</body>";
    fullHTML += "</html>";

    out << fullHTML;

    file.close();
}

void Original::printFileTbView(QTableView *table, QString header, QString name)
{
    QString fullHTML = "";
    fullHTML += name
            + "<br/>"
            + "<html>"
            + "<body>"
            + "<table border='1'>"
            + "<tr>"
            + header
            + "</tr>";


    for(int i = 0; i < table->model()->rowCount(); i++)
    {
        fullHTML += "<tr>";
        for(int j = 0; j < table->model()->columnCount(); j++)
        {
            fullHTML += "<td>"
                    + table->model()->data(table->model()->index(i,j)).toString()
                    + "</td>";
        }
        fullHTML += "</tr>";
    }

    fullHTML += "</body>" ;
    fullHTML += "</html>";

    QPrinter printer;
    QTextDocument document;
    document.setHtml(fullHTML);

    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");

    if(dialog->exec() != QDialog::Accepted)
    {
        return;
    }
    document.print(&printer);
}

void Original::printFileTbWidget(QTableWidget *table, QString header, QString name)
{
    QString fullHTML = "";

    fullHTML += name
        + "<br/>"
        + "<html>"
        + "<body>"
        + "<table border='1'>"
        + "<tr>"
        + header
        + "</tr>";

    for(int i = 0; i < table->rowCount(); i++)
    {
        fullHTML += "<tr>";
        for(int j = 0; j < table->columnCount(); j++)
        {
            fullHTML += "<td>"
                + table->item(i,j)->text()
                + "</td>";
        }
        fullHTML += "</tr>";
    }

    fullHTML += "</body>";
    fullHTML += "</html>";


    QPrinter printer;
    QTextDocument document;
    document.setHtml(fullHTML);

    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");

    if(dialog->exec() != QDialog::Accepted)
    {
        return;
    }
    document.print(&printer);
}

void Original::on_btnSaveMC_clicked()
{
    QString header = "<td>ID</td><td>Title</td><td>Type</td><td>DataType</td><td>Category</td><td>Version</td><td>Publisher</td><td>RecordedYear</td><td>Duration</td>";
    saveFileTbView(ui->tbMC,header,"MultimediaCollection");

}

void Original::on_btnSaveMCItem_clicked()
{
    stringstream ssItem;
    ssItem << ui->collection_item_table->model()->rowCount();

    string name = "MultimediaCollectionCopies<br/>Total Items: " + ssItem.str();
    QString finalName = name.c_str();

    QString header = "<td>Barcode</td><td>Status</td>";
    saveFileTbView(ui->collection_item_table,header,finalName);
}

void Original::on_btnSaveMCBorrower_clicked()
{
    stringstream ssBorrower;
    ssBorrower << ui->collection_borrower_table->model()->rowCount();

    string name = "MultimediaCollectionBorrower<br/>Total Borrowers: " + ssBorrower.str();
    QString finalName = name.c_str();

    QString header = "<td>ID</td><td>Name</td><td>MobileNumber</td>";
    saveFileTbView(ui->collection_borrower_table,header,finalName);
}

void Original::on_btnPrintMC_clicked()
{
    QString header = "<td>ID</td><td>Title</td><td>Type</td><td>DataType</td><td>Category</td><td>Version</td><td>Publisher</td><td>RecordedYear</td><td>Duration</td>";
    printFileTbView(ui->tbMC,header,"MultimediaCollection");
}

void Original::on_btnPrintMCItem_clicked()
{
    stringstream ssItem;
    ssItem << ui->collection_item_table->model()->rowCount();
    ui->total_item->setText(ssItem.str().c_str());

    string name = "MultimediaCollectionCopies<br/>Total Items: " + ssItem.str();
    QString finalName = name.c_str();

    QString header = "<td>Barcode</td><td>Status</td>";
    printFileTbView(ui->collection_item_table,header,finalName);
}

void Original::on_btnPrintMCBorrower_clicked()
{
    stringstream ssBorrower;
    ssBorrower << ui->collection_borrower_table->model()->rowCount();

    string name = "MultimediaCollectionBorrower<br/>Total Borrowers: " + ssBorrower.str();
    QString finalName = name.c_str();

    QString header = "<td>ID</td><td>Name</td><td>MobileNumber</td>";
    printFileTbView(ui->collection_borrower_table,header,finalName);
}

void Original::on_btnSaveItem_clicked()
{
    QString header = "";
    QTableWidget *table;

    if(ui->cbInsFilter->currentIndex() == 1)
    {
        header = "<td>Barcode</td><td>Title</td><td>Status</td><td>BorrowingTime</td><td>BorrowedDate</td><td>BorrowingDay</td><td>OverdueDay</td>";
        table = ui->tbIns;
        saveFileTbWidget(table,header,"Items");
    }
    else
    {
        table = new QTableWidget();

        for(int  i = 0; i < ui->tbIns->columnCount()-1; i++)
        {
            table->insertColumn(i);
        }

        for(int i = 0; i < ui->tbIns->rowCount(); i++)
        {
            table->insertRow(i);
            for(int j = 0; j < ui->tbIns->columnCount()-1; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setText(ui->tbIns->item(i,j)->text());
                table->setItem(i,j,item);
            }
        }

        header = "<td>Barcode</td><td>Title</td><td>Status</td><td>BorrowingTime</td><td>BorrowedDate</td><td>BorrowingDay</td>";
        saveFileTbWidget(table,header,"Items");

        for(int i = 0; i < table->rowCount(); i++)
        {
            for(int j = 0; j < table->columnCount(); j++)
            {
                delete table->item(i,j);
            }
        }
        delete table;
    }


}

void Original::on_btnPrintItem_clicked()
{
    QString header = "";
    QTableWidget *table;

    if(ui->cbInsFilter->currentIndex() == 1)
    {
        header = "<td>Barcode</td><td>Title</td><td>Status</td><td>BorrowingTime</td><td>BorrowedDate</td><td>BorrowingDay</td><td>OverdueDay</td>";
        table = ui->tbIns;
        printFileTbWidget(table,header,"Items");
    }
    else
    {
        table = new QTableWidget();

        for(int  i = 0; i < ui->tbIns->columnCount()-1; i++)
        {
            table->insertColumn(i);
        }

        for(int i = 0; i < ui->tbIns->rowCount(); i++)
        {
            table->insertRow(i);
            for(int j = 0; j < ui->tbIns->columnCount()-1; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setText(ui->tbIns->item(i,j)->text());
                table->setItem(i,j,item);
            }
        }

        header = "<td>Barcode</td><td>Title</td><td>Status</td><td>BorrowingTime</td><td>BorrowedDate</td><td>BorrowingDay</td>";
        printFileTbWidget(table,header,"Items");

        for(int i = 0; i < table->rowCount(); i++)
        {
            for(int j = 0; j < table->columnCount(); j++)
            {
                delete table->item(i,j);
            }
        }
        delete table;
    }
}


void Original::on_btnSaveBorrower_clicked()
{
    QString header = "<td>ID</td><td>Name</td><td>Type</td><td>Department</td><td>MobileNumber</td><td>TotalBorrowedItems</td><td>LateReturnedItems</td>";
    saveFileTbWidget(ui->tbBorrower,header,"Borrower");
}

void Original::on_btnPrintBorrower_clicked()
{
    QString header = "<td>ID</td><td>Name</td><td>Type</td><td>Department</td><td>MobileNumber</td><td>TotalBorrowedItems</td><td>LateReturnedItems</td>";
    printFileTbWidget(ui->tbBorrower,header,"Borrower");
}

void Original::on_btnSaveBorrowerItem_clicked()
{
     int currentRow = ui->tbBorrower->currentRow();

    stringstream ssCurrently;
    ssCurrently << ui->borrower_item_table->rowCount();
    stringstream ssPreviously;
    ssPreviously << ui->tbBorrower->item(currentRow,5)->text().toInt() - ui->borrower_item_table->rowCount();

    string name = "BorrowedItem<br/>PreviouslyBorrowed: " + ssPreviously.str() + "<br/>CurrentlyBorrowed: " + ssCurrently.str();
    QString finalName = name.c_str();

    QString header = "<td>Barcode</td><td>BorrowedDate</td><td>BorrowingDay</td><td>Overdue</td>";
    saveFileTbWidget(ui->borrower_item_table,header,finalName);
}

void Original::on_btnPrintBorrowerItem_clicked()
{
    int currentRow = ui->tbBorrower->currentRow();

   stringstream ssCurrently;
   ssCurrently << ui->borrower_item_table->rowCount();
   stringstream ssPreviously;
   ssPreviously << ui->tbBorrower->item(currentRow,5)->text().toInt() - ui->borrower_item_table->rowCount();

   string name = "BorrowedItem<br/>PreviouslyBorrowed: " + ssPreviously.str() + "<br/>CurrentlyBorrowed: " + ssCurrently.str();
   QString finalName = name.c_str();

    QString header = "<td>Barcode</td><td>BorrowedDate</td><td>BorrowingDay</td><td>Overdue</td>";
    printFileTbWidget(ui->borrower_item_table,header,finalName);
}
