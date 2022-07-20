#include "livre.h"

int Livre::nbre=0;
Livre::Livre(int id_livre,QString titre,Auteur a,int an)
{
    this->id_livre=id_livre;
    this->titre=titre;
    this->auteur=a;
    this->annee=an;
}
Livre::Livre(QString titre,Auteur a,int annee)
{
    this->id_livre=nbre;
    this->titre=titre;
    this->auteur=a;
    this->annee=annee;
    nbre++;
}
Livre::Livre(){
    this->id_livre=0;
    this->titre="";
    this->auteur=*(new Auteur());
    this->annee=1975;
}
Livre::~Livre(){

}
void Livre::operator=(const Livre &a)
{
    this->id_livre=a.id_livre;
    this->titre=a.titre;
    this->auteur=a.auteur;
    this->annee=a.annee;
}


