#ifndef LIVRE_H
#define LIVRE_H
#include "auteur.h"
#include <QWidget>


class Livre
{
    public:
        Livre();
        Livre(int id_livre,QString titre,Auteur a,int annee); // un peu comme de recopie pour recuperer les donnees de la BD , ON INCREMENTE PAS LE NBRE ICI
        Livre(QString titre,Auteur a,int annee); // pour creer de nouvelles donnees
        ~Livre();
        Auteur getAuteur(){return auteur;}
        int getId_livre(){return id_livre;}
        QString getTitre(){return titre;}
        int getAnnee(){return annee;}
        void setAuteur(Auteur a){auteur=a;}
        void setId_livre(int id){id_livre=id;}
        void setTitre(QString t){titre=t;}
        void setAnnee(int a){annee=a;}
        void operator=(const Livre &a);
        static int nbre;

    private:
        int id_livre;
        QString titre;
        Auteur auteur;
        int annee;

};

#endif // LIVRE_H
