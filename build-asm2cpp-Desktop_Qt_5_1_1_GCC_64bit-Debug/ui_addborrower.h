/********************************************************************************
** Form generated from reading UI file 'addborrower.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBORROWER_H
#define UI_ADDBORROWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddBorrower
{
public:
    QPushButton *add_button;
    QPushButton *cancel_button;
    QLabel *label_title;
    QLineEdit *name_text;
    QComboBox *type_combobox;
    QComboBox *department_combobox;
    QLineEdit *phone_text;
    QSpinBox *borrowItem_spin;
    QSpinBox *returnItem_spin;
    QLabel *lblBorrowedItems_2;
    QLabel *lblBorrowerPhoneNumber_2;
    QLabel *lblBorrowerType_2;
    QLabel *lblBorrowerDepartment_2;
    QLabel *lblBorrowerName_2;
    QLabel *lblReturnedItems_2;
    QLabel *label;
    QLineEdit *id_text;

    void setupUi(QDialog *AddBorrower)
    {
        if (AddBorrower->objectName().isEmpty())
            AddBorrower->setObjectName(QStringLiteral("AddBorrower"));
        AddBorrower->resize(407, 511);
        add_button = new QPushButton(AddBorrower);
        add_button->setObjectName(QStringLiteral("add_button"));
        add_button->setGeometry(QRect(60, 460, 111, 23));
        cancel_button = new QPushButton(AddBorrower);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setGeometry(QRect(210, 460, 111, 23));
        label_title = new QLabel(AddBorrower);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(100, 20, 221, 51));
        QFont font;
        font.setPointSize(18);
        label_title->setFont(font);
        name_text = new QLineEdit(AddBorrower);
        name_text->setObjectName(QStringLiteral("name_text"));
        name_text->setEnabled(true);
        name_text->setGeometry(QRect(211, 130, 125, 23));
        type_combobox = new QComboBox(AddBorrower);
        type_combobox->setObjectName(QStringLiteral("type_combobox"));
        type_combobox->setGeometry(QRect(210, 190, 79, 23));
        department_combobox = new QComboBox(AddBorrower);
        department_combobox->setObjectName(QStringLiteral("department_combobox"));
        department_combobox->setGeometry(QRect(211, 240, 79, 23));
        phone_text = new QLineEdit(AddBorrower);
        phone_text->setObjectName(QStringLiteral("phone_text"));
        phone_text->setEnabled(true);
        phone_text->setGeometry(QRect(210, 290, 125, 23));
        borrowItem_spin = new QSpinBox(AddBorrower);
        borrowItem_spin->setObjectName(QStringLiteral("borrowItem_spin"));
        borrowItem_spin->setEnabled(true);
        borrowItem_spin->setGeometry(QRect(211, 340, 47, 24));
        returnItem_spin = new QSpinBox(AddBorrower);
        returnItem_spin->setObjectName(QStringLiteral("returnItem_spin"));
        returnItem_spin->setGeometry(QRect(211, 400, 47, 24));
        lblBorrowedItems_2 = new QLabel(AddBorrower);
        lblBorrowedItems_2->setObjectName(QStringLiteral("lblBorrowedItems_2"));
        lblBorrowedItems_2->setGeometry(QRect(20, 347, 158, 16));
        lblBorrowerPhoneNumber_2 = new QLabel(AddBorrower);
        lblBorrowerPhoneNumber_2->setObjectName(QStringLiteral("lblBorrowerPhoneNumber_2"));
        lblBorrowerPhoneNumber_2->setGeometry(QRect(90, 295, 90, 16));
        lblBorrowerType_2 = new QLabel(AddBorrower);
        lblBorrowerType_2->setObjectName(QStringLiteral("lblBorrowerType_2"));
        lblBorrowerType_2->setGeometry(QRect(140, 190, 31, 16));
        lblBorrowerDepartment_2 = new QLabel(AddBorrower);
        lblBorrowerDepartment_2->setObjectName(QStringLiteral("lblBorrowerDepartment_2"));
        lblBorrowerDepartment_2->setGeometry(QRect(100, 242, 73, 16));
        lblBorrowerName_2 = new QLabel(AddBorrower);
        lblBorrowerName_2->setObjectName(QStringLiteral("lblBorrowerName_2"));
        lblBorrowerName_2->setGeometry(QRect(130, 132, 36, 21));
        lblReturnedItems_2 = new QLabel(AddBorrower);
        lblReturnedItems_2->setObjectName(QStringLiteral("lblReturnedItems_2"));
        lblReturnedItems_2->setGeometry(QRect(20, 400, 158, 16));
        label = new QLabel(AddBorrower);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 75, 31, 31));
        id_text = new QLineEdit(AddBorrower);
        id_text->setObjectName(QStringLiteral("id_text"));
        id_text->setEnabled(false);
        id_text->setGeometry(QRect(210, 80, 113, 23));

        retranslateUi(AddBorrower);

        QMetaObject::connectSlotsByName(AddBorrower);
    } // setupUi

    void retranslateUi(QDialog *AddBorrower)
    {
        AddBorrower->setWindowTitle(QApplication::translate("AddBorrower", "Borrower", 0));
        add_button->setText(QApplication::translate("AddBorrower", "Add", 0));
        cancel_button->setText(QApplication::translate("AddBorrower", "Cancel", 0));
        label_title->setText(QApplication::translate("AddBorrower", "BORROWER FORM", 0));
        lblBorrowedItems_2->setText(QApplication::translate("AddBorrower", "Previously Borrower Items", 0));
        lblBorrowerPhoneNumber_2->setText(QApplication::translate("AddBorrower", "Phone Number", 0));
        lblBorrowerType_2->setText(QApplication::translate("AddBorrower", "Type", 0));
        lblBorrowerDepartment_2->setText(QApplication::translate("AddBorrower", "Department", 0));
        lblBorrowerName_2->setText(QApplication::translate("AddBorrower", "Name", 0));
        lblReturnedItems_2->setText(QApplication::translate("AddBorrower", "Previously Returned Items", 0));
        label->setText(QApplication::translate("AddBorrower", "Id:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddBorrower: public Ui_AddBorrower {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBORROWER_H
