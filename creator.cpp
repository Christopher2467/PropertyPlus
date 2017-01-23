#include "creator.h"
#include "ui_creator.h"
#include <mainwindow.h>

using namespace std;

void getInfo();
//Not Completed
creator::creator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creator)
{
    ui->setupUi(this);
    getInfo();
    /*
     * Template Data
     * not code used in final
     */
    ui->plainTextEditAddress->appendPlainText("25 Melrose Drive");
    ui->plainTextEditTenantOne->appendPlainText("John Doe");
    ui->plainTextEditTenantTwo->appendPlainText("John Doe");
    ui->plainTextEditTenantThree->appendPlainText("John Doe");

}

creator::~creator()
{
    delete ui;
}

void getInfo(){
    //global varaible address
    //cout << address;



}
