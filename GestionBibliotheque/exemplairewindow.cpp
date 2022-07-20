#include "exemplairewindow.h"
#include "ui_exemplairewindow.h"

Exemplaire* ExemplaireWindow::tab=new Exemplaire[Exemplaire::nbre];
ExemplaireWindow::ExemplaireWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExemplaireWindow)
{
    ui->setupUi(this);
    tab=ConnexionBd::listeExemplaire();
    affichageDesExemplaires();
}

ExemplaireWindow::~ExemplaireWindow()
{
    delete [] tab;
    delete ui;
}
void ExemplaireWindow::affichageDesExemplaires()
{

        ui->tableWidget->setRowCount(0);
        for (int i=0; i<Exemplaire::nbre; i++)
              insertExemplaireRow(i, tab[i]);

}
void ExemplaireWindow::insertExemplaireRow(int ligne, Exemplaire l)
{
    QTableWidget *table=ui->tableWidget;
    table->insertRow(ligne);

    QLabel* id = new QLabel(QString::number(l.getId_exemplaire()));
    id->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    id->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* titre = new QLabel(l.getLivre().getTitre());
    titre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* annee = new QLabel(QString::number(l.getLivre().getAnnee()));
    annee->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* etat = new QLabel(l.getEtat());
    etat->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* auteur_n = new QLabel(l.getLivre().getAuteur().getNom());
    auteur_n->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* auteur_p = new QLabel(l.getLivre().getAuteur().getPrenom());
    auteur_p->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        // affectation aux cellules de la ligne numero ligne
    table->setCellWidget(ligne,0,id);
    table->setCellWidget(ligne,1,titre);
    table->setCellWidget(ligne,2,annee);
    table->setCellWidget(ligne,3,etat);
    table->setCellWidget(ligne,4,auteur_n);
    table->setCellWidget(ligne,5,auteur_p);

        //parametre de la table

    table->resizeColumnsToContents();
    table->horizontalHeader()->stretchLastSection();
    table->setSortingEnabled(true);
    table->sortByColumn(1);
    table->sortByColumn(2);
    table->sortByColumn(3);
    table->sortByColumn(4);
    table->sortByColumn(5);

}
void ExemplaireWindow::deleteExemplaireRow(int ligne){
    ui->tableWidget->removeRow(ligne);
}
void ExemplaireWindow::on_supprimerButton_clicked()
{
    int ligne = ui->tableWidget->currentRow();
    if (ligne != -1){
    QMessageBox::StandardButton confirm;
    confirm=QMessageBox::question(this,"confirmation","Etes vous sur de vouloire supprimer cet Exemplaire de '"+tab[ligne].getLivre().getTitre()+"'? ",QMessageBox::Yes|QMessageBox::No);
    if(confirm==QMessageBox::No)return ;
    if(ConnexionBd::supprimerExemplaire(tab[ligne]))
    {
        deleteExemplaireRow(ligne);
    }
    else{
        QMessageBox::warning(this,"suppression","Impossible de supprimer cet Exemplaire '"+tab[ligne].getLivre().getTitre()+"'");
    }
    }
    else{
        QMessageBox::warning(this,"suppression","Vous devez d'abord selectionner un Exemplaire");
    }
}

void ExemplaireWindow::on_modifierButton_clicked()
{
    int ligne = ui->tableWidget->currentRow();
    if (ligne != -1){
        QDialog *m=new Add_modifyExemplaire(this,tab[ligne],true);
        m->setWindowTitle("Exemplaire");
        m->show();
    }
    else{
        QMessageBox::warning(this,"suppression","Vous devez d'abord selectionnée un Exemplaire");
    }
}

void ExemplaireWindow::on_ajouterButton_clicked()
{
    QDialog *m=new Add_modifyExemplaire(this,*new Exemplaire());
    m->setWindowTitle("Exemplaire");
    m->show();

}


void ExemplaireWindow::on_rafraichirButton_clicked()
{
    for(int i=Exemplaire::nbre; i >=0  ; i--)ui->tableWidget->removeRow(i);
    ui->tableWidget->setRowCount(0);
    for (int i=0; i<Exemplaire::nbre; i++)
          insertExemplaireRow(i, tab[i]);
}

