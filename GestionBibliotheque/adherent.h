#ifndef ADHERENT_H
#define ADHERENT_H
#include<QString>

class Adherent
{
public:
    Adherent();
    Adherent(int id,QString nom,QString prenom,char sexe,int tel,QString adresse);
    ~Adherent();

    int getId_adherent(){return id_adherent;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    char getSexe(){return sexe;}
    int getTel(){return tel;}
    QString getAdresse(){return adresse;}

    void setId_adherent(int id){id_adherent=id;}
    void setNom(QString t){nom=t;}
    void setPrenom(QString t){prenom=t;}
    void setSexe(char s){sexe=s;}
    void setTel(int phone){tel=phone;}
    void setAdresse(QString a){adresse=a;}
    void operator=(const Adherent &a);
    static int nbre;
private:
    int id_adherent;
    QString nom;
    QString prenom;
    char sexe;
    int tel;
    QString adresse;
};

#endif // ADHERENT_H
