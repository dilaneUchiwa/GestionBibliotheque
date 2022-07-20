#include "add_modifyexemplaire.h"
#include "ui_add_modifyexemplaire.h"



Add_modifyExemplaire::Add_modifyExemplaire(QWidget *parent,Exemplaire l,bool modify) :
    QDialog(parent),
    ui(new Ui::Add_modifyExemplaire)
{
    ui->setupUi(this);
    ui->idEdit->setText(QString::number(l.getId_exemplaire()));

    Livre *tab=ConnexionBd::listeLivre();
    index_id=new int[Livre::nbre];
    for (int i=0;i<Livre::nbre ;i++ ) {
        index_id[i]=tab[i].getId_livre();
        ui->livre->addItem(tab[i].getTitre()+"-------"+tab[i].getAuteur().getNom());
    }
    ui->livre->setCurrentText(l.getLivre().getTitre()+"-------"+l.getLivre().getAuteur().getNom());
    this->modify=modify;
}

Add_modifyExemplaire::~Add_modifyExemplaire()
{
    delete ui;
}

void Add_modifyExemplaire::on_annuler_clicked()
{
    this->close();
    delete this;
}

void Add_modifyExemplaire::on_valider_clicked()
{
    Exemplaire *e;
    int i;
    Livre l=*new Livre();

    int id=(new QString(ui->idEdit->text()))->toInt();
    l=*ConnexionBd::getLivre(index_id[ui->livre->currentIndex()]);
    QString etat=ui->etat->currentText();
    for(i=0; i < Exemplaire::nbre ;i++){
        if(ExemplaireWindow::tab[i].getId_exemplaire()==id)break;
    }
    if(i<Exemplaire::nbre){
        ExemplaireWindow::tab[i].setLivre(*ConnexionBd::getLivre(l.getId_livre()));
        ExemplaireWindow::tab[i].setEtat(etat);
    }else{
        ExemplaireWindow::tab[Exemplaire::nbre].setId_exemplaire(id);
        ExemplaireWindow::tab[Exemplaire::nbre].setLivre(l);
        ExemplaireWindow::tab[Exemplaire::nbre].setEtat(etat);
    }

    if(modify){
        e=new Exemplaire(id,l,etat);
        if(ConnexionBd::updateExemplaire(*e)){
            QMessageBox::information(this,"Mise à jour","cet exemplaire a été mis à jour");
        }else{
            QMessageBox::warning(this,"Mise à jour","Impossible de mettre cet exemplaire à jour'");
        }

    }
    else{
        e=new Exemplaire(l,etat);
        if(ConnexionBd::insererExemplaire(*e)){
            QMessageBox::information(this,"insertion","cet exemplaire a été enregistré");
        }
        else{
            QMessageBox::warning(this,"insertion","Impossible de creer cet exemplaire");
        }
    }
    delete this;
}
