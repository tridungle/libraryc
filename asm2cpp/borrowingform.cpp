#include "borrowingform.h"
#include "ui_borrowingform.h"

BorrowingForm::BorrowingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrowingForm)
{
    ui->setupUi(this);
}

BorrowingForm::~BorrowingForm()
{
    delete ui;
}

void BorrowingForm::on_btnConfirm_clicked()
{
    QString instanceBarcode = ui->txtItem->text();
    QString borrowerID = ui->txtBorrower->text();
    int borrowingDay = stoi(ui->sbBorrowingDay->text().toStdString());

    mc->borrowing(instanceBarcode,borrowerID,borrowingDay);

    this->close();
}

void BorrowingForm::on_btnCancel_clicked()
{
     this->close();
}
