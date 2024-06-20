#ifndef BUYTICKET_H
#define BUYTICKET_H

#include <QDialog>
#include "dbheader.h"

namespace Ui {
class buyticket;
}

class buyticket : public QDialog
{
    Q_OBJECT

private:
    Ui::buyticket *ui;
    QSqlQueryModel *model;

    QString passengername ;
    QString passengerCNIC;
    QString ContactNo ;
    QString selecttrain;

    QString Nooftrian ;
    QString stfrom ;
    QString stTo ;
    QString timeofdep;
    QString priceoftc;
    QString classtrain;

public:
    explicit buyticket(QWidget *parent = nullptr);
    ~buyticket();

    void savingticket()
    {
        qDebug() <<"PASSENGER NAME IS :"<<passengername <<"PASSENGER CNIC :"<<passengerCNIC<<"Contact No is :"<<ContactNo;
        qDebug() <<"TRAIN SELECTED IS :"<<selecttrain<<" NUMBER OF TRAIN IS :"<<Nooftrian;
        qDebug() <<" FROM "<<stfrom<<" TO "<<stTo<<"TIME "<<timeofdep<<" PRICE "<<priceoftc<<"CLASS OF TRAIN IS :"<<classtrain;


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
        //, TrainkaNumber, From, To, Time, Price, Class
        //, '"+Nooftrian+"', '"+from+"', '"+To+"', '"+time+"', '"+price+"', '"+classoftrain+"'
        query.prepare("insert into Ticket (PassengerName, PassengerCNIC, ContactNo, SelectedTrain, TrainkaNumber, Fromst, Tost, Timeis, Priceis, Classis) VALUES('"+passengername+"', '"+passengerCNIC+"', '"+ContactNo+"', '"+selecttrain+"', '"+Nooftrian+"', '"+stfrom+"', '"+stTo+"', '"+timeofdep+"', '"+priceoftc+"', '"+classtrain+"')");
        query.exec();
        qDebug() << "LAST ERROR "<<query.lastError().text();

        db.close();
    }

private slots:
    void on_btnshowtrains_clicked();

    void on_pushButton_clicked();

    void on_cmbtrains_currentTextChanged(const QString &arg1);

    void on_cmbtrains_textActivated(const QString &arg1);


};

#endif // BUYTICKET_H
