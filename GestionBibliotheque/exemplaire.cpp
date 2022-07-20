#include "exemplaire.h"

int Exemplaire::nbre=0;
Exemplaire::Exemplaire(int id_Exemplaire,Livre livre,QString etat)
{
    this->id_exemplaire=id_Exemplaire;
    this->livre=livre;
    this->etat=etat;
}
Exemplaire::Exemplaire(Livre livre,QString etat)
{
    this->id_exemplaire=nbre;
    this->livre=livre;
    this->etat=etat;
    nbre++;
}
Exemplaire::Exemplaire(){
    this->id_exemplaire=0;
    this->livre=*new Livre();
    this->etat="";
}
Exemplaire::~Exemplaire(){

}
void Exemplaire::operator=(const Exemplaire &a)
{
    id_exemplaire=a.id_exemplaire;
    livre=a.livre;
    etat=a.etat;
}


