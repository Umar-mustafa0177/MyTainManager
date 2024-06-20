#include "buyticket.h"
#include "ui_buyticket.h"
#include <qmessagebox.h>

buyticket::buyticket(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::buyticket)
{
    ui->setupUi(this);
    model = NULL;
}

buyticket::~buyticket()
{
    delete ui;
    delete model;
}

//button for load data of train
void buyticket::on_btnshowtrains_clicked()
{
    //QString nameoftrain = ui->cmbtrains->toPlainText();
    //QSqlDatabase database = QSqlDatabase::database("C:/Users/user/Documents/MYQTPROJECT/traindatabase.db");

    QSqlDatabase db = QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/user/Documents/MYQTPROJECT/traindatabase.db");

    if(QFile::exists("C:/Users/user/Documents/MYQTPROJECT/traindatabase.db"))
    {
        qDebug() <<"DATABASE EXISTS :";
    }
    else
    {
        qDebug() <<"DATABASE NOT FOUND :";
        return;
    }

    if(!db.open())
    {
        qDebug() <<"error to open a database !!";
        return;
    }
    {
        qDebug() <<"database opened successfully!!";
    }



    if(model == NULL)
    {


        model = new QSqlQueryModel();
    }

    QSqlQuery query;

    model->setQuery("select TrainName from Train");
    ui->cmbtrains->setModel(model);
    qDebug() << " after btnFind_clicked";

}

//button for save
void buyticket::on_pushButton_clicked()
{
    passengername =ui->txtpassengername->toPlainText();
    passengerCNIC = ui->txtCNIC->toPlainText();
    ContactNo = ui->txtContactNo->toPlainText();
    selecttrain = ui->cmbtrains->currentText();

    Nooftrian = ui->txtNumberoftrain->toPlainText();
    stfrom = ui->txtfrom->toPlainText();;
    stTo = ui->txtTo->toPlainText();;
   timeofdep = ui->txtTime->toPlainText();;
   priceoftc = ui->txtPrice->toPlainText();;
   classtrain = ui->txtclassoftrain->toPlainText();;


    savingticket();



}

//button for showing details of selected train in text edit boxes
void buyticket::on_cmbtrains_currentTextChanged(const QString &arg1)
{
    QString nameofcmb= ui->cmbtrains->currentText();



    QSqlDatabase db = QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/user/Documents/MYQTPROJECT/traindatabase.db");

    if(QFile::exists("C:/Users/user/Documents/MYQTPROJECT/traindatabase.db"))
    {
        qDebug() <<"DATABASE EXISTS :";
    }
    else
    {
        qDebug() <<"DATABASE NOT FOUND :";
        return;
    }

    if(!db.open())
    {
        qDebug() <<"error to open a database !!";
        return;
    }
    {
        qDebug() <<"database opened successfully!!";
    }

    QSqlQuery query;


    query.prepare("select  TrainNo, Stationfrom, StationTo, Timing, Fare, Class from Train where TrainName='"+nameofcmb+"' ");
    query.exec();
    while(query.next())
    {
        ui->txtNumberoftrain->setText(query.value(0).toString());
        ui->txtfrom->setText(query.value(1).toString());
        ui->txtTo->setText(query.value(2).toString());
        ui->txtTime->setText(query.value(3).toString());
        ui->txtPrice->setText(query.value(4).toString());
        ui->txtclassoftrain->setText(query.value(5).toString());
    }
    qDebug() << "LAST ERROR "<<query.lastError().text();
    db.close();
}




