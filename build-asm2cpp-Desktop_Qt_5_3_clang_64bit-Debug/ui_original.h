/********************************************************************************
** Form generated from reading UI file 'original.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORIGINAL_H
#define UI_ORIGINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Original
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tabMC;
    QPushButton *btnMCAdd;
    QPushButton *btnMCEdit;
    QPushButton *btnMCDelete;
    QTableView *tbMC;
    QLabel *lbMCSort;
    QComboBox *cbMCSort;
    QLineEdit *txtMCSearch;
    QLabel *lbInsBorrower_2;
    QTableView *collection_borrower_table;
    QLabel *lbInsBorrower_3;
    QLabel *lbMCFilter;
    QComboBox *cbMCFilter;
    QTableView *collection_item_table;
    QLabel *label;
    QLabel *total_item;
    QLabel *label_4;
    QLabel *total_borrower;
    QPushButton *pushButton;
    QPushButton *btnSaveMC;
    QPushButton *btnPrintMC;
    QPushButton *btnPrintMCItem;
    QPushButton *btnSaveMCItem;
    QPushButton *btnSaveMCBorrower;
    QPushButton *btnPrintMCBorrower;
    QWidget *tabIns;
    QPushButton *btnInsAdd;
    QPushButton *btnInsEdit;
    QPushButton *btnInsDelete;
    QLineEdit *txtInsSearch;
    QLabel *lbInsSort;
    QComboBox *cbInsSort;
    QLabel *lbInsBorrower;
    QFrame *line;
    QLabel *lbInsCollection;
    QLabel *lbInsFilter;
    QComboBox *cbInsFilter;
    QTableWidget *tbIns;
    QTableView *item_collection_table;
    QTableView *item_borrower_table;
    QPushButton *btnSaveItem;
    QPushButton *btnPrintItem;
    QWidget *tabBorrower;
    QPushButton *btnBorrowerAdd;
    QPushButton *btnBorrowerEdit;
    QPushButton *btnBorrowerDelete;
    QComboBox *cbBorrowerSort;
    QLabel *lbBorrowerSort;
    QLineEdit *txtBorrowerSearch;
    QLabel *label_3;
    QLabel *lbBorrowerFilter;
    QComboBox *cbBorrowerFilter;
    QLabel *lblPreviously;
    QLabel *lbCurrently;
    QLabel *lblPreviouslyBorrowed;
    QLabel *lblCurrentlyBorrowed;
    QTableWidget *tbBorrower;
    QPushButton *btnSaveBorrower;
    QPushButton *btnPrintBorrower;
    QPushButton *btnSaveBorrowerItem;
    QPushButton *btnPrintBorrowerItem;
    QTableWidget *borrower_item_table;
    QWidget *tabMisc;
    QComboBox *cbMisc;
    QTableView *tbMisc;
    QPushButton *btnMiscAdd;
    QPushButton *btnMiscEdit;
    QPushButton *btnMiscDelete;
    QLineEdit *txtMiscSearch;
    QWidget *tabOperation;
    QTableView *tbOperationInstance;
    QLabel *lbOperationIns;
    QPushButton *btnOperationBorrowing;
    QPushButton *btnOperationReturning;
    QLineEdit *txtOperationInsSearch;
    QTableView *tbOperationBorrower;
    QLineEdit *txtOperationBorrowerSearch;
    QLabel *lbOperationBorrower;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Original)
    {
        if (Original->objectName().isEmpty())
            Original->setObjectName(QStringLiteral("Original"));
        Original->resize(1159, 588);
        actionExit = new QAction(Original);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(Original);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralwidget = new QWidget(Original);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1161, 541));
        tabMC = new QWidget();
        tabMC->setObjectName(QStringLiteral("tabMC"));
        btnMCAdd = new QPushButton(tabMC);
        btnMCAdd->setObjectName(QStringLiteral("btnMCAdd"));
        btnMCAdd->setGeometry(QRect(10, 10, 61, 31));
        btnMCEdit = new QPushButton(tabMC);
        btnMCEdit->setObjectName(QStringLiteral("btnMCEdit"));
        btnMCEdit->setGeometry(QRect(80, 10, 61, 31));
        btnMCDelete = new QPushButton(tabMC);
        btnMCDelete->setObjectName(QStringLiteral("btnMCDelete"));
        btnMCDelete->setGeometry(QRect(140, 10, 61, 31));
        tbMC = new QTableView(tabMC);
        tbMC->setObjectName(QStringLiteral("tbMC"));
        tbMC->setGeometry(QRect(0, 50, 911, 461));
        lbMCSort = new QLabel(tabMC);
        lbMCSort->setObjectName(QStringLiteral("lbMCSort"));
        lbMCSort->setGeometry(QRect(440, 10, 41, 31));
        cbMCSort = new QComboBox(tabMC);
        cbMCSort->setObjectName(QStringLiteral("cbMCSort"));
        cbMCSort->setGeometry(QRect(470, 10, 101, 31));
        txtMCSearch = new QLineEdit(tabMC);
        txtMCSearch->setObjectName(QStringLiteral("txtMCSearch"));
        txtMCSearch->setGeometry(QRect(740, 10, 171, 31));
        lbInsBorrower_2 = new QLabel(tabMC);
        lbInsBorrower_2->setObjectName(QStringLiteral("lbInsBorrower_2"));
        lbInsBorrower_2->setGeometry(QRect(910, 260, 181, 41));
        QFont font;
        font.setPointSize(16);
        lbInsBorrower_2->setFont(font);
        collection_borrower_table = new QTableView(tabMC);
        collection_borrower_table->setObjectName(QStringLiteral("collection_borrower_table"));
        collection_borrower_table->setGeometry(QRect(920, 330, 231, 181));
        lbInsBorrower_3 = new QLabel(tabMC);
        lbInsBorrower_3->setObjectName(QStringLiteral("lbInsBorrower_3"));
        lbInsBorrower_3->setGeometry(QRect(950, 0, 181, 41));
        lbInsBorrower_3->setFont(font);
        lbMCFilter = new QLabel(tabMC);
        lbMCFilter->setObjectName(QStringLiteral("lbMCFilter"));
        lbMCFilter->setGeometry(QRect(580, 10, 71, 31));
        cbMCFilter = new QComboBox(tabMC);
        cbMCFilter->setObjectName(QStringLiteral("cbMCFilter"));
        cbMCFilter->setGeometry(QRect(640, 10, 101, 31));
        collection_item_table = new QTableView(tabMC);
        collection_item_table->setObjectName(QStringLiteral("collection_item_table"));
        collection_item_table->setGeometry(QRect(920, 70, 231, 181));
        label = new QLabel(tabMC);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(950, 40, 91, 16));
        total_item = new QLabel(tabMC);
        total_item->setObjectName(QStringLiteral("total_item"));
        total_item->setGeometry(QRect(1050, 40, 57, 16));
        label_4 = new QLabel(tabMC);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(950, 300, 91, 16));
        total_borrower = new QLabel(tabMC);
        total_borrower->setObjectName(QStringLiteral("total_borrower"));
        total_borrower->setGeometry(QRect(1050, 300, 57, 16));
        pushButton = new QPushButton(tabMC);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 10, 101, 31));
        btnSaveMC = new QPushButton(tabMC);
        btnSaveMC->setObjectName(QStringLiteral("btnSaveMC"));
        btnSaveMC->setGeometry(QRect(300, 10, 61, 31));
        btnPrintMC = new QPushButton(tabMC);
        btnPrintMC->setObjectName(QStringLiteral("btnPrintMC"));
        btnPrintMC->setGeometry(QRect(370, 10, 61, 31));
        btnPrintMCItem = new QPushButton(tabMC);
        btnPrintMCItem->setObjectName(QStringLiteral("btnPrintMCItem"));
        btnPrintMCItem->setGeometry(QRect(1090, 10, 61, 31));
        btnSaveMCItem = new QPushButton(tabMC);
        btnSaveMCItem->setObjectName(QStringLiteral("btnSaveMCItem"));
        btnSaveMCItem->setGeometry(QRect(1020, 10, 61, 31));
        btnSaveMCBorrower = new QPushButton(tabMC);
        btnSaveMCBorrower->setObjectName(QStringLiteral("btnSaveMCBorrower"));
        btnSaveMCBorrower->setGeometry(QRect(1030, 270, 61, 31));
        btnPrintMCBorrower = new QPushButton(tabMC);
        btnPrintMCBorrower->setObjectName(QStringLiteral("btnPrintMCBorrower"));
        btnPrintMCBorrower->setGeometry(QRect(1100, 270, 61, 31));
        tabWidget->addTab(tabMC, QString());
        btnMCDelete->raise();
        btnMCAdd->raise();
        btnMCEdit->raise();
        tbMC->raise();
        lbMCSort->raise();
        cbMCSort->raise();
        txtMCSearch->raise();
        lbInsBorrower_2->raise();
        collection_borrower_table->raise();
        lbInsBorrower_3->raise();
        lbMCFilter->raise();
        cbMCFilter->raise();
        collection_item_table->raise();
        label->raise();
        total_item->raise();
        label_4->raise();
        total_borrower->raise();
        pushButton->raise();
        btnSaveMC->raise();
        btnPrintMC->raise();
        btnPrintMCItem->raise();
        btnSaveMCItem->raise();
        btnSaveMCBorrower->raise();
        btnPrintMCBorrower->raise();
        tabIns = new QWidget();
        tabIns->setObjectName(QStringLiteral("tabIns"));
        btnInsAdd = new QPushButton(tabIns);
        btnInsAdd->setObjectName(QStringLiteral("btnInsAdd"));
        btnInsAdd->setGeometry(QRect(10, 10, 51, 31));
        btnInsEdit = new QPushButton(tabIns);
        btnInsEdit->setObjectName(QStringLiteral("btnInsEdit"));
        btnInsEdit->setGeometry(QRect(70, 10, 51, 31));
        btnInsDelete = new QPushButton(tabIns);
        btnInsDelete->setObjectName(QStringLiteral("btnInsDelete"));
        btnInsDelete->setGeometry(QRect(130, 10, 51, 31));
        txtInsSearch = new QLineEdit(tabIns);
        txtInsSearch->setObjectName(QStringLiteral("txtInsSearch"));
        txtInsSearch->setEnabled(true);
        txtInsSearch->setGeometry(QRect(630, 10, 161, 31));
        lbInsSort = new QLabel(tabIns);
        lbInsSort->setObjectName(QStringLiteral("lbInsSort"));
        lbInsSort->setGeometry(QRect(330, 10, 41, 31));
        cbInsSort = new QComboBox(tabIns);
        cbInsSort->setObjectName(QStringLiteral("cbInsSort"));
        cbInsSort->setGeometry(QRect(360, 10, 101, 31));
        lbInsBorrower = new QLabel(tabIns);
        lbInsBorrower->setObjectName(QStringLiteral("lbInsBorrower"));
        lbInsBorrower->setGeometry(QRect(890, 10, 161, 31));
        QFont font1;
        font1.setPointSize(18);
        lbInsBorrower->setFont(font1);
        line = new QFrame(tabIns);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(790, 250, 351, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lbInsCollection = new QLabel(tabIns);
        lbInsCollection->setObjectName(QStringLiteral("lbInsCollection"));
        lbInsCollection->setGeometry(QRect(890, 270, 161, 31));
        lbInsCollection->setFont(font1);
        lbInsFilter = new QLabel(tabIns);
        lbInsFilter->setObjectName(QStringLiteral("lbInsFilter"));
        lbInsFilter->setGeometry(QRect(470, 10, 61, 31));
        cbInsFilter = new QComboBox(tabIns);
        cbInsFilter->setObjectName(QStringLiteral("cbInsFilter"));
        cbInsFilter->setGeometry(QRect(530, 10, 101, 31));
        tbIns = new QTableWidget(tabIns);
        if (tbIns->columnCount() < 7)
            tbIns->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbIns->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbIns->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbIns->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbIns->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tbIns->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tbIns->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tbIns->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tbIns->setObjectName(QStringLiteral("tbIns"));
        tbIns->setGeometry(QRect(0, 50, 791, 461));
        item_collection_table = new QTableView(tabIns);
        item_collection_table->setObjectName(QStringLiteral("item_collection_table"));
        item_collection_table->setGeometry(QRect(800, 50, 351, 192));
        item_borrower_table = new QTableView(tabIns);
        item_borrower_table->setObjectName(QStringLiteral("item_borrower_table"));
        item_borrower_table->setGeometry(QRect(800, 310, 351, 192));
        btnSaveItem = new QPushButton(tabIns);
        btnSaveItem->setObjectName(QStringLiteral("btnSaveItem"));
        btnSaveItem->setGeometry(QRect(190, 10, 61, 31));
        btnPrintItem = new QPushButton(tabIns);
        btnPrintItem->setObjectName(QStringLiteral("btnPrintItem"));
        btnPrintItem->setGeometry(QRect(260, 10, 61, 31));
        tabWidget->addTab(tabIns, QString());
        tabBorrower = new QWidget();
        tabBorrower->setObjectName(QStringLiteral("tabBorrower"));
        btnBorrowerAdd = new QPushButton(tabBorrower);
        btnBorrowerAdd->setObjectName(QStringLiteral("btnBorrowerAdd"));
        btnBorrowerAdd->setGeometry(QRect(10, 10, 51, 31));
        btnBorrowerEdit = new QPushButton(tabBorrower);
        btnBorrowerEdit->setObjectName(QStringLiteral("btnBorrowerEdit"));
        btnBorrowerEdit->setGeometry(QRect(60, 10, 51, 31));
        btnBorrowerDelete = new QPushButton(tabBorrower);
        btnBorrowerDelete->setObjectName(QStringLiteral("btnBorrowerDelete"));
        btnBorrowerDelete->setGeometry(QRect(110, 10, 51, 31));
        cbBorrowerSort = new QComboBox(tabBorrower);
        cbBorrowerSort->setObjectName(QStringLiteral("cbBorrowerSort"));
        cbBorrowerSort->setGeometry(QRect(300, 10, 121, 31));
        lbBorrowerSort = new QLabel(tabBorrower);
        lbBorrowerSort->setObjectName(QStringLiteral("lbBorrowerSort"));
        lbBorrowerSort->setGeometry(QRect(270, 10, 41, 31));
        txtBorrowerSearch = new QLineEdit(tabBorrower);
        txtBorrowerSearch->setObjectName(QStringLiteral("txtBorrowerSearch"));
        txtBorrowerSearch->setGeometry(QRect(610, 10, 161, 31));
        label_3 = new QLabel(tabBorrower);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(790, 40, 221, 41));
        label_3->setFont(font);
        lbBorrowerFilter = new QLabel(tabBorrower);
        lbBorrowerFilter->setObjectName(QStringLiteral("lbBorrowerFilter"));
        lbBorrowerFilter->setGeometry(QRect(430, 10, 51, 31));
        cbBorrowerFilter = new QComboBox(tabBorrower);
        cbBorrowerFilter->setObjectName(QStringLiteral("cbBorrowerFilter"));
        cbBorrowerFilter->setGeometry(QRect(490, 10, 121, 31));
        lblPreviously = new QLabel(tabBorrower);
        lblPreviously->setObjectName(QStringLiteral("lblPreviously"));
        lblPreviously->setGeometry(QRect(800, 100, 111, 20));
        lbCurrently = new QLabel(tabBorrower);
        lbCurrently->setObjectName(QStringLiteral("lbCurrently"));
        lbCurrently->setGeometry(QRect(800, 130, 111, 20));
        lblPreviouslyBorrowed = new QLabel(tabBorrower);
        lblPreviouslyBorrowed->setObjectName(QStringLiteral("lblPreviouslyBorrowed"));
        lblPreviouslyBorrowed->setGeometry(QRect(930, 100, 111, 20));
        lblCurrentlyBorrowed = new QLabel(tabBorrower);
        lblCurrentlyBorrowed->setObjectName(QStringLiteral("lblCurrentlyBorrowed"));
        lblCurrentlyBorrowed->setGeometry(QRect(930, 130, 111, 20));
        tbBorrower = new QTableWidget(tabBorrower);
        if (tbBorrower->columnCount() < 7)
            tbBorrower->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tbBorrower->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tbBorrower->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tbBorrower->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tbBorrower->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tbBorrower->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tbBorrower->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tbBorrower->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        tbBorrower->setObjectName(QStringLiteral("tbBorrower"));
        tbBorrower->setGeometry(QRect(0, 50, 771, 461));
        btnSaveBorrower = new QPushButton(tabBorrower);
        btnSaveBorrower->setObjectName(QStringLiteral("btnSaveBorrower"));
        btnSaveBorrower->setGeometry(QRect(160, 10, 51, 31));
        btnPrintBorrower = new QPushButton(tabBorrower);
        btnPrintBorrower->setObjectName(QStringLiteral("btnPrintBorrower"));
        btnPrintBorrower->setGeometry(QRect(210, 10, 51, 31));
        btnSaveBorrowerItem = new QPushButton(tabBorrower);
        btnSaveBorrowerItem->setObjectName(QStringLiteral("btnSaveBorrowerItem"));
        btnSaveBorrowerItem->setGeometry(QRect(980, 40, 81, 31));
        btnPrintBorrowerItem = new QPushButton(tabBorrower);
        btnPrintBorrowerItem->setObjectName(QStringLiteral("btnPrintBorrowerItem"));
        btnPrintBorrowerItem->setGeometry(QRect(1070, 40, 81, 31));
        borrower_item_table = new QTableWidget(tabBorrower);
        if (borrower_item_table->columnCount() < 4)
            borrower_item_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        borrower_item_table->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        borrower_item_table->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        borrower_item_table->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        borrower_item_table->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        borrower_item_table->setObjectName(QStringLiteral("borrower_item_table"));
        borrower_item_table->setGeometry(QRect(780, 160, 381, 351));
        tabWidget->addTab(tabBorrower, QString());
        tabMisc = new QWidget();
        tabMisc->setObjectName(QStringLiteral("tabMisc"));
        cbMisc = new QComboBox(tabMisc);
        cbMisc->setObjectName(QStringLiteral("cbMisc"));
        cbMisc->setGeometry(QRect(230, 10, 131, 31));
        tbMisc = new QTableView(tabMisc);
        tbMisc->setObjectName(QStringLiteral("tbMisc"));
        tbMisc->setGeometry(QRect(230, 50, 681, 451));
        btnMiscAdd = new QPushButton(tabMisc);
        btnMiscAdd->setObjectName(QStringLiteral("btnMiscAdd"));
        btnMiscAdd->setGeometry(QRect(390, 10, 71, 31));
        btnMiscEdit = new QPushButton(tabMisc);
        btnMiscEdit->setObjectName(QStringLiteral("btnMiscEdit"));
        btnMiscEdit->setGeometry(QRect(480, 10, 71, 31));
        btnMiscDelete = new QPushButton(tabMisc);
        btnMiscDelete->setObjectName(QStringLiteral("btnMiscDelete"));
        btnMiscDelete->setGeometry(QRect(570, 10, 71, 31));
        txtMiscSearch = new QLineEdit(tabMisc);
        txtMiscSearch->setObjectName(QStringLiteral("txtMiscSearch"));
        txtMiscSearch->setGeometry(QRect(710, 10, 201, 31));
        tabWidget->addTab(tabMisc, QString());
        tabOperation = new QWidget();
        tabOperation->setObjectName(QStringLiteral("tabOperation"));
        tbOperationInstance = new QTableView(tabOperation);
        tbOperationInstance->setObjectName(QStringLiteral("tbOperationInstance"));
        tbOperationInstance->setGeometry(QRect(580, 110, 481, 311));
        lbOperationIns = new QLabel(tabOperation);
        lbOperationIns->setObjectName(QStringLiteral("lbOperationIns"));
        lbOperationIns->setGeometry(QRect(770, 20, 181, 41));
        lbOperationIns->setFont(font);
        btnOperationBorrowing = new QPushButton(tabOperation);
        btnOperationBorrowing->setObjectName(QStringLiteral("btnOperationBorrowing"));
        btnOperationBorrowing->setGeometry(QRect(170, 450, 311, 41));
        btnOperationReturning = new QPushButton(tabOperation);
        btnOperationReturning->setObjectName(QStringLiteral("btnOperationReturning"));
        btnOperationReturning->setGeometry(QRect(660, 450, 311, 41));
        txtOperationInsSearch = new QLineEdit(tabOperation);
        txtOperationInsSearch->setObjectName(QStringLiteral("txtOperationInsSearch"));
        txtOperationInsSearch->setGeometry(QRect(580, 70, 481, 31));
        tbOperationBorrower = new QTableView(tabOperation);
        tbOperationBorrower->setObjectName(QStringLiteral("tbOperationBorrower"));
        tbOperationBorrower->setGeometry(QRect(80, 110, 481, 311));
        txtOperationBorrowerSearch = new QLineEdit(tabOperation);
        txtOperationBorrowerSearch->setObjectName(QStringLiteral("txtOperationBorrowerSearch"));
        txtOperationBorrowerSearch->setGeometry(QRect(80, 70, 481, 31));
        lbOperationBorrower = new QLabel(tabOperation);
        lbOperationBorrower->setObjectName(QStringLiteral("lbOperationBorrower"));
        lbOperationBorrower->setGeometry(QRect(270, 20, 181, 41));
        lbOperationBorrower->setFont(font);
        tabWidget->addTab(tabOperation, QString());
        Original->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Original);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1159, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Original->setMenuBar(menubar);
        statusbar = new QStatusBar(Original);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Original->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(Original);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Original);
    } // setupUi

    void retranslateUi(QMainWindow *Original)
    {
        Original->setWindowTitle(QApplication::translate("Original", "Neat Librarian", 0));
        actionExit->setText(QApplication::translate("Original", "Exit", 0));
        actionAbout->setText(QApplication::translate("Original", "About", 0));
        btnMCAdd->setText(QApplication::translate("Original", "Add", 0));
        btnMCEdit->setText(QApplication::translate("Original", "Edit", 0));
        btnMCDelete->setText(QApplication::translate("Original", "Delete", 0));
        lbMCSort->setText(QApplication::translate("Original", "Sort", 0));
        cbMCSort->clear();
        cbMCSort->insertItems(0, QStringList()
         << QApplication::translate("Original", "ID", 0)
         << QApplication::translate("Original", "Collection Type", 0)
         << QApplication::translate("Original", "Data Type", 0)
         << QApplication::translate("Original", "Category", 0)
         << QApplication::translate("Original", "Title", 0)
         << QApplication::translate("Original", "Version", 0)
         << QApplication::translate("Original", "Publisher", 0)
         << QApplication::translate("Original", "Recorded Year", 0)
         << QApplication::translate("Original", "Duration", 0)
        );
        txtMCSearch->setPlaceholderText(QApplication::translate("Original", "Search...", 0));
        lbInsBorrower_2->setText(QApplication::translate("Original", "BORROWER", 0));
        lbInsBorrower_3->setText(QApplication::translate("Original", "ITEM", 0));
        lbMCFilter->setText(QApplication::translate("Original", "Search For", 0));
        cbMCFilter->clear();
        cbMCFilter->insertItems(0, QStringList()
         << QApplication::translate("Original", "ID", 0)
         << QApplication::translate("Original", "Collection Type", 0)
         << QApplication::translate("Original", "Data Type", 0)
         << QApplication::translate("Original", "Category", 0)
         << QApplication::translate("Original", "Title", 0)
         << QApplication::translate("Original", "Version", 0)
         << QApplication::translate("Original", "Publisher", 0)
         << QApplication::translate("Original", "Recorded Year", 0)
         << QApplication::translate("Original", "Duration", 0)
        );
        label->setText(QApplication::translate("Original", "Total items:", 0));
        total_item->setText(QString());
        label_4->setText(QApplication::translate("Original", "Total borrowers:", 0));
        total_borrower->setText(QString());
        pushButton->setText(QApplication::translate("Original", "Create items", 0));
        btnSaveMC->setText(QApplication::translate("Original", "Save", 0));
        btnPrintMC->setText(QApplication::translate("Original", "Print", 0));
        btnPrintMCItem->setText(QApplication::translate("Original", "Print", 0));
        btnSaveMCItem->setText(QApplication::translate("Original", "Save", 0));
        btnSaveMCBorrower->setText(QApplication::translate("Original", "Save", 0));
        btnPrintMCBorrower->setText(QApplication::translate("Original", "Print", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMC), QApplication::translate("Original", "Collection", 0));
        btnInsAdd->setText(QApplication::translate("Original", "Add", 0));
        btnInsEdit->setText(QApplication::translate("Original", "Edit", 0));
        btnInsDelete->setText(QApplication::translate("Original", "Delete", 0));
        txtInsSearch->setPlaceholderText(QApplication::translate("Original", "Search...", 0));
        lbInsSort->setText(QApplication::translate("Original", "Sort", 0));
        cbInsSort->clear();
        cbInsSort->insertItems(0, QStringList()
         << QApplication::translate("Original", "Barcode", 0)
         << QApplication::translate("Original", "Status", 0)
         << QApplication::translate("Original", "Borrowing Time", 0)
         << QApplication::translate("Original", "Borrowed Date", 0)
         << QApplication::translate("Original", "Borrowing Day", 0)
         << QApplication::translate("Original", "Title", 0)
        );
        lbInsBorrower->setText(QApplication::translate("Original", "COLLECTION", 0));
        lbInsCollection->setText(QApplication::translate("Original", "BORROWER", 0));
        lbInsFilter->setText(QApplication::translate("Original", "Search For", 0));
        cbInsFilter->clear();
        cbInsFilter->insertItems(0, QStringList()
         << QApplication::translate("Original", "Specified ID", 0)
         << QApplication::translate("Original", "Overdue", 0)
        );
        QTableWidgetItem *___qtablewidgetitem = tbIns->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Original", "Barcode", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tbIns->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Original", "Title", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tbIns->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Original", "Status", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tbIns->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Original", "Borrowing Time", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tbIns->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Original", "Borrowed Date", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tbIns->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Original", "Borrowing Day", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tbIns->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Original", "Overdue day", 0));
        btnSaveItem->setText(QApplication::translate("Original", "Save", 0));
        btnPrintItem->setText(QApplication::translate("Original", "Print", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabIns), QApplication::translate("Original", "Items", 0));
        btnBorrowerAdd->setText(QApplication::translate("Original", "Add", 0));
        btnBorrowerEdit->setText(QApplication::translate("Original", "Edit", 0));
        btnBorrowerDelete->setText(QApplication::translate("Original", "Delete", 0));
        cbBorrowerSort->clear();
        cbBorrowerSort->insertItems(0, QStringList()
         << QApplication::translate("Original", "ID", 0)
         << QApplication::translate("Original", "Name", 0)
         << QApplication::translate("Original", "Borrower Type", 0)
         << QApplication::translate("Original", "Department", 0)
         << QApplication::translate("Original", "Mobile Number", 0)
         << QApplication::translate("Original", "Borrowed Items", 0)
         << QApplication::translate("Original", "Late Returned Items", 0)
        );
        lbBorrowerSort->setText(QApplication::translate("Original", "Sort", 0));
        txtBorrowerSearch->setPlaceholderText(QApplication::translate("Original", "Search...", 0));
        label_3->setText(QApplication::translate("Original", "BORROWING ITEM", 0));
        lbBorrowerFilter->setText(QApplication::translate("Original", "Search For", 0));
        cbBorrowerFilter->clear();
        cbBorrowerFilter->insertItems(0, QStringList()
         << QApplication::translate("Original", "ID", 0)
         << QApplication::translate("Original", "Name", 0)
         << QApplication::translate("Original", "Borrower Type", 0)
         << QApplication::translate("Original", "Department", 0)
         << QApplication::translate("Original", "Mobile Number", 0)
         << QApplication::translate("Original", "Borrowed Items", 0)
         << QApplication::translate("Original", "Late Returned Items", 0)
         << QApplication::translate("Original", "Overdue", 0)
        );
        lblPreviously->setText(QApplication::translate("Original", "Previously Borrowed:", 0));
        lbCurrently->setText(QApplication::translate("Original", "Currently Borrowed:", 0));
        lblPreviouslyBorrowed->setText(QString());
        lblCurrentlyBorrowed->setText(QString());
        QTableWidgetItem *___qtablewidgetitem7 = tbBorrower->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("Original", "BorrowerID", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tbBorrower->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("Original", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tbBorrower->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("Original", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tbBorrower->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("Original", "Department", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tbBorrower->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("Original", "MobileNumber", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tbBorrower->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("Original", "TotalBorrowed", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tbBorrower->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("Original", "LateReturned", 0));
        btnSaveBorrower->setText(QApplication::translate("Original", "Save", 0));
        btnPrintBorrower->setText(QApplication::translate("Original", "Print", 0));
        btnSaveBorrowerItem->setText(QApplication::translate("Original", "Save", 0));
        btnPrintBorrowerItem->setText(QApplication::translate("Original", "Print", 0));
        QTableWidgetItem *___qtablewidgetitem14 = borrower_item_table->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("Original", "Barcode", 0));
        QTableWidgetItem *___qtablewidgetitem15 = borrower_item_table->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("Original", "BorrowedDate", 0));
        QTableWidgetItem *___qtablewidgetitem16 = borrower_item_table->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("Original", "BorrowingDay", 0));
        QTableWidgetItem *___qtablewidgetitem17 = borrower_item_table->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("Original", "Overdue", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabBorrower), QApplication::translate("Original", "Borrowers", 0));
        cbMisc->clear();
        cbMisc->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Original", "CollectionType", 0)
         << QApplication::translate("Original", "DataType", 0)
         << QApplication::translate("Original", "Category", 0)
         << QApplication::translate("Original", "Department", 0)
         << QApplication::translate("Original", "PersonType", 0)
         << QApplication::translate("Original", "Status", 0)
        );
        btnMiscAdd->setText(QApplication::translate("Original", "Add", 0));
        btnMiscEdit->setText(QApplication::translate("Original", "Edit", 0));
        btnMiscDelete->setText(QApplication::translate("Original", "Delete", 0));
        txtMiscSearch->setPlaceholderText(QApplication::translate("Original", "Search...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMisc), QApplication::translate("Original", "Miscellaneous", 0));
        lbOperationIns->setText(QApplication::translate("Original", "Item", 0));
        btnOperationBorrowing->setText(QApplication::translate("Original", "Borrow Collection", 0));
        btnOperationReturning->setText(QApplication::translate("Original", "Return Collection", 0));
        txtOperationInsSearch->setPlaceholderText(QApplication::translate("Original", "Search for an item here", 0));
        txtOperationBorrowerSearch->setPlaceholderText(QApplication::translate("Original", "Search for a borrower here", 0));
        lbOperationBorrower->setText(QApplication::translate("Original", "Borrower", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabOperation), QApplication::translate("Original", "Daily Operation", 0));
        menuFile->setTitle(QApplication::translate("Original", "File", 0));
        menuHelp->setTitle(QApplication::translate("Original", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class Original: public Ui_Original {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORIGINAL_H
