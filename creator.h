#ifndef CREATOR_H
#define CREATOR_H

#include <QWidget>

namespace Ui {
class creator;
}

class creator : public QWidget
{
    Q_OBJECT

public:
    explicit creator(QWidget *parent = 0);
    ~creator();

private:
    Ui::creator *ui;
};

#endif // CREATOR_H
