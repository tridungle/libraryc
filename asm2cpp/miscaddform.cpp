#include "miscaddform.h"
#include "ui_miscaddform.h"
#include <iostream>

MiscAddForm::MiscAddForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MiscAddForm)
{
    ui->setupUi(this);
}

MiscAddForm::~MiscAddForm()
{
    delete ui;
}

void MiscAddForm::on_btnMiscCancel_clicked()
{
    this->close();
}

QString MiscAddForm::getLbMisc() const
{
    return ui->lbMisc->text();
}

void MiscAddForm::setLbMisc(const QString &name)
{
    ui->lbMisc->setText(name);
}

std::string MiscAddForm::getCurrentType() const
{
    return this->currentType;
}

void MiscAddForm::setCurrentType(const std::string type)
{
    this->currentType = type;
}

QString MiscAddForm::getTxtMiscID() const
{
    return ui->txtMiscID->text();
}

void MiscAddForm::setTxtMiscID(const QString &id)
{
    ui->txtMiscID->setText(id);
}

void MiscAddForm::on_btnMiscAdd_clicked()
{
    QString toinsert = ui->txtMiscValue->text();
    QString thisID = ui->txtMiscID->text();

    if(toinsert.compare("") != 0)
    {
        //If Add
        if(currentAction.compare("add") == 0)
        {
            if(currentType.compare("CollectionType") == 0)
            {
                CollectionType *temptype = new CollectionType(toinsert.toStdString());
                temptype->generateID();
                mc->addCollectionType(temptype);
            }else if(currentType.compare("DataType") == 0)
            {
                DataType *temptype = new DataType(toinsert.toStdString());
                temptype->generateID();
                mc->addDataType(temptype);
            }else if(currentType.compare("Category") == 0)
            {
                Category *temptype = new Category(toinsert.toStdString());
                temptype->generateID();
                mc->addCategory(temptype);
            }else if(currentType.compare("Status") == 0)
            {
                Status *temptype = new Status(toinsert.toStdString());
                temptype->generateID();
                mc->addStatus(temptype);
            }else if(currentType.compare("PersonType") == 0)
            {
                PersonType *temptype = new PersonType(toinsert.toStdString());
                temptype->generateID();
                mc->addPersonType(temptype);
            }else if(currentType.compare("Department") == 0)
            {
                Department *temptype = new Department(toinsert.toStdString());
                temptype->generateID();
                mc->addDepartment(temptype);
            }

        }else
            //If Edit
        {
            if(currentType.compare("CollectionType") == 0)
            {
                CollectionType *temptype = new CollectionType(toinsert.toStdString());
                temptype->setID(thisID.toStdString());
                mc->updateCollectionType(temptype);
            }else if(currentType.compare("DataType") == 0)
            {
                DataType *temptype = new DataType(toinsert.toStdString());
                temptype->setID(thisID.toStdString());
                mc->updateDataType(temptype);
            }else if(currentType.compare("Category") == 0)
            {
                Category *temptype = new Category(toinsert.toStdString());
                temptype->setID(thisID.toStdString());
                mc->updateCategory(temptype);
            }else if(currentType.compare("Status") == 0)
            {
                Status *temptype = new Status(toinsert.toStdString());
                temptype->setID(thisID.toStdString());
                mc->updateStatus(temptype);
            }else if(currentType.compare("PersonType") == 0)
            {
                PersonType *temptype = new PersonType(toinsert.toStdString());
                temptype->setID(thisID.toStdString());
                mc->updatePersonType(temptype);
            }else if(currentType.compare("Department") == 0)
            {
                Department *temptype = new Department(toinsert.toStdString());
                temptype->setID(thisID.toStdString());
                mc->updateDepartment(temptype);
            }
        }

        this->close();
    }
}
