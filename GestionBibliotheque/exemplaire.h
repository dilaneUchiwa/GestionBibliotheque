#ifndef EXEMPLAIRE_H
#define EXEMPLAIRE_H
#include "livre.h"
#include <QWidget>


class Exemplaire
{
    public:
        Exemplaire();
        Exemplaire(int id_Exemplaire,Livre l,QString etat=nullptr); // un peu comme de recopie pour recuperer les donnees de la BD , ON INCREMENTE PAS LE NBRE ICI
        Exemplaire(Livre l,QString etat=nullptr); // pour creer de nouvelles donnees
        ~Exemplaire();
        int getId_exemplaire(){return id_exemplaire;}
        Livre getLivre(){return livre;}
        QString getEtat(){return etat;}
        void setId_exemplaire(int id){id_exemplaire=id;}
        void setLivre(Livre l){livre=l;}
        void setEtat(QString t){etat=t;}
        void operator=(const Exemplaire &a);
        static int nbre;

    private:
        int id_exemplaire;
        Livre livre;
        QString etat;

};

#endif // EXEMPLAIRE_H
