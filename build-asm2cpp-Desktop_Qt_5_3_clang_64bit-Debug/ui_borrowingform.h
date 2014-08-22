/********************************************************************************
** Form generated from reading UI file 'borrowingform.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWINGFORM_H
#define UI_BORROWINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BorrowingForm
{
public:
    QLabel *lbBorrowing;
    QLabel *lbItem;
    QLabel *lbBorrower;
    QLabel *lbBorrowingDay;
    QLineEdit *txtItem;
    QLineEdit *txtBorrower;
    QSpinBox *sbBorrowingDay;
    QPushButton *btnConfirm;
    QPushButton *btnCancel;

    void setupUi(QDialog *BorrowingForm)
    {
        if (BorrowingForm->objectName().isEmpty())
            BorrowingForm->setObjectName(QStringLiteral("BorrowingForm"));
        BorrowingForm->resize(400, 300);
        lbBorrowing = new QLabel(BorrowingForm);
        lbBorrowing->setObjectName(QStringLiteral("lbBorrowing"));
        lbBorrowing->setGeometry(QRect(120, 20, 161, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        lbBorrowing->setFont(font);
        lbItem = new QLabel(BorrowingForm);
        lbItem->setObjectName(QStringLiteral("lbItem"));
        lbItem->setGeometry(QRect(80, 90, 46, 13));
        lbBorrower = new QLabel(BorrowingForm);
        lbBorrower->setObjectName(QStringLiteral("lbBorrower"));
        lbBorrower->setGeometry(QRect(60, 140, 51, 16));
        lbBorrowingDay = new QLabel(BorrowingForm);
        lbBorrowingDay->setObjectName(QStringLiteral("lbBorrowingDay"));
        lbBorrowingDay->setGeometry(QRect(30, 190, 81, 16));
        txtItem = new QLineEdit(BorrowingForm);
        txtItem->setObjectName(QStringLiteral("txtItem"));
        txtItem->setEnabled(false);
        txtItem->setGeometry(QRect(140, 90, 151, 20));
        txtBorrower = new QLineEdit(BorrowingForm);
        txtBorrower->setObjectName(QStringLiteral("txtBorrower"));
        txtBorrower->setEnabled(false);
        txtBorrower->setGeometry(QRect(140, 140, 151, 20));
        sbBorrowingDay = new QSpinBox(BorrowingForm);
        sbBorrowingDay->setObjectName(QStringLiteral("sbBorrowingDay"));
        sbBorrowingDay->setGeometry(QRect(140, 190, 51, 22));
        sbBorrowingDay->setMinimum(1);
        btnConfirm = new QPushButton(BorrowingForm);
        btnConfirm->setObjectName(QStringLiteral("btnConfirm"));
        btnConfirm->setGeometry(QRect(50, 240, 121, 23));
        btnCancel = new QPushButton(BorrowingForm);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(220, 240, 121, 23));

        retranslateUi(BorrowingForm);

        QMetaObject::connectSlotsByName(BorrowingForm);
    } // setupUi

    void retranslateUi(QDialog *BorrowingForm)
    {
        BorrowingForm->setWindowTitle(QApplication::translate("BorrowingForm", "Dialog", 0));
        lbBorrowing->setText(QApplication::translate("BorrowingForm", "Borrowing", 0));
        lbItem->setText(QApplication::translate("BorrowingForm", "Item", 0));
        lbBorrower->setText(QApplication::translate("BorrowingForm", "Borrower", 0));
        lbBorrowingDay->setText(QApplication::translate("BorrowingForm", "Number of day", 0));
        btnConfirm->setText(QApplication::translate("BorrowingForm", "Confirm", 0));
        btnCancel->setText(QApplication::translate("BorrowingForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class BorrowingForm: public Ui_BorrowingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWINGFORM_H
