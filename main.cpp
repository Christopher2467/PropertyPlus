#include "mainwindow.h"
#include <QApplication>
#include <QtSQL>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //shows what database drivers are installed
    //good to see just incase
    qDebug() << QSqlDatabase::drivers();

    MainWindow w;
    w.show();

    return a.exec();
}
