#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSQL>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

//have to write methods up top or the program wont know what
//is being called
void createXml(vector<Property> properties);
void createObjects();
void populateUi();
void writeTxtFile(QString address, QString unit);
void readXml(string address, int unit);
void drawList();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setup for archiving
    createObjects();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete creatorWin;
}

void MainWindow::createObjects(){

    vector<Property> properties;

    for (int i = 0; i < dbcMain.getRowCount(); i++){        
        vector<QString> currentInfo = dbcMain.getRowInfo(i);

        ui->propertyList->addItem(currentInfo[0] + "|" + currentInfo[1]);


        Property myproperty (i, currentInfo[0], currentInfo[1], currentInfo[2], currentInfo[3], currentInfo[4], currentInfo[5], currentInfo[6], currentInfo[7], currentInfo[8], currentInfo[9], currentInfo[10], currentInfo[11], currentInfo[12]);
        properties.push_back(myproperty);
    }


    createXml(properties);
}

//creates an xml file based on the objects read from database
void createXml(vector<Property> properties){

    QFile file("info.xml");
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    for(int i = 0; i < properties.size(); i++){
        xmlWriter.writeStartElement("TownHouse");
        xmlWriter.writeTextElement("Adress", properties[i].adress);
        xmlWriter.writeTextElement("Unit Number", properties[i].unit);
        xmlWriter.writeTextElement("Locker Number", properties[i].locker);
        xmlWriter.writeTextElement("Parking Number",properties[i].parking);
        xmlWriter.writeTextElement("Date Purchased", properties[i].datePurchased);
        xmlWriter.writeTextElement("PropManagement", properties[i].propManagement);
        xmlWriter.writeTextElement("Status", properties[i].status);
        xmlWriter.writeTextElement("Lease", properties[i].lease);
        xmlWriter.writeTextElement("Taxes", properties[i].taxes);
        xmlWriter.writeTextElement("Maintenance", properties[i].maintenance);
        xmlWriter.writeTextElement("Utilities", properties[i].utilities);
        xmlWriter.writeTextElement("Purchases", properties[i].purchases);
        xmlWriter.writeTextElement("Misc", properties[i].misc);

        xmlWriter.writeEndElement();
    }

    file.close();

} 

void MainWindow::on_btnOpen_clicked(){

    //TODO fix in future
    //IF no item is selected it crashes

    QString item = ui->propertyList->currentItem()->text();

    QStringList list = item.split("|");

    writeTxtFile(list[0], list[1]);

    //open the information form
    informationWin = new Infor();
    informationWin -> show();

}


//Creating a field in the global text file
//for the property that was currently
//selected
void writeTxtFile(QString address, QString unit){
    cout << unit.toStdString();
    QString filename= "global.txt";
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QTextStream stream( &file );
    stream << address << endl;
    stream << unit << endl;
    file.close();

}

//for debugging purposes
//reading text file from main window
void readTxtFile(){
    QFile file("global.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream input(&file);
    QString address = input.readLine();
    QString unit = input.readLine();
    file.close();
}

void MainWindow::on_AddProperty_clicked()
{
    //not added yet
    //creatorWin = new creator();
   // creatorWin -> show();
}

void MainWindow::on_btnDelete_clicked()
{
    QString item = ui->propertyList->currentItem()->text();

    QStringList list = item.split("|");
    dbcMain.deleteRow(list[0], list[1]);
}
