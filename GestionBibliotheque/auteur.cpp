#include "auteur.h"

int Auteur::nbre=0;
Auteur::Auteur()
{
    id_auteur=0;
    nom="";
    prenom="";
}
Auteur::Auteur(int id,QString nom,QString prenom)
{
    this->id_auteur=id;
    this->nom=nom;
    this->prenom=prenom;
}
Auteur::Auteur(QString nom,QString prenom)
{
    this->id_auteur=nbre;
    this->nom=nom;
    this->prenom=prenom;
    nbre++;
}
Auteur::~Auteur(){

}
void Auteur::operator=(const Auteur &a)
{
    id_auteur=a.id_auteur;
    nom=a.nom;
    prenom=a.prenom;
}
