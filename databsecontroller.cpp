#include "databsecontroller.h"
#include <QDebug>

DatabseController::DatabseController()
{
    //creating database conenction to local db
    //in a actual program never leave server data
    //in the code and plaintext
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("propertyplus");
    db.setUserName("root");
    db.setPassword("abc123");

    if(db.open())
    {
        qDebug() << "connected " << db.hostName();
    }else{
    qDebug() << "Connection FAILED.";

    }

}

//get the all the info for a specific property
vector<QString> DatabseController::getSingleAllInfo(QString Address, QString unit){
    //create a model
    QSqlTableModel model;
    model.setTable("properties");
    model.select();

    //search through each row
    for (int i = 0; i < model.rowCount(); ++i) {
        //check each row if the rows address and unit match the ones you want
        if(Address == model.record(i).value("address").toString() & unit == model.record(i).value("unit").toString()){
            //if they match store the row into variables
            QString modelAd = model.record(i).value("address").toString();
            QString modelUnit = model.record(i).value("unit").toString();
            QString modelLocker = model.record(i).value("locker").toString();
            QString modelParking = model.record(i).value("parking").toString();
            QString modelDate = model.record(i).value("date").toString();
            QString modelCompany = model.record(i).value("company").toString();
            QString modelStatus = model.record(i).value("status").toString();
            QString modelLease = model.record(i).value("leaseamount").toString();
            QString modelTaxes = model.record(i).value("taxes").toString();
            QString modelUtil = model.record(i).value("utilities").toString();
            QString modelMaint = model.record(i).value("maintenance").toString();
            QString modelPurch = model.record(i).value("purchases").toString();
            QString modelMisc = model.record(i).value("miscellaneous").toString();

            //put row info into a vector
            vector<QString> info {modelAd, modelUnit, modelLocker, modelParking, modelDate, modelCompany, modelStatus, modelLease, modelTaxes, modelUtil, modelMaint, modelPurch, modelMisc};

            return info;
            //end for loop
            break;
        }

    }
    //if not exists
    // this is a bad way to do this
    //Not safe and could break program
    //in future fix error handling
    //maybe try to catch an error instead
    QString bad = "Doesnt exist";
    vector<QString> empty {bad};
    return empty;
}

//get row info on a specific row given a number
vector<QString> DatabseController::getRowInfo(int row){
    //setup model
        QSqlTableModel model;
        model.setTable("properties");
        model.select();

        //put row values into variables
        QString modelAd = model.record(row).value("address").toString();
        QString modelUnit = model.record(row).value("unit").toString();
        QString modelLocker = model.record(row).value("locker").toString();
        QString modelParking = model.record(row).value("parking").toString();
        QString modelDate = model.record(row).value("date").toString();
        QString modelCompany = model.record(row).value("company").toString();
        QString modelStatus = model.record(row).value("status").toString();
        QString modelLease = model.record(row).value("leaseamount").toString();
        QString modelTaxes = model.record(row).value("taxes").toString();
        QString modelUtil = model.record(row).value("utilities").toString();
        QString modelMaint = model.record(row).value("maintenance").toString();
        QString modelPurch = model.record(row).value("purchases").toString();
        QString modelMisc = model.record(row).value("miscellaneous").toString();

        //put the variables into a vector
        vector<QString> info {modelAd, modelUnit, modelLocker, modelParking, modelDate, modelCompany, modelStatus, modelLease, modelTaxes, modelUtil, modelMaint, modelPurch, modelMisc};

        return info;
}

//get the amount of rows in the table
int DatabseController::getRowCount(){
    QSqlTableModel model;
    model.setTable("properties");
    model.select();
    return model.rowCount();

}

//remove a row from the table
void DatabseController::deleteRow(QString Address, QString unit){
    //setup model
    QSqlTableModel model;
    model.setTable("properties");
    model.select();

    //parse through each row to find matching building
    for (int i = 0; i < model.rowCount(); ++i) {
        if(Address == model.record(i).value("address").toString() & unit == model.record(i).value("unit").toString()){
            //when matching delete the row
            model.removeRow(i);
            //submitAll enures the change gets pushed through
            model.submitAll();
            break;
        }

    }

}
