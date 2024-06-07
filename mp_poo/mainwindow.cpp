#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include"QMessageBox"
#include"QPixmap"
#include <QTextStream>
#include<QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    dbconnection conn;
    ui->setupUi(this);
    if(ui->checkBox->isChecked()){
        ui->lineEdit__password->setEchoMode(QLineEdit::Normal);
    }

    if(!conn.connOpen())
        ui->label_3->setText("Not Connected");
    else{
        ui->label_3->setText("Connected");
        conn.conClose();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
        dbconnection conn;
        utilisateur us;    
        us.set_username(ui->lineEdit_user_name->text());
        us.set_password(ui->lineEdit__password->text());
        if(ui->radioButton->isChecked()){
            us.set_role("administrateur");
        }
        else{
            us.set_role("utilisateur");
        }
        if(!conn.connOpen()){

            qDebug()<<("Not Connected");
            return;
        }
        else{

            QSqlQuery qry;
            qry.prepare("select * from Login where username='"+us.get_username()+"' and pwd='"+us.get_password()+"' and role= '"+us.get_role()+"' ");
            if(qry.exec()){
                int count =0;
                while(qry.next()){
                    count++;
                }


                if(count==0){
                    QMessageBox::information(this,"Login","utilisatuer non existant");

                }
                else{
                    if(us.get_role()=="administrateur"){
                                qDebug()<<"username and password is correct";
                                admin=new adminDialog(this);
                                //hide();
                                admin->show();
                                conn.conClose();
                    }
                else{

                        qDebug()<<"username and password is correct";
                       // hide();
                        dialog=new userDialog(this);
                        dialog->show();
                        conn.conClose();

                   }

                }
            }


        }
}




void MainWindow::on_checkBox_clicked()
{
     if(ui->checkBox->isChecked())
          ui->lineEdit__password->setEchoMode(QLineEdit::Normal);
     else
         ui->lineEdit__password->setEchoMode(QLineEdit::Password);


}
