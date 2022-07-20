#include "add_modifylivre.h"
#include "ui_add_modifylivre.h"


Add_modifyLivre::Add_modifyLivre(QWidget *parent,Livre l,bool modify) :
    QDialog(parent),
    ui(new Ui::Add_modifyLivre)
{
    ui->setupUi(this);
    ui->idEdit->setText(QString::number(l.getId_livre()));
    ui->titreEdit->setText(l.getTitre());
    ui->anneeEdit->setDate((*new QDate()).addYears(l.getAnnee()));

    Auteur *tab=ConnexionBd::listeAuteur();
    index_id=new int[Auteur::nbre];
    for (int i=0;i<Auteur::nbre ;i++ ) {
        index_id[i]=tab[i].getId_auteur();
        ui->auteurCombobox->addItem(tab[i].getNom()+"  "+tab[i].getPrenom());
    }
    ui->auteurCombobox->setCurrentText(l.getAuteur().getNom()+" "+l.getAuteur().getPrenom());
    this->modify=modify;
}

Add_modifyLivre::~Add_modifyLivre()
{
    delete ui;
}

void Add_modifyLivre::on_annuler_clicked()
{
    this->close();
    delete this;
}

void Add_modifyLivre::on_valider_clicked()
{
    Livre *l;
    int i;
    Auteur a=*new Auteur();
    QString titre=*new QString(ui->titreEdit->text());
    int annee=ui->anneeEdit->date().year();
    int id=(new QString(ui->idEdit->text()))->toInt();
    a.setId_auteur(index_id[ui->auteurCombobox->currentIndex()]);
    for(i=0; i < Livre::nbre ;i++){
        if(LivreWindow::tab[i].getId_livre()==id)break;
    }
    if(i<Livre::nbre){
        LivreWindow::tab[i].setTitre(titre);
        LivreWindow::tab[i].setAnnee(annee);
        LivreWindow::tab[i].setAuteur(*ConnexionBd::getAuteur(a.getId_auteur()));
    }else{
        LivreWindow::tab[Livre::nbre].setId_livre(id);
        LivreWindow::tab[Livre::nbre].setTitre(titre);
        LivreWindow::tab[Livre::nbre].setAnnee(annee);
        LivreWindow::tab[Livre::nbre].setAuteur(*ConnexionBd::getAuteur(a.getId_auteur()));
    }

    if(modify){
        l=new Livre(id,titre,a,annee);
        if(ConnexionBd::updateLivre(*l)){
            QMessageBox::information(this,"Mise à jour","Le livre '"+ui->titreEdit->text()+"' a été mis à jour");
        }else{
            QMessageBox::warning(this,"Mise à jour","Impossible de mettre le livre '"+ui->titreEdit->text()+" à jour'");
        }

    }
    else{
        l=new Livre(ui->titreEdit->text(),a,ui->anneeEdit->date().year());
        if(ConnexionBd::insererLivre(*l)){
            QMessageBox::information(this,"insertion","Le livre '"+ui->titreEdit->text()+"' a été enregistré");
        }
        else{
            QMessageBox::warning(this,"insertion","Impossible de creer le livre '"+ui->titreEdit->text()+"'");
        }
    }
    delete this;
}
