#ifndef MODIFYTRAIN_H
#define MODIFYTRAIN_H

#include <QDialog>
#include "dbheader.h"
#include "QMessageBox"

namespace Ui {
class modifytrain;
}

class modifytrain : public QDialog
{
    Q_OBJECT

private:
    Ui::modifytrain *ui;

    QString trainkano ;
    QString fromstation ;
    QString Tostation ;
    QString time ;
    QString priceofticket ;
    QString trainkiclass ;

public:
    explicit modifytrain(QWidget *parent = nullptr);
    ~modifytrain();

    void modifyingthetrain()
    {
        qDebug()  <<" NO IS :"<<trainkano<<"STATION FROM "<<fromstation<<"STATION TO "<<Tostation;
        qDebug() <<"TIME IS :"<<time<<"PRICE OF TICKET IS L"<<priceofticket<<" CLASS IS :"<<trainkiclass;

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



        //query.prepare("UPDATE Train Set Stationfrom = '"+fromstation+"', StationTo '"+Tostation+"' = , Timing = '"+time+"', Fare = '"+priceofticket+"' WHERE TrainNo = '"+trainkano+"' " )  ;
        QSqlQuery query;
        query.prepare("UPDATE Train SET Stationfrom = '" + fromstation + "', StationTo = '" + Tostation + "', Timing = '" + time + "', Fare = '" + priceofticket + "', Class = '" + trainkiclass + "' WHERE TrainNo = '" + trainkano + "'");

        query.exec();
        qDebug() << "LAST ERROR "<<query.lastError().text();
        db.close();
    }

private slots:
    void on_pushButton_clicked();


};

#endif // MODIFYTRAIN_H
