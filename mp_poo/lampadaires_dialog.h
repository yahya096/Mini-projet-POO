#ifndef LAMPADAIRES_DIALOG_H
#define LAMPADAIRES_DIALOG_H

#include <QDialog>
#include"dbconnection.h"
namespace Ui {
class Lampadaires_Dialog;
}

class Lampadaires_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Lampadaires_Dialog(QWidget *parent = 0);
    ~Lampadaires_Dialog();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);


private:
    Ui::Lampadaires_Dialog *ui;
};

#endif // LAMPADAIRES_DIALOG_H
