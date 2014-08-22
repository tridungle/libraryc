#include "addcollectionform.h"
#include "mcsystem.h"
#include <sstream>

AddCollectionForm::AddCollectionForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCollectionForm)
{
    ui->setupUi(this);
}

AddCollectionForm::~AddCollectionForm()
{
    delete ui;
}

void AddCollectionForm::on_collectionCancel_clicked()
{
    this->close();
}

void AddCollectionForm::on_collectionAdd_clicked()
{

    QSqlQuery qry;

    stringstream ss;
    QString id = ui->id_text->text();
    QString type = ui->cbCollectionType->currentText();
    QString datatype = ui->cbCollectionDataType->currentText();
    QString title = ui->text_title->text();
    QString version = ui->text_version->text();
    QString publisher = ui->text_publisher->text();
    QString recordedYear = ui->dtEditCollectionRecordedYear->text();
    QString duration_hr = ui->sbxCollectionHour->text();
    QString duration_mi = ui->sbxCollectionMinute->text();
    QString duration_se = ui->sbxCollectionSecond->text();
//    ss << duration_hr.toStdString();
    int du_hr;
    istringstream (duration_hr.toStdString()) >> du_hr;


//    ss << duration_mi.toStdString();
    int du_mi;
    istringstream (duration_mi.toStdString()) >> du_mi;


//    ss << duration_se.toStdString();
    int du_se;
    istringstream (duration_se.toStdString()) >> du_se;


    int total = (du_hr *60*60) + (du_mi*60) + du_se;
    ss << total;

    string tempdu = ss.str();
    QString duration = tempdu.c_str();
    QString category = ui->cbCollectionCategory->currentText();

    CollectionType *ct = mc->getCollectionType("",type.toStdString());
    DataType *dt = mc->getDataType("",datatype.toStdString());
    Category *c = mc->getCategory("",category.toStdString());

    MultimediaCollection *tempmc = new MultimediaCollection(ct->getID(),dt->getID(),c->getID(),title.toStdString(),
                                                            version.toStdString(),publisher.toStdString(),recordedYear.toInt(),
                                                            duration.toInt());

    if(this->currentAction.compare("add") == 0)
    {
        tempmc->generateID();
        mc->addMC(tempmc);

    }else
    {
        tempmc->setID(id.toStdString());
        mc->updateMC(tempmc);
    }

    this->close();



    //Using SQL
//    qry.prepare("insert into multimediacollection(type,datatype,category,title,version,publisher,recordedyear, duration)" +
//                " values (:type,:datatype,:category,:title,:version,:publisher,:recordedyear, :duration);");
//    qry.bindValue(":type", type);
//    qry.bindValue(":datatype", datatype);
//    qry.bindValue(":category", category);
//    qry.bindValue(":title", title);
//    qry.bindValue(":version", version);
//    qry.bindValue(":publisher", publisher);
//    qry.bindValue(":recordedyear", recordedYear);
//    qry.bindValue(":duration", duration);
//    qry.exec();

}
