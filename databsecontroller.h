#ifndef DATABSECONTROLLER_H
#define DATABSECONTROLLER_H
#include <QtSql>

using namespace std;

class DatabseController : public QSqlDatabase
{
public:  
    DatabseController();

    //class methods
    vector<QString> getSingleAllInfo(QString Address, QString unit);
    vector<QString> getRowInfo(int row);
    int getRowCount();
    void deleteRow(QString Address, QString unit);
private:
    QSqlDatabase db;
};

#endif // DATABSECONTROLLER_H
