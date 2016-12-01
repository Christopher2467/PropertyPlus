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
#include <QStandardItemModel>
#include <creator.h>
#include <infor.h>


using namespace std;

class Property{
  public:
    int id;
    string adress;
    int unit;
    int locker;
    int parking;
    int datePurchased;
    string propManagement;
    int status;
    double lease;
    double taxes;
    double maintenance;
    double utilities;
    double purchases;
    double misc;

    Property(int i, string adr, int uni, int lock, int park, int date, string manage, int statu, double leas, double taxs, double maint, double util, double purch, double mis){
        id = i;
        adress = adr;
        unit = uni;
        locker = lock;
        parking = park;
        datePurchased = date;
        propManagement = manage;
        status = statu;
        lease = leas;
        taxes = taxs;
        maintenance = maint;
        utilities = util;
        purchases = purch;
        misc = mis;
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

    void populateUi();

private slots:

    void on_btnOpen_clicked();


private:
    Ui::MainWindow *ui;
    creator *creatorWin;
    Infor *informationWin;

};

#endif // MAINWINDOW_H
