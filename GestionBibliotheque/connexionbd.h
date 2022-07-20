#ifndef CONNEXIONBD_H
#define CONNEXIONBD_H
#include "livre.h"
#include "emprunt.h"

#include<QtSql/QSqlDatabase>
#include<QSqlQuery>

class ConnexionBd
{
public:
    ConnexionBd();
    ~ConnexionBd();
    static Livre* listeLivre();
    static bool insererLivre(Livre l);
    static bool supprimerLivre(Livre l);
    static bool updateLivre(Livre l);
    static Livre* getLivre(int id);
    static Livre* recherherLivre(QString cle);


    static Auteur* listeAuteur();
    static bool insererAuteur(Auteur l);
    static bool supprimerAuteur(Auteur l);
    static bool updateAuteur(Auteur l);
    static Auteur* getAuteur(int id);

    static Adherent* listeAdherent();
    static bool insererAdherent(Adherent l);
    static bool supprimerAdherent(Adherent l);
    static bool updateAdherent(Adherent l);
    static Adherent* getAdherent(int id);

    static Exemplaire* listeExemplaire();
    static bool insererExemplaire(Exemplaire l);
    static bool supprimerExemplaire(Exemplaire l);
    static bool updateExemplaire(Exemplaire l);
    static Exemplaire* getExemplaire(int id);

    static Emprunt* listeEmprunt();
    static bool insererEmprunt(Emprunt l);
    static bool supprimerEmprunt(Emprunt l);
    static bool rendreEmprunt(Emprunt l);
    static Emprunt* getEmprunt(int ide,int ida);

    QSqlDatabase db;
};

#endif // CONNEXIONBD_H
