#include "modifytrain.h"
#include "ui_modifytrain.h"
#include <QMessageBox>

modifytrain::modifytrain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifytrain)
{
    ui->setupUi(this);
}

modifytrain::~modifytrain()
{
    delete ui;
}

void modifytrain::on_pushButton_clicked()
{

    trainkano = ui->txttrainno->toPlainText();
    fromstation = ui->txtstationfrom->toPlainText();
    Tostation = ui->txtstationto->toPlainText();
    time = ui->txttime->toPlainText();
    priceofticket = ui->txtfare->toPlainText();
    trainkiclass = ui->txtclass->toPlainText();

    //calling the function
    modifyingthetrain();
}

