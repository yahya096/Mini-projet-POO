#ifndef USERDIALOG_H
#define USERDIALOG_H
#include <QDialog>

namespace Ui {
class userDialog;
}

class userDialog : public QDialog
{
    Q_OBJECT

public:

    explicit userDialog(QWidget *parent = 0);
    ~userDialog();
public slots:
        void function_timer();
private slots:


    void on_allume_1_clicked();

    void on_eteindre1_clicked();

private:
    Ui::userDialog *ui;
    QTimer *timer;
};

#endif // USERDIALOG_H
