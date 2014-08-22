#ifndef BORROWINGFORM_H
#define BORROWINGFORM_H

#include <QDialog>
#include "ui_borrowingform.h"
#include "mcsystem.h"

namespace Ui {
class BorrowingForm;
}

class BorrowingForm : public QDialog
{
    Q_OBJECT

public:
    QLineEdit* getTxtItem(){
        return ui->txtItem;
    }

    QLineEdit* getTxtBorrower(){
        return ui->txtBorrower;
    }

    explicit BorrowingForm(QWidget *parent = 0);
    ~BorrowingForm();

private slots:
    void on_btnConfirm_clicked();
    void on_btnCancel_clicked();

private:
    Ui::BorrowingForm *ui;
};

#endif // BORROWINGFORM_H
