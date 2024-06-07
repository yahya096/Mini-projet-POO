#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H
#include <QDialog>
#include"lampadaires_dialog.h"
#include"avenuedialog.h"
#include"consommation_dialog.h"
#include"userdialog.h"
namespace Ui {
class adminDialog;
}

class adminDialog : public QDialog
{
    Q_OBJECT

public:


    explicit adminDialog(QWidget *parent = 0);
    ~adminDialog();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::adminDialog *ui;
    Lampadaires_Dialog *tab;
    avenuedialog *av;
    Consommation_Dialog * co;
    userDialog *us;
};

#endif // ADMINDIALOG_H
