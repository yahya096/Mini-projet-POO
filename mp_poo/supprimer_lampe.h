#ifndef SUPPRIMER_LAMPE_H
#define SUPPRIMER_LAMPE_H

#include <QDialog>

namespace Ui {
class supprimer_lampe;
}

class supprimer_lampe : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_lampe(QWidget *parent = 0);
    ~supprimer_lampe();

private:
    Ui::supprimer_lampe *ui;
};

#endif // SUPPRIMER_LAMPE_H
