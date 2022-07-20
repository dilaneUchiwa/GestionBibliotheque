#include "emprunt.h"


int Emprunt::nbre=0;
Emprunt::Emprunt(Adherent a,Exemplaire e,QDate date_emprunt,QDate date_retour_prevue,QDate date_retour_effectif,bool statut)
{
    adherent=a;
    exemplaire=e;
    this->date_emprunt=date_emprunt;
    this->date_retour_prevue=date_retour_prevue;
    this->date_retour_effectif=date_retour_effectif;
    this->statut=statut;
}
Emprunt::Emprunt(QDate date_emprunt,QDate date_retour_prevue,QDate date_retour_effectif,bool statut)
{
    this->date_emprunt=date_emprunt;
    this->date_retour_prevue=date_retour_prevue;
    this->date_retour_effectif=date_retour_effectif;
    this->statut=statut;
    nbre++;
}
Emprunt::Emprunt()
{
    
}
Emprunt::~Emprunt(){

}

