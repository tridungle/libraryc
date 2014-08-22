#include "additem.h"
#include "mcsystem.h"
#include <QMessageBox>
#include "ui_additem.h"

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
    ui->barcode_tablewidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->barcode_tablewidget->horizontalHeader()->setStretchLastSection(true);
    ui->barcode_tablewidget->resizeColumnsToContents();
    currentRow = 0;
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_pushButton_2_clicked()
{
    this->close();

}

void AddItem::on_id_combobox_activated(const QString &arg1)
{
    QSqlQuery qry;

    QString type;
    QString datatype;
    QString title;
    QString version;
    QString publisher;
    QString recordedYear;
    QString duration;
    QString category;


    qry.prepare("select * from multimediacollection where multimediacollectionid = :id");
    qry.bindValue(":id",arg1);
    qry.exec();
    while(qry.next())
    {
        type = qry.value(1).toString();
        datatype = qry.value(2).toString();
        category = qry.value(3).toString();
        title = qry.value(4).toString();
        version = qry.value(5).toString();
        publisher = qry.value(6).toString();
        recordedYear = qry.value(7).toString();
        duration = qry.value(8).toString();
    }

    //Collectiontype
    qry.prepare("select * from collectiontype where id = :id;");
    qry.bindValue(":id",type);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        type = tempi;
    }

    //DataType
    qry.prepare("select * from datatype where id = :id;");
    qry.bindValue(":id",datatype);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        datatype = tempi;
    }

    //Category
    qry.prepare("select * from category where id = :id;");
    qry.bindValue(":id",category);
    qry.exec();
    while(qry.next())
    {
        QString tempi = qry.value(1).toString();
        category = tempi;
    }

    ui->type_text->setText(type);
    ui->category_text->setText(category);
    ui->title_text->setText(title);
    ui->record_text->setText(recordedYear);
    ui->datatype_text->setText(datatype);
    ui->version_text->setText(version);
    ui->publisher_text->setText(publisher);
    ui->duration_text->setText(duration);
}

void AddItem::on_copy_spin_valueChanged(int arg1)
{
//    ui->barcode_tablewidget->setSizePolicy(QSizePolicy::horizontalPolicy(),QSizePolicy::verticalPolicy());
//    ui->barcode_tablewidget->setRowCount(arg1);

    if(currentRow < arg1)
    {
        for(int i = currentRow; i < arg1; i++)
        {
            ui->barcode_tablewidget->insertRow(0);

            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText("");
            ui->barcode_tablewidget->setItem(0,0,item);
            currentRow++;
        }
    }else if(currentRow > arg1)
    {
        for(int i = currentRow; i > arg1; i--)
        {
            delete ui->barcode_tablewidget->item(0,0);
            ui->barcode_tablewidget->removeRow(0);
            currentRow--;
        }
    }

//    for(int i = 0; i < arg1; i++)
//    {
//        QTableWidgetItem *item = new QTableWidgetItem(tr(""));
//        ui->barcode_tablewidget->setItem(i,0,item);
//    }
}

void AddItem::on_add_button_clicked()
{
    QSqlQuery qry;

    int tempcopy;
    istringstream(ui->copy_spin->text().toStdString()) >> tempcopy;

    //Check the selected collection id
    if(ui->id_combobox->currentText().compare("") == 0)
    {
        QMessageBox::warning(this,"Warning","Please select a collection id","OK",0);
        return;
    }

    //Check copy value
    if(tempcopy < 1)
    {
        QMessageBox::warning(this,"Warning","Number of copies must be greater than 0","OK",0);
        return;
    }

    QString mcID = ui->id_combobox->currentText();
    QString status = ui->status_combobox->currentText();

    Status *st = mc->getStatus("",status.toStdString());

    if(this->currentAction.compare("add") == 0)
    {
        bool checkBarcode = true;

        //Check empty
        for(int i = 0; i < tempcopy; i++)
        {
            QString barcode = ui->barcode_tablewidget->item(i,0)->text();
            cout << barcode.toStdString() << "\n";
            if(!ui->barcode_tablewidget->item(i,0) || barcode.isEmpty())
            {
                QMessageBox::warning(this,"Warning","Barcode must have value","OK",0);
                checkBarcode = false;
                break;
            }
        }

        if(checkBarcode == true)
        {
            for(int i = 0; i < tempcopy; i++)
            {
                QString barcode = ui->barcode_tablewidget->item(i,0)->text();
                cout << barcode.toStdString() << "\n";
                MCInstance *tempIns = new MCInstance(barcode.toStdString(),st->getID(),
                                                     mcID.toStdString());
                mc->addMCInstance(tempIns);
            }
            this->close();
        }
    }else
    {
        QString barcode = ui->barcode_tablewidget->item(0,0)->text();
        cout << barcode.toStdString() << "\n";
        MCInstance *tempIns = new MCInstance(barcode.toStdString(),st->getID(),
                                             mcID.toStdString());
        mc->updateMCInstance(oldbarcode,tempIns);

        this->close();
    }

}


