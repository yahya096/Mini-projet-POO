#include "admindialog.h"
#include"mainwindow.h"
#include "ui_admindialog.h"
#include<QMessageBox>
#include<QTextStream>
#include<QPixmap>
#include<QFile>
#include<QFileDialog>
#include<QDir>
QString file_name="";

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);
}


adminDialog::~adminDialog()
{
    delete ui;
}


void adminDialog::on_pushButton_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"file","not open");
     }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void adminDialog::on_pushButton_2_clicked()
{

    QString filter="Text File(*.txt)";
    file_name = QFileDialog::getOpenFileName(this,"open file ","./",filter);
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"file","not open");
     }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();

    ui->pushButton->setEnabled(1);



}





void adminDialog::on_pushButton_4_clicked()
{
    tab=new Lampadaires_Dialog (this);
    tab->show();

}


void adminDialog::on_pushButton_3_clicked()
{
    av=new avenuedialog (this);
    av->show();
}

void adminDialog::on_pushButton_5_clicked()
{
    co=new Consommation_Dialog (this);
    co->show();
}

void adminDialog::on_pushButton_6_clicked()
{
    us=new userDialog (this);
    us->show();
}
