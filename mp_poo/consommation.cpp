#include "consommation.h"
#include<QtSql>
#include"lampadaires.h"
Consommation::Consommation()
{
}
int Consommation::get_id(){
   return(idlampe);
}
void Consommation::set_id(int i){
   idlampe=i;
}
void Consommation::delete_c(){
    dbconnection conn;
    if(!conn.connOpen()){
        qDebug()<<("Not Connected");
        return;
    }
    else{

           QSqlQuery qry;
           qry.prepare("Delete from Consommation where idlampe ='"+QString::number(idlampe)+"' ");
           if(qry.exec()){
               qDebug()<<"deleted successfully";
           }

           else {
            qDebug()<<"ERREUR";
          }
       }
conn.conClose();
}
void Consommation::ajouter(){
    dbconnection conn;
    QString m;
    if(!conn.connOpen()){
        qDebug()<<("Not Connected");
        return;
    }
    else{

        QSqlQuery qry;

       qry.prepare("select * from Lampadaires ");
       if(qry.exec()){
          while(qry.next()){
          m =qry.value(0).toString();
          }
           QSqlQuery a;
           a.prepare("insert into Consommation (idlampe) values ('"+m+"') ");
           if(a.exec()){
               qDebug()<<"saved successfully";
           }

        }
        else {
            qDebug()<<"Not Saved";
        }
}conn.conClose();
}
QSqlQueryModel* Consommation:: Load(){
    dbconnection conn;
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.get_mydb());
    qry->prepare("select * from Consommation");
    qry->exec();
    modal->setQuery(*qry);
    conn.conClose();
    return modal;
}
Consommation::~Consommation(){}
