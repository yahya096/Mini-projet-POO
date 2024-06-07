#include "consommation_dialog.h"
#include "ui_consommation_dialog.h"
#include<QtSql>
#include"lampadaires.h"
#include"consommation.h"
Consommation_Dialog::Consommation_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Consommation_Dialog)
{
    ui->setupUi(this);
    QSqlQueryModel * modal=new QSqlQueryModel();
    lampadaires L;
    modal=L.Load();
    ui->comboBox->setModel(modal);
}

Consommation_Dialog::~Consommation_Dialog()
{
    delete ui;
}

void Consommation_Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    dbconnection conn;

    if(!conn.connOpen()){
        qDebug()<<("Not Connected");
        return;
    }
    else{

        QSqlQuery qry;
        qry.prepare("select * from Lampadaires where ID_Lampadaires='"+arg1+"'");
        if(qry.exec()){
            while(qry.next()){
                ui->lineEdit_nom->setText(qry.value(1).toString());
                ui->lineEdit_type->setText(qry.value(2).toString());
                ui->lineEdit_av->setText(qry.value(3).toString());
                ui->lineEdit_cume->setText(qry.value(4).toString());
            }

        }
    }
conn.conClose();
}


void Consommation_Dialog::on_pushButton_clicked()
{
    Consommation C;
    QSqlQueryModel * modal=new QSqlQueryModel();
    modal=C.Load();
    ui->table_lampes->setModel(modal);
    qDebug()<<modal->rowCount();
}

void Consommation_Dialog::on_pushButton_2_clicked()
{
    Consommation C;
    C.set_id(ui->comboBox->currentText().toInt());
    C.delete_c();
}
