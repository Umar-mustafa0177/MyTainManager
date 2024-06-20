#ifndef ADDTRAIN_H
#define ADDTRAIN_H

#include <QDialog>
#include "dbheader.h"
#include "QMessageBox"

namespace Ui {
class addtrain;
}

class addtrain : public QDialog
{
    Q_OBJECT

private:
    Ui::addtrain *ui;


    QString trainkaname ;
    QString trainkano;
    QString fromstation ;
    QString Tostation ;
    QString time ;
    QString priceofticket;
    QString trainclass ;

public:
    explicit addtrain(QWidget *parent = nullptr);
    ~addtrain();


    //function of adding train;
    void addingthetrain(){
    qDebug() <<"NAME IS :"<<trainkaname <<" NO IS :"<<trainkano<<"STATION FROM "<<fromstation<<"STATION TO "<<Tostation;
    qDebug() <<"TIME IS :"<<time<<"PRICE OF TICKET IS L"<<priceofticket<<" CLASS IS :"<<trainclass;

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

    query.prepare("insert into Train (TrainName, TrainNo, Stationfrom, StationTo, Timing, Fare, Class) VALUES('" +trainkaname+"', '" +trainkano+"', '" +fromstation+"', '" +Tostation+"', '" +time+"', '" +priceofticket+"', '" +trainclass+"')");


    query.exec();
    qDebug() << "LAST ERROR "<<query.lastError().text();

    };


private slots:
    void on_pushButton_clicked();


};

#endif // ADDTRAIN_H
