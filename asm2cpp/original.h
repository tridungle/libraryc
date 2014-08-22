#ifndef ORIGINAL_H
#define ORIGINAL_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtGui>

#include <string>
#include <sstream>
#include <cmath>

#include "ui_original.h"

#include "mcsystem.h"
#include "addcollectionform.h"
#include "addborrower.h"
#include "additem.h"
#include "miscaddform.h"
#include "borrowingform.h"

namespace Ui {
class Original;
}

class Original : public QMainWindow
{
    Q_OBJECT

public:
    explicit Original(QWidget *parent = 0);
    ~Original();
    QString getLastId(QString tablename);
    void displayTbMC();
    void displayTbMCIns();
    void displayTbBorrower();
    void displayTbOperationInstance();
    void displayTbOperationBorrower();

private slots:
    void on_actionExit_triggered();

    void on_btnMCAdd_clicked();

    void on_cbMisc_activated(const QString &arg1);

    void on_btnMiscAdd_clicked();

    void on_tbIns_clicked(const QModelIndex &index);

    void on_txtMCSearch_textChanged(const QString &arg1);

    void on_cbMCSort_activated(const QString &arg1);

    void on_cbInsSort_activated(const QString &arg1);

    void on_txtInsSearch_textChanged(const QString &arg1);

    void on_cbBorrowerSort_activated(const QString &arg1);

    void on_txtBorrowerSearch_textChanged(const QString &arg1);

    void on_txtOperationInsSearch_textChanged(const QString &arg1);

    void on_tbMC_clicked(const QModelIndex &index);

    void on_btnMCEdit_clicked();

    void on_btnMiscDelete_clicked();

    void on_btnMCDelete_clicked();

    void on_btnOperationBorrowing_clicked();

    void on_txtOperationBorrowerSearch_textChanged(const QString &arg1);

    void on_btnBorrowerAdd_clicked();

    void on_tbMC_activated(const QModelIndex &index);

    void on_tbBorrower_clicked(const QModelIndex &index);

    void on_btnBorrowerDelete_clicked();

    void on_btnBorrowerEdit_clicked();

    void on_btnInsAdd_clicked();

    void on_cbMCFilter_activated(const QString &arg1);

    void on_cbInsFilter_activated(const QString &arg1);

    void on_cbBorrowerFilter_activated(const QString &arg1);

    void on_btnInsEdit_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_btnInsDelete_clicked();

    void on_tbMisc_clicked(const QModelIndex &index);

    void on_btnMiscEdit_clicked();

    void on_btnOperationReturning_clicked();

    void on_collection_item_table_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_cbBorrowerFilter_currentIndexChanged(int index);

    void setDataToTable(const QString query, QTableWidget *table);
    void on_actionAbout_triggered();

    void on_btnSaveMC_clicked();

    void saveFileTbView(QTableView *table, QString header, QString name);

    void saveFileTbWidget(QTableWidget *table, QString header, QString name);

    void printFileTbView(QTableView *table, QString header, QString name);

    void printFileTbWidget(QTableWidget *table, QString header, QString name);

    void on_btnSaveMCItem_clicked();

    void on_btnSaveMCBorrower_clicked();

    void on_btnPrintMC_clicked();

    void on_btnPrintMCItem_clicked();

    void on_btnPrintMCBorrower_clicked();

    void on_btnSaveItem_clicked();

    void on_btnSaveBorrower_clicked();

    void on_btnPrintItem_clicked();

    void on_btnPrintBorrower_clicked();

    void on_btnSaveBorrowerItem_clicked();

    void on_btnPrintBorrowerItem_clicked();

private:
    Ui::Original *ui;
    std::string misc_value;
    std::string mc_value;
    std::string bo_value;
    std::string ins_value;
    std::string misc_click;
    QString mcQuery;
    QString borrowerQuery;
    QString mcInsQuery;
    QString operationInsQuery;
    QString operationBorrowerQuery;
    QString overdueBorrowerQuery;
    QSqlQueryModel *getModel(const QString &query);
};

#endif // ORIGINAL_H
