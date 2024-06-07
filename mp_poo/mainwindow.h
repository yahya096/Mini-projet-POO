#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtSql>
#include<QFileInfo>
#include<QDebug>
#include <QMainWindow>
#include <QVector>
#include "utilisateur.h"
#include"userdialog.h"
#include"admindialog.h"
#include"dbconnection.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    QVector<utilisateur> liste_user;

    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_checkBox_clicked();

private:
    Ui::MainWindow *ui;
    userDialog *dialog;
    adminDialog *admin;



};

#endif // MAINWINDOW_H
