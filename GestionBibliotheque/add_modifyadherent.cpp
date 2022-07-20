#include "add_modifyadherent.h"
#include "ui_add_modifyadherent.h"

Add_modifyAdherent::Add_modifyAdherent(QWidget *parent,Adherent l,bool modify) :
    QDialog(parent),
    ui(new Ui::Add_modifyAdherent)
{
    ui->setupUi(this);
    ui->idEdit->setText(QString::number(l.getId_adherent()));
    ui->nomEdit->setText(l.getNom());
    ui->PrenomEdit->setText(l.getPrenom());

    //ui->radioButton_h

    ui->TelEdit->setText(QString::number(l.getTel()));
    ui->AddressseEdit->setText(l.getAdresse());

    this->modify=modify;
}

Add_modifyAdherent::~Add_modifyAdherent()
{
    delete ui;
}

void Add_modifyAdherent::on_annuler_clicked()
{
    this->close();
    delete this;
}

void Add_modifyAdherent::on_valider_clicked()
{
    Adherent *l;
    int i;
    QString nom=*new QString(ui->nomEdit->text());
    QString prenom=*new QString(ui->PrenomEdit->text());
    char sexe='M';
    int tel=ui->TelEdit->text().toInt();
    QString adresse=*new QString(ui->AddressseEdit->text());
    int id=(new QString(ui->idEdit->text()))->toInt();
    for(i=0; i < Adherent::nbre ;i++){
        if(AdherentWindow::tab[i].getId_adherent()==id)break;
    }
    if(i<Adherent::nbre){
        AdherentWindow::tab[i].setNom(nom);
        AdherentWindow::tab[i].setPrenom(prenom);
        AdherentWindow::tab[i].setSexe(sexe);
        AdherentWindow::tab[i].setTel(tel);
        AdherentWindow::tab[i].setAdresse(adresse);
    }else{
        AdherentWindow::tab[Adherent::nbre].setId_adherent(id);
        AdherentWindow::tab[Adherent::nbre].setNom(nom);
        AdherentWindow::tab[Adherent::nbre].setPrenom(prenom);
        AdherentWindow::tab[Adherent::nbre].setSexe(sexe);
        AdherentWindow::tab[Adherent::nbre].setTel(tel);
        AdherentWindow::tab[Adherent::nbre].setAdresse(adresse);
        Adherent::nbre++;
    }

    if(modify){
        l=new Adherent(id,nom,prenom,sexe,tel,adresse);
        if(ConnexionBd::updateAdherent(*l)){
            QMessageBox::information(this,"Mise à jour","L'adherent '"+ui->nomEdit->text()+"' a été mis à jour");
        }else{
            QMessageBox::warning(this,"Mise à jour","Impossible de mettre l'adherent '"+ui->PrenomEdit->text()+" à jour'");
        }

    }
    else{
        l=new Adherent(id,nom,prenom,sexe,tel,adresse);
        if(ConnexionBd::insererAdherent(*l)){
            QMessageBox::information(this,"insertion","L'adherent '"+ui->nomEdit->text()+"' a été enregistré");
        }
        else{
            QMessageBox::warning(this,"insertion","Impossible de creer l'adherent '"+ui->PrenomEdit->text()+"'");
        }
    }
    delete this;
}
