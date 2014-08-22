/********************************************************************************
** Form generated from reading UI file 'additem.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEM_H
#define UI_ADDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_AddItem
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *id_combobox;
    QPushButton *add_button;
    QPushButton *pushButton_2;
    QTableWidget *barcode_tablewidget;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line;
    QLabel *label_11;
    QComboBox *status_combobox;
    QLabel *label_15;
    QSpinBox *copy_spin;
    QLabel *type_text;
    QLabel *category_text;
    QLabel *title_text;
    QLabel *record_text;
    QLabel *datatype_text;
    QLabel *version_text;
    QLabel *publisher_text;
    QLabel *duration_text;

    void setupUi(QDialog *AddItem)
    {
        if (AddItem->objectName().isEmpty())
            AddItem->setObjectName(QStringLiteral("AddItem"));
        AddItem->resize(449, 551);
        label = new QLabel(AddItem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 0, 141, 51));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label_2 = new QLabel(AddItem);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(42, 62, 17, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Open Sans"));
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        id_combobox = new QComboBox(AddItem);
        id_combobox->setObjectName(QStringLiteral("id_combobox"));
        id_combobox->setGeometry(QRect(140, 60, 91, 23));
        add_button = new QPushButton(AddItem);
        add_button->setObjectName(QStringLiteral("add_button"));
        add_button->setGeometry(QRect(100, 500, 91, 31));
        pushButton_2 = new QPushButton(AddItem);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 500, 91, 31));
        barcode_tablewidget = new QTableWidget(AddItem);
        if (barcode_tablewidget->columnCount() < 1)
            barcode_tablewidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        barcode_tablewidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        barcode_tablewidget->setObjectName(QStringLiteral("barcode_tablewidget"));
        barcode_tablewidget->setGeometry(QRect(260, 320, 111, 161));
        label_3 = new QLabel(AddItem);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(42, 100, 32, 16));
        label_3->setFont(font1);
        label_4 = new QLabel(AddItem);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 100, 64, 16));
        label_4->setFont(font1);
        label_5 = new QLabel(AddItem);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(42, 140, 55, 16));
        label_5->setFont(font1);
        label_6 = new QLabel(AddItem);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(42, 180, 34, 16));
        label_6->setFont(font1);
        label_7 = new QLabel(AddItem);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 140, 44, 16));
        label_7->setFont(font1);
        label_8 = new QLabel(AddItem);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(260, 180, 56, 16));
        label_8->setFont(font1);
        label_9 = new QLabel(AddItem);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(42, 220, 81, 16));
        label_9->setFont(font1);
        label_10 = new QLabel(AddItem);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(260, 220, 53, 16));
        label_10->setFont(font1);
        line = new QFrame(AddItem);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(30, 250, 391, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_11 = new QLabel(AddItem);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 270, 51, 21));
        status_combobox = new QComboBox(AddItem);
        status_combobox->setObjectName(QStringLiteral("status_combobox"));
        status_combobox->setGeometry(QRect(260, 270, 131, 23));
        label_15 = new QLabel(AddItem);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(90, 380, 57, 21));
        copy_spin = new QSpinBox(AddItem);
        copy_spin->setObjectName(QStringLiteral("copy_spin"));
        copy_spin->setGeometry(QRect(140, 380, 61, 24));
        type_text = new QLabel(AddItem);
        type_text->setObjectName(QStringLiteral("type_text"));
        type_text->setGeometry(QRect(140, 100, 101, 16));
        category_text = new QLabel(AddItem);
        category_text->setObjectName(QStringLiteral("category_text"));
        category_text->setGeometry(QRect(140, 140, 101, 16));
        title_text = new QLabel(AddItem);
        title_text->setObjectName(QStringLiteral("title_text"));
        title_text->setGeometry(QRect(140, 180, 101, 16));
        record_text = new QLabel(AddItem);
        record_text->setObjectName(QStringLiteral("record_text"));
        record_text->setGeometry(QRect(140, 220, 101, 16));
        datatype_text = new QLabel(AddItem);
        datatype_text->setObjectName(QStringLiteral("datatype_text"));
        datatype_text->setGeometry(QRect(340, 100, 91, 16));
        version_text = new QLabel(AddItem);
        version_text->setObjectName(QStringLiteral("version_text"));
        version_text->setGeometry(QRect(340, 140, 91, 16));
        publisher_text = new QLabel(AddItem);
        publisher_text->setObjectName(QStringLiteral("publisher_text"));
        publisher_text->setGeometry(QRect(340, 180, 91, 16));
        duration_text = new QLabel(AddItem);
        duration_text->setObjectName(QStringLiteral("duration_text"));
        duration_text->setGeometry(QRect(340, 220, 91, 16));

        retranslateUi(AddItem);

        QMetaObject::connectSlotsByName(AddItem);
    } // setupUi

    void retranslateUi(QDialog *AddItem)
    {
        AddItem->setWindowTitle(QApplication::translate("AddItem", "Item", 0));
        label->setText(QApplication::translate("AddItem", "ITEM FORM", 0));
        label_2->setText(QApplication::translate("AddItem", "ID:", 0));
        id_combobox->clear();
        id_combobox->insertItems(0, QStringList()
         << QString()
        );
        add_button->setText(QApplication::translate("AddItem", "Add", 0));
        pushButton_2->setText(QApplication::translate("AddItem", "Cancel", 0));
        QTableWidgetItem *___qtablewidgetitem = barcode_tablewidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AddItem", "Barcode", 0));
        label_3->setText(QApplication::translate("AddItem", "Type:", 0));
        label_4->setText(QApplication::translate("AddItem", "Data type:", 0));
        label_5->setText(QApplication::translate("AddItem", "Category:", 0));
        label_6->setText(QApplication::translate("AddItem", "Title: ", 0));
        label_7->setText(QApplication::translate("AddItem", "Version:", 0));
        label_8->setText(QApplication::translate("AddItem", "Publisher:", 0));
        label_9->setText(QApplication::translate("AddItem", "RecordYear:", 0));
        label_10->setText(QApplication::translate("AddItem", "Duration:", 0));
        label_11->setText(QApplication::translate("AddItem", "Status:", 0));
        label_15->setText(QApplication::translate("AddItem", "Copy:", 0));
        type_text->setText(QString());
        category_text->setText(QString());
        title_text->setText(QString());
        record_text->setText(QString());
        datatype_text->setText(QString());
        version_text->setText(QString());
        publisher_text->setText(QString());
        duration_text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddItem: public Ui_AddItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEM_H
