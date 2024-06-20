#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::User)
{
    ui->setupUi(this);

    ptrbuyticket = new buyticket();
    ptrfindtrain = new findtrain();
    ptrseatavailability = new seatavailability();
}

User::~User()
{
    delete ui;
    delete ptrbuyticket;
    delete ptrfindtrain;
    delete ptrseatavailability;
}

void User::on_pushButton_clicked()
{
    ptrbuyticket->show();
}


void User::on_pushButton_2_clicked()
{
    ptrfindtrain->show();
}


void User::on_pushButton_3_clicked()
{
    ptrseatavailability->show();
}

