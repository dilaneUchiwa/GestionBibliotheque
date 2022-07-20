#ifndef AUTEUR_H
#define AUTEUR_H
#include<QString>

class Auteur
{
public:
    Auteur();
    Auteur(int id,QString nom,QString prenom);
    Auteur(QString nom,QString prenom);
    ~Auteur();
    int getId_auteur(){return id_auteur;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    void setId_auteur(int id){id_auteur=id;}
    void setNom(QString t){nom=t;}
    void setPrenom(QString t){prenom=t;}
    void operator=(const Auteur &a);
    static int nbre;
private:
    int id_auteur;
    QString nom;
    QString prenom;
};

#endif // AUTEUR_H
