#ifndef ADDBORROWER_H
#define ADDBORROWER_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include "ui_addborrower.h"

namespace Ui {
class AddBorrower;
}

class AddBorrower : public QDialog
{
    Q_OBJECT

public:

    QLineEdit* getIdText()
    {
        return ui->id_text;
    }

    void setIdText(QLineEdit &type)
    {
        ui->id_text = &type;
    }

    QLineEdit* getNameText()
    {
        return ui->name_text;
    }

    void setNameText(QLineEdit &type)
    {
        ui->name_text = &type;
    }

    QComboBox* getPersonType()
    {
        return ui->type_combobox;
    }

    void setPersonType(QComboBox &type)
    {
        ui->type_combobox = &type;
    }

    QComboBox* getDepartment()
    {
        return ui->department_combobox;
    }

    void setDepartment(QComboBox &type)
    {
        ui->department_combobox = &type;
    }

    QLineEdit* getPhone()
    {
        return ui->phone_text;
    }

    void setPhone(QLineEdit &type)
    {
        ui->phone_text = &type;
    }

    QSpinBox* getBorrowedItem()
    {
        return ui->borrowItem_spin;
    }

    void setBorrowedItem(QSpinBox &type)
    {
        ui->borrowItem_spin = &type;
    }

    QSpinBox* getReturnItem()
    {
        return ui->returnItem_spin;
    }

    void setReturnItem(QSpinBox &type)
    {
        ui->returnItem_spin = &type;
    }

    QPushButton* getClickButton()
    {
        return ui->add_button;
    }

    void setClickButton(QPushButton &type)
    {
        ui->add_button = &type;
    }

    //Nothing
    std::string getCurrentAtion() const
    {
        return this->currentAction;
    }
    void setCurrentAction(const std::string act)
    {
        this->currentAction = act;
    }

    std::string getCurrentClickId() const
    {
        return this->currentClickId;
    }
    void setCurrentClickId(const std::string act)
    {
        this->currentClickId = act;
    }

    explicit AddBorrower(QWidget *parent = 0);
    ~AddBorrower();

private slots:
    void on_cancel_button_clicked();

    void on_add_button_clicked();

private:
    Ui::AddBorrower *ui;
    std::string currentAction;
    std::string currentClickId;
};

#endif // ADDBORROWER_H
