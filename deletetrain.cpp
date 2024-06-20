#include "deletetrain.h"
#include "ui_deletetrain.h"
#include <QMessageBox>

deletetrain::deletetrain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deletetrain)
{
    ui->setupUi(this);
}

deletetrain::~deletetrain()
{
    delete ui;
}

void deletetrain::on_pushButton_clicked()
{
        trainno = ui->txtrainno->toPlainText();

    deletingthetrain();
}

