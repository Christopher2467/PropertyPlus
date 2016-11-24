#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


void createXml(vector<Property> properties);
vector<Property> createObjects();
void populateUi(vector<Property>  myproperty);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createObjects();

    populateUi(createObjects());


}

void MainWindow::populateUi(vector<Property> myproperty){
    QStandardItemModel *model = new QStandardItemModel();
    ui->propertyList->setModel( model );
    QStandardItem *item;

    cout << "----------------------";
    cout << myproperty[1].adress;
    cout << "----------------------";


    item = new QStandardItem();
    item->setData( "ass" , Qt::DisplayRole );
    item->setEditable( false );
    model->appendRow( item );

}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<Property> createObjects(){
    Property myproperty (1, "213fartstreet", "mr.dog", 20, 1000);
    Property myproperty1 (2, "123 WoofCrescent", "mr.Cat", 3, 940);
    Property myproperty2 (3, "Stephensons Streest", "Gary Johnson", 4, 900);
    Property mypropery3 (4, "Burnamthopre Crescent", "Steve Jobs", 332, 1034);
    Property myproperty4 (5, "Leachview Crescent", "Katie Williams", 7, 3001);
    Property myproperty5 (6, "MyDog View", "Cat fart", 5, 3323);

    vector<Property> properties {myproperty, myproperty1, myproperty2, mypropery3, myproperty4, myproperty5};

    createXml(properties);

    return properties;
}

void createXml(vector<Property> properties){

    QFile file("info.xml");
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("Townhouses");

    for(int i = 0; i < 6; i++){
    xmlWriter.writeStartElement(QString::fromStdString(to_string(properties[i].id)));
    xmlWriter.writeTextElement("Adress", QString::fromStdString(properties[i].adress));
    xmlWriter.writeTextElement("Tenants", QString::fromStdString(properties[i].tenants));
    xmlWriter.writeTextElement("Term", QString::fromStdString(to_string(properties[i].term)));
    xmlWriter.writeTextElement("Rent", QString::fromStdString(to_string(properties[i].rent)));

    xmlWriter.writeEndElement();
    }

    file.close();

}


void MainWindow::on_btnOpen_clicked()
{

}
