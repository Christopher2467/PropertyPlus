#ifndef CREATORWINDOW_H
#define CREATORWINDOW_H

#include <QWidget>

namespace Ui {
class creatorwindow;
}

class creatorwindow : public QWidget
{
    Q_OBJECT

public:
    explicit creatorwindow(QWidget *parent = 0);
    ~creatorwindow();

private:
    Ui::creatorwindow *ui;
};

#endif // CREATORWINDOW_H
