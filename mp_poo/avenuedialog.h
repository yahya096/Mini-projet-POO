#ifndef AVENUEDIALOG_H
#define AVENUEDIALOG_H

#include <QDialog>
#include "dbconnection.h"

namespace Ui {
class avenuedialog;
}

class avenuedialog : public QDialog
{
    Q_OBJECT

public:
    explicit avenuedialog(QWidget *parent = 0);
    ~avenuedialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_nbr_clicked();


private:
    Ui::avenuedialog *ui;

};

#endif // AVENUEDIALOG_H
