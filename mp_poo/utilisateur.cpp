#include "utilisateur.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
utilisateur::utilisateur(){ //constructeur par defaut
    username="";
    password="";
    role="";
}
utilisateur::~utilisateur(){} //Distructeur
QString utilisateur::get_username()
{
    return username;
}

QString utilisateur::get_password()
{
   return password ;
}

QString utilisateur::get_role()
{
   return role ;
}

void utilisateur:: set_username(QString u)
{
   username=u;
}
void utilisateur::set_password(QString p)
{
   password=p;
}
void utilisateur::set_role(QString r)
{
   role=r;
}
bool utilisateur::operator==(utilisateur &us){  //surcharge de loperator ==
      if(us.get_password()==password && us.get_username()==username && us.get_role()==role)
           return(true);
              else
           return(false);
}
