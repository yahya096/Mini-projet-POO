#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
class dbconnection
{
private:
    QSqlDatabase mydbi;
public:
    dbconnection();
    bool connOpen();
    void conClose();
    QSqlDatabase get_mydb();
    ~dbconnection();

};

#endif // DBCONNECTION_H
