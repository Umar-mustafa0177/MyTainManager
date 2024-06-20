#include "manageadmin.h"
#include "ui_manageadmin.h"

ManageAdmin::ManageAdmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManageAdmin)
{
    ui->setupUi(this);
    ptraddtrain = new addtrain();
    ptrmodifytrain = new modifytrain();
    ptrdeletetrain = new deletetrain();
    ptrsearchticket = new searchticket();

}

ManageAdmin::~ManageAdmin()
{
    delete ui;
    delete ptraddtrain;
    delete ptrmodifytrain;
    delete ptrdeletetrain;
    delete ptrsearchticket;
}

void ManageAdmin::on_pushButton_clicked()
{
    ptraddtrain->show();
}


void ManageAdmin::on_pushButton_2_clicked()
{
    ptrmodifytrain->show();
}


void ManageAdmin::on_pushButton_3_clicked()
{
    ptrdeletetrain->show();
}


void ManageAdmin::on_pushButton_4_clicked()
{
    ptrsearchticket->show();
}

