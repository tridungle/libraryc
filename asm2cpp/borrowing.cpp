#include "borrowing.h"
#include "ui_borrowing.h"

Borrowing::Borrowing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Borrowing)
{
    ui->setupUi(this);
}

Borrowing::~Borrowing()
{
    delete ui;
}
