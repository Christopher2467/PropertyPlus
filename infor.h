#ifndef INFOR_H
#define INFOR_H

#include <QWidget>

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
};

#endif // INFOR_H
