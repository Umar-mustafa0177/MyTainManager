#ifndef SEATAVAILABILITY_H
#define SEATAVAILABILITY_H

#include <QDialog>
#include "dbheader.h"

namespace Ui {
class seatavailability;
}

class seatavailability : public QDialog
{
    Q_OBJECT

public:
    explicit seatavailability(QWidget *parent = nullptr);
    ~seatavailability();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_cmbselect_currentTextChanged(const QString &arg1);

private:
    Ui::seatavailability *ui;
    QSqlQueryModel *model;
};

#endif // SEATAVAILABILITY_H
