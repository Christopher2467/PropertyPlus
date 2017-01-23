#include "infor.h"
#include "ui_infor.h"
#include "mainwindow.h"
#include <QtSql>

vector<QString> readTxtFile();

Infor::Infor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Infor)
{
    ui->setupUi(this);

    vector<QString> info = readTxtFile();

    //Will get the value of the property that was in the text file and store it in a vector
    vector<QString> totalInfo = dbcInfo.getSingleAllInfo(info[0], info[1]);

    //draw to the ui the values
    ui->Address1->setText(totalInfo[0]);
    ui->unitNUMBER1->setText(totalInfo[1]);
    ui->lockernumber->setText(totalInfo[2]);
    ui->parkingnumber1->setText(totalInfo[3]);
    ui->datepurchased->setText(totalInfo[4]);
    ui->company1->setText(totalInfo[5]);
    ui->status1->setText(totalInfo[6]);
    ui->leaseamount1->setText(totalInfo[7]);
    ui->taxes1->setText(totalInfo[8]);
    //TODO Add to Ui the remaining fields
    ui->Maintenancefee1->setText(totalInfo[10]);
}

//read the global file
vector<QString> readTxtFile(){
    //open file and file stream
    QFile file("global.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream input(&file);
    //parse the two lines where the data would be
    QString address = input.readLine();
    QString unit = input.readLine();
    file.close();
    //put the two lines of data into a vector
    vector<QString> info {address, unit};

    return info;
}

Infor::~Infor()
{
    delete ui;
}
