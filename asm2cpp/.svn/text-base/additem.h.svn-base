#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QTableWidget>
#include <ui_additem.h>

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = 0);
    ~AddItem();

    QComboBox* getMcId()
    {
        return ui->id_combobox;
    }

    void setMcId(QComboBox &type)
    {
        ui->id_combobox = &type;
    }

    QLabel* getType()
    {
        return ui->type_text;
    }

    void setType(QLabel &type)
    {
        ui->type_text = &type;
    }

    //Category
    QLabel* getCategory()
    {
        return ui->category_text;
    }

    void setCategory(QLabel &type)
    {
        ui->category_text = &type;
    }

    //Title
    QLabel* getTitle()
    {
        return ui->title_text;
    }

    void setTitle(QLabel &type)
    {
        ui->title_text = &type;
    }

    //Recordyear
    QLabel* getRecordedYear()
    {
        return ui->record_text;
    }

    void setRecordedYear(QLabel &type)
    {
        ui->record_text = &type;
    }

    //Datatype
    QLabel* getDataType()
    {
        return ui->datatype_text;
    }

    void setDataType(QLabel &type)
    {
        ui->datatype_text = &type;
    }

    //Version

    QLabel* getVersion()
    {
        return ui->version_text;
    }

    void setVersion(QLabel &type)
    {
        ui->version_text = &type;
    }

    //Publisher

    QLabel* getPublisher()
    {
        return ui->publisher_text;
    }

    void setPublisher(QLabel &type)
    {
        ui->publisher_text = &type;
    }

    //Duration
    QLabel* getDuration()
    {
        return ui->duration_text;
    }

    void setDuration(QLabel &type)
    {
        ui->duration_text = &type;
    }

    //Status

    QComboBox* getStatus()
    {
        return ui->status_combobox;
    }

    void setStatus(QComboBox &type)
    {
        ui->status_combobox = &type;
    }

    //Copies
    QSpinBox* getCopy()
    {
        return ui->copy_spin;
    }

    void setCopy(QSpinBox &type)
    {
        ui->copy_spin = &type;
    }

    //Tablewidget
    QTableWidget* getBarcodeTable()
    {
        return ui->barcode_tablewidget;
    }

    void setBarcodeTable(QTableWidget &type)
    {
        ui->barcode_tablewidget = &type;
    }

    //Add button
    QPushButton* getAddButton()
    {
        return ui->add_button;
    }

    void setAddButton(QPushButton &type)
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

    Ui::AddItem* getUI()
    {
        return this->ui;
    }

    QString getOldBarcode()
    {
        return oldbarcode;
    }

    void setOldBarcode(QString &type)
    {
        oldbarcode = type;
    }

private slots:
    void on_pushButton_2_clicked();

    void on_id_combobox_activated(const QString &arg1);

    void on_copy_spin_valueChanged(int arg1);

    void on_add_button_clicked();


private:
    Ui::AddItem *ui;
    std::string currentAction;
    std::string currentClickId;
    int currentRow;
    QString oldbarcode;
};

#endif // ADDITEM_H
