#ifndef CONSOMMATION_H
#define CONSOMMATION_H
#include<QtSql>
class Consommation
{
private:
    int idlampe = 0 ;
public:
    Consommation();
    int get_id();
    void set_id(int id);
    void ajouter();
    void delete_c();
    QSqlQueryModel * Load();
    ~Consommation();
};

#endif // CONSOMMATION_H
