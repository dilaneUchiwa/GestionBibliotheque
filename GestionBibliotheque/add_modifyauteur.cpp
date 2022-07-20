#include "add_modifyauteur.h"
#include "ui_add_modifyauteur.h"


Add_modifyAuteur::Add_modifyAuteur(QWidget *parent,Auteur a,bool modify) :
    QDialog(parent),
    ui(new Ui::Add_modifyAuteur)
{
    ui->setupUi(this);
    ui->idEdit->setText(QString::number(a.getId_auteur()));
    ui->nomEdit->setText(a.getNom());
    ui->prenomEdit->setText(a.getPrenom());
    this->modify=modify;
}

Add_modifyAuteur::~Add_modifyAuteur()
{
    delete ui;
}

void Add_modifyAuteur::on_annuler_clicked()
{
    this->close();
    delete this;
    
}

void Add_modifyAuteur::on_valider_clicked()
{
    int i;
    Auteur a=*new Auteur();
    QString nom=*new QString(ui->nomEdit->text());
    QString prenom=*new QString(ui->prenomEdit->text());
    int id=(new QString(ui->idEdit->text()))->toInt();


    for(i=0; i < Auteur::nbre ;i++){
        if(AuteurWindow::tab[i].getId_auteur()==id)break;
    }
    if(i<Auteur::nbre){
        AuteurWindow::tab[i].setNom(nom);
        AuteurWindow::tab[i].setPrenom(prenom);
    }else{
        AuteurWindow::tab[Auteur::nbre].setId_auteur(id);
        AuteurWindow::tab[Auteur::nbre].setNom(nom);
        AuteurWindow::tab[Auteur::nbre].setPrenom(prenom);
    }


    if(modify){
        a=*new Auteur(nom,prenom);
        if(ConnexionBd::updateAuteur(a)){
            QMessageBox::information(this,"Mise à jour","L'Auteur a"+ui->nomEdit->text()+"' a été mis à jour");
        }else{
            QMessageBox::warning(this,"Mise à jour","Impossible de mettre l'auteur "+ui->nomEdit->text()+"' à jour");
        }

    }
    else{
        a=*new Auteur(id,nom,prenom);
        if(ConnexionBd::insererAuteur(a)){
            QMessageBox::information(this,"insertion","Le Auteur a"+ui->nomEdit->text()+"' a été enregistré");
        }
        else{
            QMessageBox::warning(this,"insertion","Impossible de creer l'auteur a"+ui->nomEdit->text()+"'");
        }
    }
    delete this;
}
