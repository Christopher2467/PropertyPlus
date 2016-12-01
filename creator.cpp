#include "creator.h"
#include "ui_creator.h"
#include <mainwindow.h>

using namespace std;

void getInfo();

creator::creator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creator)
{
    ui->setupUi(this);
    getInfo();
}

creator::~creator()
{
    delete ui;
}

void getInfo(){
    //global varaible address
    //cout << address;
}
