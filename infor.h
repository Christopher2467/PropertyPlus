#ifndef INFOR_H
#define INFOR_H

#include <QWidget>
#include <QSql>
#include<databsecontroller.h>

namespace Ui {
class Infor;
}

class Infor : public QWidget
{
    Q_OBJECT

public:
    explicit Infor(QWidget *parent = 0);
    ~Infor();

private:
    Ui::Infor *ui;
    QSqlDatabase dbInfo;
    DatabseController dbcInfo;
};

#endif // INFOR_H
