#ifndef SEARCHTICKET_H
#define SEARCHTICKET_H

#include <QDialog>
#include "dbheader.h"
#include "QMessageBox"

namespace Ui {
class searchticket;
}

class searchticket : public QDialog
{
    Q_OBJECT

private:
    Ui::searchticket *ui;
    QSqlQueryModel *model;

    QString nametosearch;


public:
    explicit searchticket(QWidget *parent = nullptr);
    ~searchticket();


    void connectdatabase()
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


    }



private slots:
    void on_btnsearch_clicked();
    void searchingofticket();


};

#endif // SEARCHTICKET_H
