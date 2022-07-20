#include "add_emprunt.h"
#include "ui_add_emprunt.h"

Add_Emprunt::Add_Emprunt(QWidget *parent,Emprunt l,bool modify) :
    QDialog(parent),
    ui(new Ui::Add_Emprunt)
{
    ui->setupUi(this);

/*    ui->->setText(l.getTitre());
    ui->anneeEdit->setDate((*new QDate()).addYears(l.getAnnee()));

    Auteur *tab=ConnexionBd::listeAuteur();
    index_id=new int[Auteur::nbre];
    for (int i=0;i<Auteur::nbre ;i++ ) {
        index_id[i]=tab[i].getId_auteur();
        ui->auteurCombobox->addItem(tab[i].getNom()+"  "+tab[i].getPrenom());
    }
    ui->auteurCombobox->setCurrentText(l.getAuteur().getNom()+" "+l.getAuteur().getPrenom());
    this->modify=modify;
    */
}

Add_Emprunt::~Add_Emprunt()
{
    delete ui;
}

void Add_Emprunt::on_annuler_clicked()
{
    this->close();
    delete this;
}

void Add_Emprunt::on_valider_clicked()
{
//    Emprunt *l;
//    int i;
//    Auteur a=*new Auteur();
//    QString titre=*new QString(ui->titreEdit->text());
//    int annee=ui->anneeEdit->date().year();
//    int id=(new QString(ui->idEdit->text()))->toInt();
//    a.setId_auteur(index_id[ui->auteurCombobox->currentIndex()]);
//    EmpruntWindow::tab[Emprunt::nbre].setId_Emprunt(id);
//    EmpruntWindow::tab[Emprunt::nbre].setTitre(titre);
//    EmpruntWindow::tab[Emprunt::nbre].setAnnee(annee);
//    EmpruntWindow::tab[Emprunt::nbre].setAuteur(*ConnexionBd::getAuteur(a.getId_auteur()));
//    l=new Emprunt(ui->titreEdit->text(),a,ui->anneeEdit->date().year());
//    if(ConnexionBd::insererEmprunt(*l)){
//        QMessageBox::information(this,"insertion","Le Emprunt '"+ui->titreEdit->text()+"' a été enregistré");
//    }
//    else{
//        QMessageBox::warning(this,"insertion","Impossible de creer le Emprunt '"+ui->titreEdit->text()+"'");
//    }

//    delete this;
}
