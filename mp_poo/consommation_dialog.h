#ifndef CONSOMMATION_DIALOG_H
#define CONSOMMATION_DIALOG_H

#include <QDialog>

namespace Ui {
class Consommation_Dialog;
}

class Consommation_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Consommation_Dialog(QWidget *parent = 0);
    ~Consommation_Dialog();

private slots:

    void on_comboBox_currentIndexChanged(const QString &arg1);


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Consommation_Dialog *ui;
};

#endif // CONSOMMATION_DIALOG_H
