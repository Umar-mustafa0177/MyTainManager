#include "nextpage.h"
#include "ui_nextpage.h"

Nextpage::Nextpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Nextpage)
{
    ui->setupUi(this);
    ptruser = new User;
    ptrAdmin = new Admin;
}

Nextpage::~Nextpage()
{
    delete ui;
    delete ptruser;
    delete ptrAdmin;
}

void Nextpage::on_pushButton_clicked()
{
    ptruser -> show();
}


void Nextpage::on_pushButton_2_clicked()
{
    ptrAdmin -> show();
}

