#include "admin.h"
#include "ui_admin.h"
#include <qmessagebox.h>

Admin::Admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);

    connect (ui->pushButton3, SIGNAL(clicked()), this, SLOT(signinbutton()));
    ptrManageAdmin = new ManageAdmin;
}

Admin::~Admin()
{
    delete ui;
    delete ptrManageAdmin;
}

void Admin::signinbutton()
{
    QString username[]={"ahmed", "ali", "raza"};
    QString userpass[]={"ahmed123", "ali123", "raza123"};

    QString enteredusername=ui->lineEdit->text();
    QString entereduserpass=ui->lineEdit_2->text();

    bool found=false;
    for (int i = 0; i < username->length(); ++i)
    {
        if(enteredusername == username[i] && entereduserpass == userpass[i])
        {

            ptrManageAdmin->show();
            found = true;
            break;
        }
    }

    if(!found)
    {
        QMessageBox::warning(this, "Error", "Invalid Username or Password");
    }

}

