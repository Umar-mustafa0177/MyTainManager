#include "searchticket.h"
#include "ui_searchticket.h"

searchticket::searchticket(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::searchticket)
{
    ui->setupUi(this);
    model = NULL;
}

searchticket::~searchticket()
{
    delete ui;
    delete model;
}

//function for searching the ticket and represnet data in tableview
//-------------------------------------------------------------------------------------------------------------
 void searchticket::searchingofticket()
{
    nametosearch = ui->txtnameofapass->toPlainText();
    // Query to fetch data from the database
    QString query = "select * from Ticket where PassengerName like '%" + nametosearch + "%'";

    // Execute the query and fetch the data
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);

    // Check for errors
    if (model->lastError().isValid())
    {
        qDebug() << "Error executing query:" << model->lastError().text();
        // Handle error
    }
    // Set the model to the listview
    ui->tableView->setModel(model);
}

//-------------------------------------------------------------------------------------------------------------------

void searchticket::on_btnsearch_clicked()
{

     connectdatabase();
     searchingofticket();



}

