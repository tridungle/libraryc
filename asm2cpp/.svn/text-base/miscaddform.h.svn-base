#ifndef MISCADDFORM_H
#define MISCADDFORM_H

#include <QDialog>
#include <QLineEdit>
#include <ui_miscaddform.h>
#include <string>
#include "mcinstance.h"
#include "borrower.h"
#include "mcsystem.h"

namespace Ui {
class MiscAddForm;
}

class MiscAddForm : public QDialog
{
    Q_OBJECT

public:
    explicit MiscAddForm(QWidget *parent = 0);
    ~MiscAddForm();
    QString getLbMisc() const;
    void setLbMisc(const QString &name);
    std::string getCurrentType() const;
    void setCurrentType(const std::string type);
    QString getTxtMiscID() const;
    void setTxtMiscID(const QString &id);

    void setCurrentAction(const std::string act)
    {
        this->currentAction = act;
    }

    QLineEdit* getTxtLine()
    {
        return ui->txtMiscValue;
    }

    QPushButton* getAddButton()
    {
        return ui->btnMiscAdd;
    }

private slots:
    void on_btnMiscCancel_clicked();

    void on_btnMiscAdd_clicked();

private:
    Ui::MiscAddForm *ui;
    std::string currentType;
    std::string currentAction;
};

#endif // MISCADDFORM_H
