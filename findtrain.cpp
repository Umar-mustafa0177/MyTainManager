#include "findtrain.h"
#include "ui_findtrain.h"

findtrain::findtrain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::findtrain)
{
    ui->setupUi(this);
    model = NULL;
}

findtrain::~findtrain()
{
    delete ui;
    delete model;
}


void findtrain::findingtrains()
{
    trainno = ui->txtnameoftraintosearch->toPlainText();
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

    model->setQuery("select * from Train where TrainName like '%" + trainno + "%'", db);
    ui->tableView->setModel(model);
    qDebug() << " after btnFind_clicked";
}


void findtrain::on_pushButton_clicked()
{
    findingtrains();

}

