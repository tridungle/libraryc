/********************************************************************************
** Form generated from reading UI file 'miscaddform.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISCADDFORM_H
#define UI_MISCADDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MiscAddForm
{
public:
    QLabel *lbMisc;
    QLabel *lbMiscID;
    QLabel *lbMiscValue;
    QLineEdit *txtMiscID;
    QLineEdit *txtMiscValue;
    QPushButton *btnMiscAdd;
    QPushButton *btnMiscCancel;

    void setupUi(QDialog *MiscAddForm)
    {
        if (MiscAddForm->objectName().isEmpty())
            MiscAddForm->setObjectName(QStringLiteral("MiscAddForm"));
        MiscAddForm->resize(325, 192);
        lbMisc = new QLabel(MiscAddForm);
        lbMisc->setObjectName(QStringLiteral("lbMisc"));
        lbMisc->setGeometry(QRect(110, 10, 211, 51));
        QFont font;
        font.setPointSize(16);
        lbMisc->setFont(font);
        lbMiscID = new QLabel(MiscAddForm);
        lbMiscID->setObjectName(QStringLiteral("lbMiscID"));
        lbMiscID->setGeometry(QRect(70, 70, 31, 21));
        lbMiscValue = new QLabel(MiscAddForm);
        lbMiscValue->setObjectName(QStringLiteral("lbMiscValue"));
        lbMiscValue->setGeometry(QRect(20, 110, 81, 21));
        txtMiscID = new QLineEdit(MiscAddForm);
        txtMiscID->setObjectName(QStringLiteral("txtMiscID"));
        txtMiscID->setEnabled(false);
        txtMiscID->setGeometry(QRect(120, 70, 171, 23));
        txtMiscValue = new QLineEdit(MiscAddForm);
        txtMiscValue->setObjectName(QStringLiteral("txtMiscValue"));
        txtMiscValue->setGeometry(QRect(120, 110, 171, 23));
        btnMiscAdd = new QPushButton(MiscAddForm);
        btnMiscAdd->setObjectName(QStringLiteral("btnMiscAdd"));
        btnMiscAdd->setGeometry(QRect(50, 150, 81, 31));
        btnMiscCancel = new QPushButton(MiscAddForm);
        btnMiscCancel->setObjectName(QStringLiteral("btnMiscCancel"));
        btnMiscCancel->setGeometry(QRect(180, 150, 81, 31));

        retranslateUi(MiscAddForm);

        QMetaObject::connectSlotsByName(MiscAddForm);
    } // setupUi

    void retranslateUi(QDialog *MiscAddForm)
    {
        MiscAddForm->setWindowTitle(QApplication::translate("MiscAddForm", "Dialog", 0));
        lbMisc->setText(QApplication::translate("MiscAddForm", "MISC FORM", 0));
        lbMiscID->setText(QApplication::translate("MiscAddForm", "Id:", 0));
        lbMiscValue->setText(QApplication::translate("MiscAddForm", "New value:", 0));
        btnMiscAdd->setText(QApplication::translate("MiscAddForm", "Add", 0));
        btnMiscCancel->setText(QApplication::translate("MiscAddForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class MiscAddForm: public Ui_MiscAddForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISCADDFORM_H
