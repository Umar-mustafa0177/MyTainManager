#ifndef USER_H
#define USER_H

#include <QDialog>
#include "buyticket.h"
#include "findtrain.h"
#include "seatavailability.h"

namespace Ui {
class User;
}

class User : public QDialog
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::User *ui;

    buyticket *ptrbuyticket;
    findtrain *ptrfindtrain;
    seatavailability *ptrseatavailability;
};

#endif // USER_H
