#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "manageadmin.h"

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void signinbutton();

private:
    Ui::Admin *ui;
    ManageAdmin *ptrManageAdmin;
};

#endif // ADMIN_H
