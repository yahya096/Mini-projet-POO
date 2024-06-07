#include "supprimer_avenue.h"
#include "ui_supprimer_avenue.h"

supprimer_avenue::supprimer_avenue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_avenue)
{
    ui->setupUi(this);
}

supprimer_avenue::~supprimer_avenue()
{
    delete ui;
}
