#ifndef ADDCOLLECTIONFORM_H
#define ADDCOLLECTIONFORM_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QPushButton>
#include "ui_addcollectionform.h"

namespace Ui {
class AddCollectionForm;
}

class AddCollectionForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddCollectionForm(QWidget *parent = 0);
    ~AddCollectionForm();

    QLineEdit* getIdText()
    {
        return ui->id_text;
    }

    void setIdText(QLineEdit &type)
    {
        ui->id_text = &type;
    }

    QComboBox* getCurrentCollectionType()
    {
        return ui->cbCollectionType;
    }

    void setCurrentCollectionType(QComboBox &type)
    {
        ui->cbCollectionType = &type;
    }

    QComboBox* getCurrentCollectionDataType()
    {
        return ui->cbCollectionDataType;
    }

    void setCurrentCollectionDataType(QComboBox &type)
    {
        ui->cbCollectionDataType = &type;
    }

    QComboBox* getCurrentCategory()
    {
        return ui->cbCollectionCategory;
    }

    void setCurrentCategory(QComboBox &type)
    {
        ui->cbCollectionCategory = &type;
    }

    QLineEdit* getCurrentTitle()
    {
        return ui->text_title;
    }

    void setCurrentTitle(QLineEdit &type)
    {
        ui->text_title = &type;
    }

    QLineEdit* getCurrentVersion()
    {
        return ui->text_version;
    }

    void setCurrentVersion(QLineEdit &type)
    {
        ui->text_version = &type;
    }

    QLineEdit* getCurrentPublisher()
    {
        return ui->text_publisher;
    }

    void setCurrentPublisher(QLineEdit &type)
    {
        ui->text_publisher = &type;
    }

    QDateEdit* getCurrentYearRecorded()
    {
        return ui->dtEditCollectionRecordedYear;
    }

    void setCurrentYearRecorded(QDateEdit &type)
    {
        ui->dtEditCollectionRecordedYear = &type;
    }

    QSpinBox* getCurrentHour()
    {
        return ui->sbxCollectionHour;
    }

    void setCurrentHour(QSpinBox &type)
    {
        ui->sbxCollectionHour = &type;
    }

    QSpinBox* getCurrentMinute()
    {
        return ui->sbxCollectionMinute;
    }

    void setCurrentMinute(QSpinBox &type)
    {
        ui->sbxCollectionMinute = &type;
    }

    QSpinBox* getCurrentSecond()
    {
        return ui->sbxCollectionSecond;
    }

    void setCurrentSecond(QSpinBox &type)
    {
        ui->sbxCollectionSecond = &type;
    }

    QPushButton* getAddButton()
    {
        return ui->collectionAdd;
    }

    void setAddButton(QPushButton &type)
    {
        ui->collectionAdd = &type;
    }

    //NOTHING
    std::string getCurrentType() const
    {
        return this->currentType;
    }
    void setCurrentType(const std::string type)
    {
        this->currentType = type;
    }

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

private slots:
    void on_collectionCancel_clicked();

    void on_collectionAdd_clicked();

private:
    Ui::AddCollectionForm *ui;
    std::string currentType;
    std::string currentAction;
    std::string currentClickId;
};

#endif // ADDCOLLECTIONFORM_H
