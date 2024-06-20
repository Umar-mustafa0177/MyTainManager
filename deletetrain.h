#ifndef DELETETRAIN_H
#define DELETETRAIN_H

#include <QDialog>
#include "QMessageBox"
#include "dbheader.h"

namespace Ui {
class deletetrain;
}

class deletetrain : public QDialog
{
    Q_OBJECT


private:
    Ui::deletetrain *ui;

    QString trainno;

public:
    explicit deletetrain(QWidget *parent = nullptr);
    ~deletetrain();


    //function for deleting the trian:
    void deletingthetrain()
    {
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
        query.prepare("Delete  from Train where TrainNo = '"+trainno+"'");
        query.exec();
        qDebug() << "LAST ERROR "<<query.lastError().text();
        db.close();
    }


private slots:
    void on_pushButton_clicked();

};

#endif // DELETETRAIN_H
