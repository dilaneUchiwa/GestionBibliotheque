#ifndef EMPRUNT_H
#define EMPRUNT_H
#include "adherent.h"
#include "exemplaire.h"

#include <QWidget>
#include<QDate>


class Emprunt
{
    public:
        Emprunt();
        Emprunt(Adherent a,Exemplaire e,QDate date_emprunt,QDate date_retour_prevue,QDate date_retour_effectif,bool statut=false); // un peu comme de recopie pour recuperer les donnees de la BD , ON INCREMENTE PAS LE NBRE ICI
        Emprunt(QDate date_emprunt,QDate date_retour_prevue,QDate date_retour_effectif,bool statut=false); // pour creer de nouvelles donnees
        ~Emprunt();
        Adherent getAdherent(){return adherent;}
        Exemplaire getExemplaire(){return exemplaire;}
        QDate getDate_emprunt(){return date_emprunt;}
        QDate getDate_retour_prevu(){return date_retour_prevue;}
        QDate getDate_retour_effectif(){return date_retour_effectif;}
        bool getStatut(){return statut;}

        void setExemplaire(Exemplaire e){exemplaire=e;}
        void setAdherent(Adherent a){adherent=a;}
        void setDate_emprunt(QDate d){date_emprunt=d;}
        void setDate_retour_prevu(QDate d){date_retour_prevue=d;}
        void setDate_retour_effectif(QDate d){date_retour_effectif=d;}
        void setStatut(bool s){statut=s;}
        static int nbre;

    private:
        Adherent adherent;
        Exemplaire exemplaire;
        QDate date_emprunt;
        QDate date_retour_prevue;
        QDate date_retour_effectif;
        bool statut;

};
#endif // EMPRUNT_H
