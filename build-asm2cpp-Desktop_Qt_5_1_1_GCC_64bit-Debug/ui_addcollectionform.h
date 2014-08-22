/********************************************************************************
** Form generated from reading UI file 'addcollectionform.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOLLECTIONFORM_H
#define UI_ADDCOLLECTIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCollectionForm
{
public:
    QLineEdit *text_version;
    QLineEdit *text_title;
    QComboBox *cbCollectionDataType;
    QDateEdit *dtEditCollectionRecordedYear;
    QLineEdit *text_publisher;
    QComboBox *cbCollectionCategory;
    QComboBox *cbCollectionType;
    QPushButton *collectionAdd;
    QLabel *label_title;
    QPushButton *collectionCancel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblCollectionType;
    QLabel *lblCollectionDataType;
    QLabel *lblCollectionTitle;
    QLabel *lblCollectionVersion;
    QLabel *lblCollectionPublisher;
    QLabel *lblCollectionRecordedYear;
    QLabel *lblCollectionDuration;
    QLabel *lblCollectionCategory;
    QSplitter *splitter;
    QSpinBox *sbxCollectionHour;
    QLabel *lblCollectionHour;
    QSpinBox *sbxCollectionMinute;
    QLabel *lblCollectionMinute;
    QSpinBox *sbxCollectionSecond;
    QLabel *lblCollectionSecond;
    QLabel *label;
    QLineEdit *id_text;

    void setupUi(QDialog *AddCollectionForm)
    {
        if (AddCollectionForm->objectName().isEmpty())
            AddCollectionForm->setObjectName(QStringLiteral("AddCollectionForm"));
        AddCollectionForm->resize(416, 535);
        text_version = new QLineEdit(AddCollectionForm);
        text_version->setObjectName(QStringLiteral("text_version"));
        text_version->setGeometry(QRect(160, 250, 151, 20));
        text_title = new QLineEdit(AddCollectionForm);
        text_title->setObjectName(QStringLiteral("text_title"));
        text_title->setGeometry(QRect(160, 200, 151, 20));
        cbCollectionDataType = new QComboBox(AddCollectionForm);
        cbCollectionDataType->setObjectName(QStringLiteral("cbCollectionDataType"));
        cbCollectionDataType->setGeometry(QRect(160, 150, 151, 20));
        dtEditCollectionRecordedYear = new QDateEdit(AddCollectionForm);
        dtEditCollectionRecordedYear->setObjectName(QStringLiteral("dtEditCollectionRecordedYear"));
        dtEditCollectionRecordedYear->setGeometry(QRect(160, 350, 61, 22));
        dtEditCollectionRecordedYear->setMaximumDateTime(QDateTime(QDate(2013, 12, 24), QTime(23, 59, 59)));
        dtEditCollectionRecordedYear->setMinimumDateTime(QDateTime(QDate(1920, 1, 1), QTime(0, 0, 0)));
        dtEditCollectionRecordedYear->setCurrentSection(QDateTimeEdit::YearSection);
        dtEditCollectionRecordedYear->setCalendarPopup(true);
        text_publisher = new QLineEdit(AddCollectionForm);
        text_publisher->setObjectName(QStringLiteral("text_publisher"));
        text_publisher->setGeometry(QRect(160, 300, 151, 20));
        cbCollectionCategory = new QComboBox(AddCollectionForm);
        cbCollectionCategory->setObjectName(QStringLiteral("cbCollectionCategory"));
        cbCollectionCategory->setGeometry(QRect(160, 450, 151, 20));
        cbCollectionType = new QComboBox(AddCollectionForm);
        cbCollectionType->setObjectName(QStringLiteral("cbCollectionType"));
        cbCollectionType->setGeometry(QRect(160, 100, 151, 20));
        cbCollectionType->setFrame(true);
        collectionAdd = new QPushButton(AddCollectionForm);
        collectionAdd->setObjectName(QStringLiteral("collectionAdd"));
        collectionAdd->setGeometry(QRect(70, 490, 111, 23));
        label_title = new QLabel(AddCollectionForm);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(100, 10, 241, 31));
        QFont font;
        font.setPointSize(18);
        label_title->setFont(font);
        collectionCancel = new QPushButton(AddCollectionForm);
        collectionCancel->setObjectName(QStringLiteral("collectionCancel"));
        collectionCancel->setGeometry(QRect(220, 490, 111, 23));
        layoutWidget = new QWidget(AddCollectionForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(31, 90, 118, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lblCollectionType = new QLabel(layoutWidget);
        lblCollectionType->setObjectName(QStringLiteral("lblCollectionType"));

        verticalLayout->addWidget(lblCollectionType);

        lblCollectionDataType = new QLabel(layoutWidget);
        lblCollectionDataType->setObjectName(QStringLiteral("lblCollectionDataType"));

        verticalLayout->addWidget(lblCollectionDataType);

        lblCollectionTitle = new QLabel(layoutWidget);
        lblCollectionTitle->setObjectName(QStringLiteral("lblCollectionTitle"));

        verticalLayout->addWidget(lblCollectionTitle);

        lblCollectionVersion = new QLabel(layoutWidget);
        lblCollectionVersion->setObjectName(QStringLiteral("lblCollectionVersion"));

        verticalLayout->addWidget(lblCollectionVersion);

        lblCollectionPublisher = new QLabel(layoutWidget);
        lblCollectionPublisher->setObjectName(QStringLiteral("lblCollectionPublisher"));

        verticalLayout->addWidget(lblCollectionPublisher);

        lblCollectionRecordedYear = new QLabel(layoutWidget);
        lblCollectionRecordedYear->setObjectName(QStringLiteral("lblCollectionRecordedYear"));

        verticalLayout->addWidget(lblCollectionRecordedYear);

        lblCollectionDuration = new QLabel(layoutWidget);
        lblCollectionDuration->setObjectName(QStringLiteral("lblCollectionDuration"));

        verticalLayout->addWidget(lblCollectionDuration);

        lblCollectionCategory = new QLabel(layoutWidget);
        lblCollectionCategory->setObjectName(QStringLiteral("lblCollectionCategory"));

        verticalLayout->addWidget(lblCollectionCategory);

        splitter = new QSplitter(AddCollectionForm);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(160, 410, 218, 24));
        splitter->setOrientation(Qt::Horizontal);
        sbxCollectionHour = new QSpinBox(splitter);
        sbxCollectionHour->setObjectName(QStringLiteral("sbxCollectionHour"));
        splitter->addWidget(sbxCollectionHour);
        lblCollectionHour = new QLabel(splitter);
        lblCollectionHour->setObjectName(QStringLiteral("lblCollectionHour"));
        splitter->addWidget(lblCollectionHour);
        sbxCollectionMinute = new QSpinBox(splitter);
        sbxCollectionMinute->setObjectName(QStringLiteral("sbxCollectionMinute"));
        splitter->addWidget(sbxCollectionMinute);
        lblCollectionMinute = new QLabel(splitter);
        lblCollectionMinute->setObjectName(QStringLiteral("lblCollectionMinute"));
        splitter->addWidget(lblCollectionMinute);
        sbxCollectionSecond = new QSpinBox(splitter);
        sbxCollectionSecond->setObjectName(QStringLiteral("sbxCollectionSecond"));
        splitter->addWidget(sbxCollectionSecond);
        lblCollectionSecond = new QLabel(splitter);
        lblCollectionSecond->setObjectName(QStringLiteral("lblCollectionSecond"));
        splitter->addWidget(lblCollectionSecond);
        label = new QLabel(AddCollectionForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 45, 31, 31));
        id_text = new QLineEdit(AddCollectionForm);
        id_text->setObjectName(QStringLiteral("id_text"));
        id_text->setEnabled(false);
        id_text->setGeometry(QRect(160, 50, 113, 23));

        retranslateUi(AddCollectionForm);

        QMetaObject::connectSlotsByName(AddCollectionForm);
    } // setupUi

    void retranslateUi(QDialog *AddCollectionForm)
    {
        AddCollectionForm->setWindowTitle(QApplication::translate("AddCollectionForm", "Add Collection", 0));
        text_version->setPlaceholderText(QString());
        text_title->setPlaceholderText(QString());
        dtEditCollectionRecordedYear->setDisplayFormat(QApplication::translate("AddCollectionForm", "yyyy", 0));
        text_publisher->setPlaceholderText(QString());
        collectionAdd->setText(QApplication::translate("AddCollectionForm", "Add", 0));
        label_title->setText(QApplication::translate("AddCollectionForm", "COLLECTION FORM", 0));
        collectionCancel->setText(QApplication::translate("AddCollectionForm", "Cancel", 0));
        lblCollectionType->setText(QApplication::translate("AddCollectionForm", "Type", 0));
        lblCollectionDataType->setText(QApplication::translate("AddCollectionForm", "Data Type", 0));
        lblCollectionTitle->setText(QApplication::translate("AddCollectionForm", "Title", 0));
        lblCollectionVersion->setText(QApplication::translate("AddCollectionForm", "Version", 0));
        lblCollectionPublisher->setText(QApplication::translate("AddCollectionForm", "Publisher", 0));
        lblCollectionRecordedYear->setText(QApplication::translate("AddCollectionForm", "Recorded Year", 0));
        lblCollectionDuration->setText(QApplication::translate("AddCollectionForm", "Duration", 0));
        lblCollectionCategory->setText(QApplication::translate("AddCollectionForm", "Category", 0));
        lblCollectionHour->setText(QApplication::translate("AddCollectionForm", "Hrs", 0));
        lblCollectionMinute->setText(QApplication::translate("AddCollectionForm", "Mins", 0));
        lblCollectionSecond->setText(QApplication::translate("AddCollectionForm", "Secs", 0));
        label->setText(QApplication::translate("AddCollectionForm", "Id:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCollectionForm: public Ui_AddCollectionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOLLECTIONFORM_H
