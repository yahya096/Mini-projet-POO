#ifndef LAMPADAIRES_H
#define LAMPADAIRES_H
#include<QString>
#include<Qtsql>
#include"dbconnection.h"
class lampadaires
{
private:
    QString nom;
    int id;
    QString type;
    QString avenue;
    float cumulEnergie;
public:
    lampadaires();
    QString get_nom();
    int get_id();
    QString get_type();
    QString get_avenue();
    float get_cumulEnergie();
    void set_nom(QString n);
    void set_id(int i);
    void set_type(QString t);
    void set_avenue(QString a);
    void set_cumulEnergie(float ce);

    void Ajouter();
    void Supprimer();
    void Modifier();
    QSqlQueryModel * Load();
    ~lampadaires();
};

#endif // LAMPADAIRES_H
