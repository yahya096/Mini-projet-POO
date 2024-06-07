#include "lampadaires.h"
#include"dbconnection.h"
#include<QString>
#include<QDebug>
#include<Qtsql>
lampadaires::lampadaires()
{
    int id=0;
    QString nom="";
    QString type="";
    QString avenue="";
    float cumulEnergie=0.0;
}

QString lampadaires::get_nom(){
    return nom;
}
QString lampadaires::get_avenue(){
    return avenue;
}
QString lampadaires::get_type(){
    return type;
}
int lampadaires::get_id(){
    return id;
}
float lampadaires::get_cumulEnergie(){
    return cumulEnergie;
}
void lampadaires::set_nom(QString n){
    nom=n;
}
void lampadaires::set_avenue(QString a){
    avenue=a;
}
void lampadaires::set_type(QString t){
    type=t;
}
void lampadaires::set_id(int i){
    id=i;
}
void lampadaires::set_cumulEnergie(float ce){
    cumulEnergie=ce;
}
void lampadaires::Ajouter(){
    dbconnection conn;
    if(!conn.connOpen()){
        qDebug()<<("Not Connected");
        return;
    }
    else{

       QSqlQuery qry;

       qry.prepare("insert into Lampadaires (nom,type,avenue,cumulEnergie) values ('"+nom+"','"+type+"','"+avenue+"','"+QString::number(cumulEnergie)+"') ");
       if(qry.exec()){
            qDebug()<<"Saved Successfully";
            conn.conClose();
        }
        else {
            qDebug()<<"Not Saved";
        }
}
}
void lampadaires::Modifier(){
    dbconnection conn;
    if(!conn.connOpen()){
        qDebug()<<("Not Connected");
        return;
    }
    else{
        QSqlQuery qry;
        qry.prepare("update Lampadaires set nom= '"+nom+"', type= '"+type+"', avenue= '"+avenue+"', cumulEnergie= '"+QString::number(cumulEnergie)+"' where ID_Lampadaires= '"+QString::number(id)+"' ");
        if(qry.exec()){
            qDebug()<<"updated Successfully";
            conn.conClose();
        }
        else {
            qDebug()<<"Not Updated";
        }
    }

}
void lampadaires::Supprimer(){
    dbconnection conn;
    if(!conn.connOpen()){

        qDebug()<<("Not Connected");
        return;
    }
    else{
        QSqlQuery qry;
        qry.prepare("Delete from Lampadaires where ID_Lampadaires ='"+QString::number(id)+"' ");
        if(qry.exec()){
            qDebug()<<"Deleted Successfully";
            conn.conClose();
        }
        else {
            qDebug()<<"Not Deleted";
        }

    }
}
QSqlQueryModel* lampadaires::Load(){
    dbconnection conn;
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.get_mydb());
    qry->prepare("select * from Lampadaires");
    qry->exec();
    modal->setQuery(*qry);
    conn.conClose();
    return modal;

}
lampadaires::~lampadaires(){

}
