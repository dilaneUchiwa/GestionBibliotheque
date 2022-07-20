#include "adherent.h"

int Adherent::nbre=0;
Adherent::Adherent()
{
    id_adherent=0;
    nom="";
    prenom="";
}
Adherent::Adherent(int id,QString nom,QString prenom,char sexe,int tel,QString adresse)
{
    this->id_adherent=id;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->tel=tel;
    this->adresse=adresse;
}
Adherent::~Adherent(){

}
void Adherent::operator=(const Adherent &a)
{
    id_adherent=a.id_adherent;
    nom=a.nom;
    prenom=a.prenom;
    sexe=a.sexe;
    tel=a.tel;
    adresse=a.adresse;
}
