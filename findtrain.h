#ifndef FINDTRAIN_H
#define FINDTRAIN_H

#include <QDialog>
#include "dbheader.h"

namespace Ui {
class findtrain;
}

class findtrain : public QDialog
{
    Q_OBJECT

public:
    explicit findtrain(QWidget *parent = nullptr);
    ~findtrain();

private slots:
   void findingtrains();

    void on_pushButton_clicked();

private:
    Ui::findtrain *ui;
    QSqlQueryModel *model;

    QString trainno;
};

#endif // FINDTRAIN_H
