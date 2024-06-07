#ifndef AVENUE_H
#define AVENUE_H
#include<QString>
#include<QtSql>
#include"dbconnection.h"
class avenue
{
    private:
    QString nom;
    int id;
public:
    avenue();
    QString get_nom();
    int get_id();
    void set_nom(QString n);
    void set_id(int i);
    void Ajouter();
    void Supprimer();
    void Modifier();
    QSqlQueryModel * Load();
    ~avenue();
};

#endif // AVENUE_H
