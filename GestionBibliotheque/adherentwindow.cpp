#include "adherentwindow.h"
#include "ui_adherentwindow.h"

Adherent* AdherentWindow::tab=new Adherent[Adherent::nbre];
AdherentWindow::AdherentWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdherentWindow)
{
    ui->setupUi(this);
    tab=ConnexionBd::listeAdherent();
    affichageDesAdherents();
}

AdherentWindow::~AdherentWindow()
{
    delete [] tab;
    delete ui;
}
void AdherentWindow::affichageDesAdherents()
{

        ui->tableWidget->setRowCount(0);
        for (int i=0; i<Adherent::nbre; i++)
              insertAdherentRow(i, tab[i]);

}
void AdherentWindow::insertAdherentRow(int ligne, Adherent l)
{
    QTableWidget *table=ui->tableWidget;
    table->insertRow(ligne);

    QLabel* id = new QLabel(QString::number(l.getId_adherent()));
    id->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* nom = new QLabel(l.getNom());
    nom->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* prenom = new QLabel(l.getPrenom());
    prenom->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* sexe = new QLabel("M");
    sexe->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* tel = new QLabel(QString::number(l.getTel()));
    tel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* adresse = new QLabel(l.getAdresse());
    adresse->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        // affectation aux cellules de la ligne numero ligne
    table->setCellWidget(ligne,0,id);
    table->setCellWidget(ligne,1,nom);
    table->setCellWidget(ligne,2,prenom);
    table->setCellWidget(ligne,3,sexe);
    table->setCellWidget(ligne,4,tel);
    table->setCellWidget(ligne,4,adresse);

        //parametre de la table

    table->resizeColumnsToContents();
    table->horizontalHeader()->stretchLastSection();
    table->setSortingEnabled(true);
    table->sortByColumn(1);
    table->sortByColumn(2);
    table->sortByColumn(3);
    table->sortByColumn(4);


}
void AdherentWindow::deleteAdherentRow(int ligne){
    ui->tableWidget->removeRow(ligne);
}
void AdherentWindow::on_supprimerButton_clicked()
{
    int ligne = ui->tableWidget->currentRow();
    if (ligne != -1){
    QMessageBox::StandardButton confirm;
    confirm=QMessageBox::question(this,"confirmation","Etes vous sur de vouloire supprimer l'Adherent '"+tab[ligne].getNom()+"'? ",QMessageBox::Yes|QMessageBox::No);
    if(confirm==QMessageBox::No)return ;
    if(ConnexionBd::supprimerAdherent(tab[ligne]))
    {
        deleteAdherentRow(ligne);
    }
    else{
        QMessageBox::warning(this,"suppression","Impossible de supprimer l' Adherent '"+tab[ligne].getNom()+"'");
    }
    }
    else{
        QMessageBox::warning(this,"suppression","Vous devez d'abord selectionner un Adherent");
    }
}

void AdherentWindow::on_modifierButton_clicked()
{
    int ligne = ui->tableWidget->currentRow();
    if (ligne != -1){
        QDialog *m=new Add_modifyAdherent(this,tab[ligne],true);
        m->setWindowTitle("Adherent");
        m->show();
    }
    else{
        QMessageBox::warning(this,"suppression","Vous devez d'abord selectionnée un Adherent");
    }
}

void AdherentWindow::on_ajouterButton_clicked()
{
    QDialog *m=new Add_modifyAdherent(this,*new Adherent());
    m->setWindowTitle("Adherent");
    m->show();

}


void AdherentWindow::on_rafraichirButton_clicked()
{
    for(int i=Adherent::nbre; i >=0  ; i--)ui->tableWidget->removeRow(i);
    ui->tableWidget->setRowCount(0);
    for (int i=0; i<Adherent::nbre; i++)
          insertAdherentRow(i, tab[i]);
}

