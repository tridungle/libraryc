#include "addborrower.h"
#include "mcsystem.h"
#include "ui_addborrower.h"

AddBorrower::AddBorrower(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBorrower)
{
    ui->setupUi(this);
}

AddBorrower::~AddBorrower()
{
    delete ui;
}

void AddBorrower::on_cancel_button_clicked()
{
    this->close();
}

void AddBorrower::on_add_button_clicked()
{
    QSqlQuery qry;

    QString id = ui->id_text->text();
    QString name = ui->name_text->text();
    QString personType =ui->type_combobox->currentText();
    QString department = ui->department_combobox->currentText();
    QString phone = ui->phone_text->text();
    QString borrowItem = ui->borrowItem_spin->text();
    QString returnItem = ui->returnItem_spin->text();

    PersonType *pt = mc->getPersonType("",personType.toStdString());
    Department *depart = mc->getDepartment("",department.toStdString());

    Borrower *tempbo = new Borrower(name.toStdString(),pt->getID(),depart->getID(),phone.toStdString());

    if(this->currentAction.compare("add") == 0)
    {
        tempbo->generateID();
        mc->addBorrower(tempbo);
    }else
    {
        tempbo->setID(id.toStdString());
        int tempBorrow;
        int tempReturn;
        istringstream(borrowItem.toStdString()) >> tempBorrow;
        istringstream(returnItem.toStdString()) >> tempReturn;
        tempbo->setBorrowedItems(tempBorrow);
        tempbo->setLateReturnedItems(tempReturn);
        mc->updateBorrower(tempbo);
    }

    this->close();
}
