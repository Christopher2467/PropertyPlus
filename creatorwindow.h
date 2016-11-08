#ifndef CREATORWINDOW_H
#define CREATORWINDOW_H

#include <QMainWindow>

namespace Ui {
class creatorWindow;
}

class creatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit creatorWindow(QWidget *parent = 0);
    ~creatorWindow();

private:
    Ui::creatorWindow *ui;
};

#endif // CREATORWINDOW_H
