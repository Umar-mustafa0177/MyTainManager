#include "seatavailability.h"
#include "ui_seatavailability.h"


seatavailability::seatavailability(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::seatavailability)
{
    ui->setupUi(this);
    model = NULL;

}
seatavailability::~seatavailability()
{
    delete ui;
    delete model;
}


void seatavailability::on_pushButton_clicked()
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



    if(model == NULL)
    {


        model = new QSqlQueryModel();
    }

    QSqlQuery query;

    model->setQuery("select TrainName from Train");
    //model->setQuery("select * from Train where TrainName like '%" + trainno + "%'", db);
    ui->cmbselect->setModel(model);
    qDebug() << " after btnFind_clicked";
}



void seatavailability::on_cmbselect_currentTextChanged(const QString &arg1)
{

    QString Selection=ui->cmbselect->currentText();

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



        QSqlQuery qry;

    qry.prepare("select COUNT(SelectedTrain) from Ticket where SelectedTrain='"+Selection+"'");
    qry.exec();
    qDebug() << "LAST ERROR "<<qry.lastError().text();
    db.close();

    QString bookedseats;
    if (qry.next()) {
        bookedseats = qry.value("COUNT(SelectedTrain)").toString();
    }
    ui->txtBookedSeats->setText(bookedseats);



    QString totalseats = "50"; // Or any other value you want
    ui->txtTotalSeats->setText(totalseats);



    int totalSeatsInt = totalseats.toInt();
    int bookedSeatsInt = bookedseats.toInt();

    int Availableseats = totalSeatsInt - bookedSeatsInt;
    qDebug() <<Availableseats<<"these are available :";


    QString noofavailable = QString::number(Availableseats);

    ui->txtAvailableseats->setText(noofavailable);
}

