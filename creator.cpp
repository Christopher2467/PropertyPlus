#include "creatorwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    creatorWindow w;
    w.show();

    return a.exec();
}
