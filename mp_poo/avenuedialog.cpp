#include "avenuedialog.h"
#include "ui_avenuedialog.h"
#include "QMessageBox"
#include "avenue.h"

avenuedialog::avenuedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::avenuedialog)
{
    ui->setupUi(this);
}

avenuedialog::~avenuedialog()
{
    delete ui;
}

void avenuedialog::on_pushButton_2_clicked()
{
    avenue av;

    av.set_id(ui->lineEdit_ID->text().toInt());
    av.set_nom(ui->lineEdit_2Nom->text());
    av.Modifier();
}

void avenuedialog::on_pushButton_3_clicked()
{
    avenue av;
    av.set_id(ui->lineEdit_ID->text().toInt());
    av.set_nom(ui->lineEdit_2Nom->text());
    av.Supprimer();
}

void avenuedialog::on_pushButton_4_clicked()
{    avenue av;
     av.set_id(ui->lineEdit_ID->text().toInt());
     av.set_nom(ui->lineEdit_2Nom->text());
     av.Ajouter();
}

void avenuedialog::on_pushButton_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
     avenue A;
     modal=A.Load();
     ui->tableView->setModel(modal);
     qDebug()<<modal->rowCount();
     ui->groupBox->setEnabled(1);
}

void avenuedialog::on_tableView_activated(const QModelIndex &index)
{   dbconnection conn;
    QString val=ui->tableView->model()->data(index).toString();

        if(!conn.connOpen()){

            qDebug()<<("Not Connected");
            return;
        }
        else{

            QSqlQuery qry;
            qry.prepare("select * from Avenue where id_avenue ='"+val+"' or nom='"+val+"' ");
            if(qry.exec()){
                while(qry.next()){
                    ui->lineEdit_2Nom->setText(qry.value(1).toString());
                    ui->lineEdit_ID->setText(qry.value(0).toString());
                    ui->pushButton_2->setEnabled(1);
                    ui->pushButton_3->setEnabled(1);
                    ui->pushButton_5->setEnabled(1);
                    conn.conClose();

                }
            }
            else {
                QMessageBox::critical(this,tr("error::"),qry.lastError().text());
            }

    }
}

void avenuedialog::on_pushButton_5_clicked()
{
    ui->pushButton_4->setEnabled(1);
    ui->lineEdit_2Nom->setText("");
    ui->lineEdit_ID->setText("");
}








void avenuedialog::on_pushButton_nbr_clicked()
{
    dbconnection conn;
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.get_mydb());
    qry->prepare("select avenue , count(*) as nbre_lampes from Lampadaires group by avenue ");
    qry->exec();
    modal->setQuery(*qry);
    conn.conClose();
    ui->tableView_2->setModel(modal);

}
