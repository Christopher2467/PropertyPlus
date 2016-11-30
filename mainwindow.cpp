#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


void createXml(vector<Property> properties);
void createObjects();
void populateUi();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createObjects();

}

void MainWindow::populateUi(){
    QStandardItemModel *model = new QStandardItemModel();
    ui->propertyList->setModel( model );
    QStandardItem *item;

    cout << "----------------------";
    cout << "----------------------";


    item = new QStandardItem();
    item->setData( "ass" , Qt::DisplayRole );
    item->setEditable( false );
    model->appendRow( item );

}
MainWindow::~MainWindow()
{
    delete ui;
    delete creatorWin;
}

void createObjects(){
    Property myproperty (1, "213fartstreet", 32, 5, 3, 12041999, "manage co", 1, 555.21, 9992.1, 8221.2, 29191.2, 921.2, 23.1);
    Property myproperty1 (2, "123 WoofCrescent", 32, 5, 3, 12041999, "manage co", 1, 555.21, 9992.1, 8221.2, 29191.2, 921.2, 23.1);

    vector<Property> properties {myproperty, myproperty1};

    createXml(properties);
}

void createXml(vector<Property> properties){

    QFile file("info.xml");
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("Townhouses");

    xmlWriter.writeStartElement(QString::fromStdString(to_string(properties[0].id)));
    xmlWriter.writeTextElement("Adress", QString::fromStdString(properties[0].adress));
    xmlWriter.writeTextElement("Unit Number", QString::fromStdString(to_string(properties[0].unit)));
    xmlWriter.writeTextElement("Locker Number", QString::fromStdString(to_string(properties[0].locker)));
    xmlWriter.writeTextElement("Parking Number", QString::fromStdString(to_string(properties[0].parking)));
    xmlWriter.writeTextElement("Date Purchased", QString::fromStdString(to_string(properties[0].datePurchased)));
    xmlWriter.writeTextElement("PropManagement", QString::fromStdString(properties[0].propManagement));
    xmlWriter.writeTextElement("Status", QString::fromStdString(to_string(properties[0].status)));
    xmlWriter.writeTextElement("Lease", QString::fromStdString(to_string(properties[0].lease)));
    xmlWriter.writeTextElement("Taxes", QString::fromStdString(to_string(properties[0].taxes)));
    xmlWriter.writeTextElement("Maintenance", QString::fromStdString(to_string(properties[0].maintenance)));
    xmlWriter.writeTextElement("Utilities", QString::fromStdString(to_string(properties[0].utilities)));
    xmlWriter.writeTextElement("Purchases", QString::fromStdString(to_string(properties[0].purchases)));
    xmlWriter.writeTextElement("Misc", QString::fromStdString(to_string(properties[0].misc)));

    xmlWriter.writeEndElement();

    file.close();

}

void MainWindow::on_btnOpen_clicked()
{
    MainWindow.address = "yodel street";
    MainWindow.unit = "1234";
    creatorWin = new creator();
    creatorWin -> show();
}
