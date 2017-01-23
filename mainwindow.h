#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
#include <QDomDocument>
#include <QtSql>
#include <databsecontroller.h>

using namespace std;

/**
 * Property Object creation that will
 * be turned into xml
 */

class Property{
  public:
    int id;
    QString adress;
    QString unit;
    QString locker;
    QString parking;
    QString datePurchased;
    QString propManagement;
    QString status;
    QString lease;
    QString taxes;
    QString maintenance;
    QString utilities;
    QString purchases;
    QString misc;

    Property(int i, QString adr, QString uni, QString lock, QString park, QString date, QString manage, QString statu, QString leas, QString taxs, QString maint, QString util, QString purch, QString mis){
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
    void createObjects();
    void on_AddProperty_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
    //necesseary to be able to open new windows
    creator *creatorWin;
    Infor *informationWin;
    QSqlDatabase dbMain;
    DatabseController dbcMain;
};

#endif // MAINWINDOW_H
