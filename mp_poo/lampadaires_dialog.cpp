#include "lampadaires_dialog.h"
#include"lampadaires.h"
#include "ui_lampadaires_dialog.h"
#include"consommation.h"
#include"avenue.h"
#include<QMessageBox>

Lampadaires_Dialog::Lampadaires_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lampadaires_Dialog)
{
    ui->setupUi(this);
}


Lampadaires_Dialog::~Lampadaires_Dialog()
{
    delete ui;
}

void Lampadaires_Dialog::on_pushButton_5_clicked()
{
        ui->pushButton->setEnabled(1);
        ui->lineEditid->setText("");
        ui->lineEdit_av->setText("");
        ui->lineEdit_cume->setText("");
        ui->lineEdit_nom->setText("");
        ui->lineEdit_type->setText("");

}

void Lampadaires_Dialog::on_pushButton_clicked()
{
    Consommation C;
    lampadaires lamp;
    lamp.set_id(ui->lineEditid->text().toInt());
    lamp.set_avenue(ui->lineEdit_av->text());
    lamp.set_cumulEnergie(ui->lineEdit_cume->text().toFloat());
    lamp.set_nom(ui->lineEdit_nom->text());
    lamp.set_type(ui->lineEdit_type->text());
    lamp.Ajouter();
    C.ajouter();
}

void Lampadaires_Dialog::on_pushButton_4_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
     lampadaires C;
     modal=C.Load();
     ui->tableView->setModel(modal);
     qDebug()<<modal->rowCount();
}

void Lampadaires_Dialog::on_pushButton_2_clicked()
{
    lampadaires lamp;
    lamp.set_id(ui->lineEditid->text().toInt());
    lamp.set_avenue(ui->lineEdit_av->text());
    lamp.set_cumulEnergie(ui->lineEdit_cume->text().toFloat());
    lamp.set_nom(ui->lineEdit_nom->text());
    lamp.set_type(ui->lineEdit_type->text());
    lamp.Modifier();
}

void Lampadaires_Dialog::on_pushButton_3_clicked()
{
    lampadaires lamp;
    lamp.set_id(ui->lineEditid->text().toInt());
    lamp.set_avenue(ui->lineEdit_av->text());
    lamp.set_cumulEnergie(ui->lineEdit_cume->text().toFloat());
    lamp.set_nom(ui->lineEdit_nom->text());
    lamp.set_type(ui->lineEdit_type->text());
    lamp.Supprimer();

}

void Lampadaires_Dialog::on_tableView_activated(const QModelIndex &index)
{
    dbconnection conn;
    QString val=ui->tableView->model()->data(index).toString();

    if(!conn.connOpen()){
        qDebug()<<("Not Connected");
        return;
    }
    else{

        QSqlQuery qry;
        qry.prepare("select * from Lampadaires where ID_Lampadaires='"+val+"' or nom='"+val+"' or type='"+val+"' or avenue='"+val+"' or cumulEnergie='"+val+"' ");
        if(qry.exec()){
            while(qry.next()){
                ui->lineEditid->setText(qry.value(0).toString());
                ui->lineEdit_nom->setText(qry.value(1).toString());
                ui->lineEdit_type->setText(qry.value(2).toString());
                ui->lineEdit_av->setText(qry.value(3).toString());
                ui->lineEdit_cume->setText(qry.value(4).toString());
                ui->pushButton_5->setEnabled(1);
                ui->pushButton_2->setEnabled(1);
                ui->pushButton_3->setEnabled(1);
            }

        }
        else {
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
    }
conn.conClose();
}

