#include "addtrain.h"
#include "ui_addtrain.h"
#include <QMessageBox>

addtrain::addtrain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addtrain)
{
    ui->setupUi(this);
}

addtrain::~addtrain()
{
    delete ui;
}

void addtrain::on_pushButton_clicked()
{
    trainkaname =ui->txttrainname->toPlainText();

    trainkano = ui->txttrainkano->toPlainText();

    fromstation = ui->txtstationfrom->toPlainText();

    Tostation = ui->txtstationto->toPlainText();

    time = ui->txttime->toPlainText();

    priceofticket = ui->txtfare->toPlainText();

    trainclass = ui->txtclass->toPlainText();


    //calling the function
    addingthetrain();

}

