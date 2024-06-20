#ifndef MANAGEADMIN_H
#define MANAGEADMIN_H

#include "addtrain.h"
#include "modifytrain.h"
#include "deletetrain.h"
#include "searchticket.h"

#include <QDialog>

namespace Ui {
class ManageAdmin;
}

class ManageAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit ManageAdmin(QWidget *parent = nullptr);
    ~ManageAdmin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ManageAdmin *ui;
    addtrain *ptraddtrain;
    modifytrain *ptrmodifytrain;
    deletetrain *ptrdeletetrain;
    searchticket *ptrsearchticket;
};

#endif // MANAGEADMIN_H
