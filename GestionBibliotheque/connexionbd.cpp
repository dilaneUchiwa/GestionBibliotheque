#include "connexionbd.h"
#include<QtDebug>

ConnexionBd::ConnexionBd()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bibliotheque.db");
    db.setUserName("root");
    db.setPassword("");
    db.open();
}
ConnexionBd::~ConnexionBd()
{
    db.close();
}
Livre* ConnexionBd::listeLivre()
{
    Livre* tab;
    Auteur* a;
    int i=0;
    QSqlQuery query,query2;
    query.exec("select count(*) from livre");
    while (query.next()) {
      tab=new Livre[query.value(0).toInt()+10];
      Livre::nbre=query.value(0).toInt();
    }
    query.exec("select * from livre");
    while (query.next()) {
      query2.prepare("select * from auteur where id_auteur=:id");
      query2.bindValue(":id",query.value(1).toInt());
      query2.exec();
      while(query2.next()){
            a=new Auteur(query2.value(0).toInt(),query2.value(1).toString(),query2.value(2).toString());
      }
      tab[i]=*new Livre(query.value(0).toInt(),query.value(2).toString(),*a,query.value(4).toInt());
      i++;
    }

    return tab;
}
bool ConnexionBd::insererLivre(Livre l)
{
    QSqlQuery query;
    query.prepare("insert into livre(titre,annee,id_auteur) values (:titre,:annee,:auteur )");
    query.bindValue(":titre",l.getTitre());
    query.bindValue(":annee",l.getAnnee());
    query.bindValue(":auteur",l.getAuteur().getId_auteur());
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::supprimerLivre(Livre l)
{
    QSqlQuery query;
    query.prepare("delete from livre where id_livre=:id");
    query.bindValue(":id",l.getId_livre());
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::updateLivre(Livre l)
{
    QSqlQuery query;
    query.prepare("update livre set titre=:titre ,annee=:annee,id_auteur=:auteur where id_livre=:id  ");
    query.bindValue(":id",l.getId_livre());
    query.bindValue(":titre",l.getTitre());
    query.bindValue(":annee",l.getAnnee());
    query.bindValue(":auteur",l.getAuteur().getId_auteur());
    if(query.exec())return true;
    return false;
}
Livre* ConnexionBd::getLivre(int id)
{
    Auteur *a;
    Livre *l;
    QSqlQuery query,query2;
    query.prepare("select * from livre where id_livre=:id");
    query.bindValue(":id",id);
    query.exec();
    while (query.next()) {
      query2.prepare("select * from auteur where id_auteur=:id");
      query2.bindValue(":id",query.value(1).toInt());
      query2.exec();
      while(query2.next()){
            a=new Auteur(query2.value(0).toInt(),query2.value(1).toString(),query2.value(2).toString());
      }
      l=new Livre(query.value(0).toInt(),query.value(2).toString(),*a,query.value(4).toInt());
    }
    return l;
}
Livre* ConnexionBd::recherherLivre(QString cle)
{
    Livre* tab;
    Auteur* a;
    int i=0;
    QSqlQuery query,query2;
    query.exec("select count(*) from livre");
    while (query.next()) {
      tab=new Livre[query.value(0).toInt()];
      Livre::nbre=query.value(0).toInt();
    }
    query.prepare("select * from livre where id_livre Like %:id% or titre Like %:titre% or annee Like %:annee%");
    query.bindValue(":id",cle.toInt());
    query.bindValue(":titre",cle);
    query.bindValue(":annee",cle.toInt());
    query.exec();

    while (query.next()) {
      query2.prepare("select * from auteur where id_auteur=:id");
      query2.bindValue(":id",query.value(1).toInt());
      query2.exec();
      while(query2.next()){
            a=new Auteur(query2.value(0).toInt(),query2.value(1).toString(),query2.value(2).toString());
      }
      tab[i]=*new Livre(query.value(0).toInt(),query.value(2).toString(),*a,query.value(4).toInt());
      i++;
    }

    return tab;
}




//                  *  AUTEUR  *


Auteur* ConnexionBd::listeAuteur()
{
    Auteur* tab;
    int i=0;
    QSqlQuery query;
    query.exec("select count(*) from Auteur");
    while (query.next()) {
      tab=new Auteur[query.value(0).toInt()+10];
      Auteur::nbre=query.value(0).toInt();
    }
    query.exec("select * from Auteur");
    while (query.next()) {
      tab[i]=*new Auteur(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString());
      i++;
    }

    return tab;
}
bool ConnexionBd::insererAuteur(Auteur a)
{
    QSqlQuery query;
    query.prepare("insert into auteur(nom,prenom) values (:nom,:prenom)");
    query.bindValue(":nom",a.getNom());
    query.bindValue(":prenom",a.getPrenom());
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::supprimerAuteur(Auteur a)
{
    QSqlQuery query;
    query.prepare("delete from auteur where id_auteur=:id");
    query.bindValue(":id",a.getId_auteur());
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::updateAuteur(Auteur a)
{
    QSqlQuery query;
    query.prepare("update auteur set nom=:nom ,prenom=:prenom where id_auteur=:id  ");
    query.bindValue(":id",a.getId_auteur());
    query.bindValue(":nom",a.getNom());
    query.bindValue(":prenom",a.getPrenom());
    if(query.exec())return true;
    return false;
}
Auteur* ConnexionBd::getAuteur(int id)
{
    Auteur *a;
    QSqlQuery query;
    query.prepare("select * from auteur where id_auteur=:id");
    query.bindValue(":id",id);
    query.exec();
    while (query.next()) {
            a=new Auteur(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString());
    }
    return a;
}

//                  *  ADHERENT  *


Adherent* ConnexionBd::listeAdherent()
{
    Adherent* tab;
    int i=0;
    QSqlQuery query;
    query.exec("select count(*) from adherent");
    while (query.next()) {
      tab=new Adherent[query.value(0).toInt()+10];
      Adherent::nbre=query.value(0).toInt();
    }
    query.exec("select * from adherent");
    while (query.next()) {
      tab[i]=*new Adherent(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(4).Char,query.value(3).toInt(),query.value(5).toString());
      i++;
    }

    return tab;
}
bool ConnexionBd::insererAdherent(Adherent a)
{
    QSqlQuery query;
    query.prepare("insert into adherent(nom,prenom,sexe,tel,adresse) values (:nom,:prenom,:sexe,:tel,:adresse)");
    query.bindValue(":nom",a.getNom());
    query.bindValue(":prenom",a.getPrenom());
    query.bindValue(":sexe",a.getSexe());
    query.bindValue(":tel",a.getTel());
    query.bindValue(":adresse",a.getAdresse());
    query.exec();
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::supprimerAdherent(Adherent a)
{
    QSqlQuery query;
    query.prepare("delete from adherent where id_adherent=:id");
    query.bindValue(":id",a.getId_adherent());
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::updateAdherent(Adherent a)
{
    QSqlQuery query;
    query.prepare("update adherent set nom=:nom ,prenom=:prenom , sexe=:sexe , tel=:tel , adresse=:adresse where id_adherent=:id  ");
    query.bindValue(":id",a.getId_adherent());
    query.bindValue(":nom",a.getNom());
    query.bindValue(":prenom",a.getPrenom());
    query.bindValue(":sexe",a.getSexe());
    query.bindValue(":tel",a.getTel());
    query.bindValue(":adresse",a.getAdresse());
    if(query.exec())return true;
    return false;
}
Adherent* ConnexionBd::getAdherent(int id)
{
    Adherent *a;
    QSqlQuery query;
    query.prepare("select * from adherent where id_adherent=:id");
    query.bindValue(":id",id);
    query.exec();
    while (query.next()) {
            a=new Adherent(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString(),query.value(4).Char,query.value(3).toInt(),query.value(5).toString());
    }
    return a;
}


//                  *  EXEMPLAIRE  *

Exemplaire* ConnexionBd::listeExemplaire()
{
    Exemplaire* tab;
    Livre* a;
    int i=0;
    QSqlQuery query,query2;
    query.exec("select count(*) from exemplaire");
    while (query.next()) {
      tab=new Exemplaire[query.value(0).toInt()+10];
      Exemplaire::nbre=query.value(0).toInt();
    }
    query.exec("select * from exemplaire");
    while (query.next()) {
      query2.prepare("select * from livre where id_livre=:id");
      query2.bindValue(":id",query.value(1).toInt());
      query2.exec();
      while(query2.next()){
            a=new Livre(query2.value(0).toInt(),query2.value(2).toString(),*getAuteur(query2.value(1).toInt()),query2.value(4).toInt());
      }
      tab[i]=*new Exemplaire(query.value(0).toInt(),*a,query.value(3).toString());
      i++;
    }

    return tab;
}
bool ConnexionBd::insererExemplaire(Exemplaire l)
{
    QSqlQuery query;
    query.prepare("insert into exemplaire(id_livre,etat) values (:livre,:etat )");
    query.bindValue(":livre",l.getLivre().getId_livre());
    query.bindValue(":etat",l.getEtat());
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::supprimerExemplaire(Exemplaire l)
{
    QSqlQuery query;
    query.prepare("delete from exemplaire where id_exemplaire=:id");
    query.bindValue(":id",l.getId_exemplaire());
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::updateExemplaire(Exemplaire l)
{
    QSqlQuery query;
    query.prepare("update exemplaire set id_livre=:livre ,etat=:etat where id_exemplaire=:id  ");
    query.bindValue(":id",l.getId_exemplaire());
    query.bindValue(":livre",l.getLivre().getId_livre());
    query.bindValue(":etat",l.getEtat());
    if(query.exec())return true;
    return false;
}
Exemplaire* ConnexionBd::getExemplaire(int id)
{
    Exemplaire* tab;
    Livre* a;
    int i=0;
    QSqlQuery query,query2;
    query.prepare("select * from exemplaire where id_exemplaire=:id");
    query.bindValue(":id",id);
    query.exec();
    while (query.next()) {
      query2.prepare("select * from livre where id_livre=:id");
      query2.bindValue(":id",query.value(1).toInt());
      query2.exec();
      while(query2.next()){
            a=new Livre(query2.value(0).toInt(),query2.value(2).toString(),*getAuteur(query2.value(1).toInt()),query2.value(4).toInt());
      }
      tab=new Exemplaire(query.value(0).toInt(),*a,query.value(3).toString());
      i++;
    }

    return tab;
}

//                  *  Emprunt *

Emprunt* ConnexionBd::listeEmprunt()
{
    Emprunt* tab;
    Exemplaire* e;
    Adherent *a;
    int i=0;
    QSqlQuery query;
    query.exec("select count(*) from emprunter");
    while (query.next()) {
      tab=new Emprunt[query.value(0).toInt()+10];
      Emprunt::nbre=query.value(0).toInt();
    }
    query.exec("select * from emprunter");
    while (query.next()) {
      e=ConnexionBd::getExemplaire(query.value(0).toInt());
      a=ConnexionBd::getAdherent(query.value(1).toInt());
      tab[i]=*new Emprunt(*a,*e,query.value(2).toDate(),query.value(3).toDate(),query.value(5).toDate(),query.value(4).toBool());
      i++;
    }

    return tab;
}
bool ConnexionBd::insererEmprunt(Emprunt l)
{
    QSqlQuery query;
    query.prepare("insert into emprunter(id_adherent,id_exemplaire,date_emprunt,date_retour_prevu,date_retour_effectif,statut) values (:ida,:ide,:datee,:daterp,:datere,:statut )");
    query.bindValue(":ida",l.getAdherent().getId_adherent());
    query.bindValue(":ide",l.getExemplaire().getId_exemplaire());
    query.bindValue(":datee",l.getDate_emprunt());
    query.bindValue(":daterp",l.getDate_retour_prevu());
    query.bindValue(":datere",l.getDate_retour_effectif());
    query.bindValue(":status",l.getStatut());
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::supprimerEmprunt(Emprunt l)
{
    QSqlQuery query;
    query.prepare("delete from emprunter where id_exemplaire=:id1 and id_adherent=id2");
    query.bindValue(":id1",l.getExemplaire().getId_exemplaire());
    query.bindValue(":id2",l.getAdherent().getId_adherent());
    if(query.exec())return true;
    return false;
}
bool ConnexionBd::rendreEmprunt(Emprunt l)
{
    QSqlQuery query;
    query.prepare("update emprunter set statut=:statut where id_exemplaire=:id1 and id_adherent=id2");
    query.bindValue(":id1",l.getExemplaire().getId_exemplaire());
    query.bindValue(":id2",l.getAdherent().getId_adherent());
    query.bindValue(":statut",1);
    if(query.exec())return true;
    return false;
}
Emprunt* ConnexionBd::getEmprunt(int id_e,int id_a)
{
    Emprunt* tab;
    Exemplaire* e;
    Adherent *a;
    QSqlQuery query,query2;
    query.exec("select * from emprunter where id_exemplaire=:id1 and id_adherent=id2");
    query.bindValue(":id1",id_e);
    query.bindValue(":id2",id_a);
    while (query.next()) {
      query2.prepare("select * from exemplaire where id_exemplaire=:id");
      query2.bindValue(":id",query.value(0).toInt());
      query2.exec();
      while(query2.next()){
            e=ConnexionBd::getExemplaire(query2.value(0).toInt());
      }
      query2.prepare("select * from adherent where id_adherent=:id");
      query2.bindValue(":id",query.value(1).toInt());
      query2.exec();
      while(query2.next()){
            a=ConnexionBd::getAdherent(query2.value(0).toInt());
      }

      tab=new Emprunt(*a,*e,query.value(2).toDate(),query.value(3).toDate(),query.value(5).toDate(),query.value(4).toBool());
    }

    return tab;

}
