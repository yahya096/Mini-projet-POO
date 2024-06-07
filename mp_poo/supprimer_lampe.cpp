#include "supprimer_lampe.h"
#include "ui_supprimer_lampe.h"

supprimer_lampe::supprimer_lampe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_lampe)
{
    ui->setupUi(this);
}

supprimer_lampe::~supprimer_lampe()
{
    delete ui;
}
