#include "avenue.h"

avenue::avenue()
{
int id=0;
QString nom="";
}
QString avenue::get_nom()
{
    return nom;
}
int avenue::get_id()
{
    return id;
}
void avenue::set_nom(QString n)
{
    nom=n;
}
void avenue::set_id(int i)
{
    id=i;
}


void avenue::Ajouter(){
    dbconnection conn;
    if(!conn.connOpen()){
        qDebug()<<("Not Connected");
        return;
    }
    else{
        QSqlQuery qry;
           qry.prepare("insert into Avenue (nom) values ('"+nom+"') ");
           if(qry.exec()){
               qDebug()<<"saved successfully";
           }
           else qDebug()<<"not saved";
        }
conn.conClose();
}
void avenue::Modifier(){
    dbconnection conn;
    if(!conn.connOpen()){
        qDebug()<<("Not Connected");
        return;
    }
    else{
        QSqlQuery qry;
        qry.prepare("update Avenue set nom= '"+nom+"' where id_avenue= '"+QString::number(id)+"' ");
        if(qry.exec()){
            qDebug()<<"updated Successfully";
            conn.conClose();
        }
        else {
            qDebug()<<"Not Updated";
        }
    }

}
void avenue::Supprimer(){
    dbconnection conn;
    if(!conn.connOpen()){

        qDebug()<<("Not Connected");
        return;
    }
    else{
        QSqlQuery qry;
        qry.prepare("Delete from Avenue where id_avenue ='"+QString::number(id)+"' ");
        if(qry.exec()){
            qDebug()<<"Deleted Successfully";
            conn.conClose();
        }
        else {
            qDebug()<<"Not Deleted";
        }

    }
}
QSqlQueryModel* avenue::Load(){
    dbconnection conn;
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.get_mydb());
    qry->prepare("select * from Avenue");
    qry->exec();
    modal->setQuery(*qry);
    conn.conClose();
    return modal;

}
avenue::~avenue(){

}
