#ifndef SUPPRIMER_AVENUE_H
#define SUPPRIMER_AVENUE_H

#include <QDialog>

namespace Ui {
class supprimer_avenue;
}

class supprimer_avenue : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_avenue(QWidget *parent = 0);
    ~supprimer_avenue();

private:
    Ui::supprimer_avenue *ui;
};

#endif // SUPPRIMER_AVENUE_H
