#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QString>
class utilisateur
{private:
    QString username;
    QString password;
    QString role;
public:
        QString get_username();
        QString get_password();
        QString get_role();

        utilisateur(); //constructeur par defaut
        void set_username(QString u);
        void set_password(QString p);
        void set_role(QString r);
        bool operator==(utilisateur &us); //surcharge d'operateur ==
        ~utilisateur();   //distructeur
};

#endif // UTILISATEUR_H
