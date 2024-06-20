#ifndef NEXTPAGE_H
#define NEXTPAGE_H

#include <QDialog>
#include "user.h"
#include "admin.h"

namespace Ui {
class Nextpage;
}

class Nextpage : public QDialog
{
    Q_OBJECT

public:
    explicit Nextpage(QWidget *parent = nullptr);
    ~Nextpage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Nextpage *ui;

    User *ptruser;
    Admin *ptrAdmin;
};

#endif // NEXTPAGE_H
