#include "userdialog.h"
#include "ui_userdialog.h"
#include "mainwindow.h"
#include"avenue.h"
userDialog::userDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userDialog)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(function_timer()));
    timer->start(1000);
    dbconnection conn;
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.get_mydb());
    qry->prepare("select Nom from Avenue");
    qry->exec();
    modal->setQuery(*qry);
    conn.conClose();
    ui->comboBox->setModel(modal);

}
userDialog::~userDialog()
{
    delete ui;
}
void userDialog::function_timer(){
    QTime t = QTime::currentTime();
    QString horloge = t.toString("hh : mm : ss");
    ui->label->setText(horloge);
}


void userDialog::on_allume_1_clicked()
{

    dbconnection conn;
    QTime time = QTime::currentTime();
    QString time_;
    time_ = time.toString("hh:mm:ss");
    QString m = ui->comboBox->currentText();
    QString n = ui->comboBox->currentText();
    conn.connOpen();
    QSqlQuery a;
    a.prepare("select * from Lampadaires where avenue= '"+m+"' ");
    if(a.exec()){
        while(a.next()){
            m = a.value(0).toString();
            QSqlQuery b;
            /* Activer les lampes d'un avenue*/
            b.prepare("UPDATE Consommation SET hdebut='"+time_+"' WHERE idlampe='"+m+"'");
            if(b.exec()){
               qDebug()<<"les lampes sont tous allumés";
            }
            qDebug() << m;
            QPushButton *button = ui->allume_1;
            QPushButton *button2 = ui->eteindre1;
            button->setStyleSheet("background-color: Green;border: 2px solid white;border-radius: 10px; font-size: 12px;");
            button2->setStyleSheet("background-color: transparent;border: 2px solid white;border-radius: 10px; font-size: 12px;");

    }
    }
   conn.conClose();
   ui->eteindre1->setEnabled(1);
   ui->label_15->setText(n);
   ui->CA->setText("");
   ui->con->setText("");

}

void userDialog::on_eteindre1_clicked()
{

    dbconnection conn;
    QString h, cue;
    QTime time = QTime::currentTime();
    QString time_;
    time_ = time.toString("hh:mm:ss");
    QString m= ui->comboBox->currentText();
    conn.connOpen();
    QSqlQuery a;
    a.prepare("select ID_Lampadaires from Lampadaires where avenue= '"+m+"' ");
    if(a.exec()){
        while(a.next()){
            m = a.value(0).toString();
            QSqlQuery b;
            /* Activer les lampes d'un avenue*/
            b.prepare("UPDATE Consommation SET hrfin='"+time_+"' WHERE idlampe='"+m+"'");
            if(b.exec()){
               qDebug()<<"Les lampes sont tous eteints";
            }
            qDebug() << m;
            QSqlQuery c;
            QString h1,h2;
            int hd,md,sd,hf,mf,sf;
            c.prepare("select * from Consommation where idlampe='"+m+"'");
            if(c.exec()){
            while(c.next()){
                h1 = c.value(2).toString();
                h2 = c.value(3).toString();
            hd = h1.mid(0,2).toUInt();
            md = h1.mid(3,2).toUInt();
            sd = h1.mid(6,2).toUInt();
            hf = h2.mid(0,2).toUInt();
            mf = h2.mid(3,2).toUInt();
            sf = h2.mid(6,2).toUInt();
            float temps = (hf-hd)*3600+(mf-md)*60+(sf-sd);
            float consomme = (temps*300.0f)/3600.0f; //une lampadaire rue consomme entre 250 et 400 W en suppose ici 300
            h.sprintf("%f",consomme);
            h=QString::number(h.toFloat(), 'f', 2);// ce limiter a 2 chiffres apres la virgule

            }}
            QSqlQuery d;
            d.prepare("update Consommation SET consommation='"+h+"' WHERE idlampe='"+m+"'");
            if(d.exec()){
                qDebug()<<h;
            }
            float consomm;
            QSqlQuery e;
            e.prepare("select cumulEnergie from Lampadaires where ID_Lampadaires='"+m+"'");
            if(e.exec()){
                while(e.next()){
            consomm = h.toFloat() + e.value(0).toFloat();}}
            cue.sprintf("%f",consomm);
            cue=QString::number(cue.toFloat(), 'f', 2);// ce limiter a 2 chiffres apres la virgule
                   QSqlQuery g;
            g.prepare("UPDATE Lampadaires SET cumulEnergie='"+cue+"' WHERE ID_Lampadaires='"+m+"'");
            if(g.exec()){qDebug()<<cue;}



    }


    }
         ui->con->setText(cue);
         ui->CA->setText(h);
         QPushButton *button = ui->allume_1;
         QPushButton *button2 = ui->eteindre1;
         button->setStyleSheet("background-color: transparent;border: 2px solid white;border-radius: 10px; font-size: 12px;");
         button2->setStyleSheet("background-color: red;border: 2px solid white;border-radius: 10px; font-size: 12px;;");





         conn.conClose();

}
