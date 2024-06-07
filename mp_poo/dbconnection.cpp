#include "dbconnection.h"

dbconnection::dbconnection()
{
    mydbi=QSqlDatabase::addDatabase("QSQLITE");
    mydbi.setDatabaseName("./MP_Database.db");

}


bool dbconnection::connOpen(){

    if(!mydbi.open())
    {
        qDebug()<<("Not Connected");
        return false;
    }
    else
        {
         qDebug()<<("Connected");
        return true;
        }

}
void dbconnection::conClose(){
    mydbi.close();
    mydbi.removeDatabase(QSqlDatabase::defaultConnection);
}
QSqlDatabase dbconnection::get_mydb(){
    return mydbi;
}
dbconnection::~dbconnection(){}


