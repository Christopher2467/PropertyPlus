#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <iostream>
#include <string>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QXmlStreamReader>
#include <vector>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QStandardItemModel>

using namespace std;

class Property{
  public:
    int id;
    string adress;
    string tenants;
    int term;
    int rent;

    Property(int i, string adr, string ten, int ter, int ren){
        id = i;
        adress = adr;
        tenants = ten;
        term = ter;
        rent = ren;
    }

};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:

    void on_btnOpen_clicked();
    void populateUi(vector<Property>);


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
