#include "empruntwindow.h"
#include "ui_empruntwindow.h"

Emprunt* EmpruntWindow::tab=new Emprunt[Emprunt::nbre];
EmpruntWindow::EmpruntWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmpruntWindow)
{
    ui->setupUi(this);
    tab=ConnexionBd::listeEmprunt();
    affichageDesEmprunts();
}

EmpruntWindow::~EmpruntWindow()
{
    delete [] tab;
    delete ui;
}
void EmpruntWindow::affichageDesEmprunts()
{

        ui->tableWidget->setRowCount(0);
        for (int i=0; i<Emprunt::nbre; i++)
              insertEmpruntRow(i, tab[i]);

}
void EmpruntWindow::insertEmpruntRow(int ligne, Emprunt l)
{
    QTableWidget *table=ui->tableWidget;
    table->insertRow(ligne);

    QLabel* exemplaire= new QLabel(l.getExemplaire().getLivre().getTitre());
    exemplaire->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* adherent= new QLabel(l.getAdherent().getNom()+" "+l.getAdherent().getPrenom());
    adherent->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* datee = new QLabel(l.getDate_emprunt().toString());
    datee->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* daterp = new QLabel(l.getDate_retour_prevu().toString());
    daterp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* datere = new QLabel(l.getDate_retour_effectif().toString());
    datere->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* statut = new QLabel();
    if(l.getStatut()==1)statut->setText("Rendu");
    else statut->setText("Non Rendu");
    statut->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


        // affectation aux cellules de la ligne numero ligne
    table->setCellWidget(ligne,0,exemplaire);
    table->setCellWidget(ligne,1,adherent);
    table->setCellWidget(ligne,2,statut);
    table->setCellWidget(ligne,3,datee);
    table->setCellWidget(ligne,4,daterp);
    table->setCellWidget(ligne,5,datere);

        //parametre de la table

    table->resizeColumnsToContents();
    table->horizontalHeader()->stretchLastSection();
    table->setSortingEnabled(true);
    table->sortByColumn(1);
    table->sortByColumn(2);
    table->sortByColumn(3);
    table->sortByColumn(4);


}
void EmpruntWindow::deleteEmpruntRow(int ligne){
    ui->tableWidget->removeRow(ligne);
}
void EmpruntWindow::on_modifierButton_clicked()
{
    int ligne = ui->tableWidget->currentRow();
    if (ligne != -1){
    QMessageBox::StandardButton confirm;
    confirm=QMessageBox::question(this,"confirmation","Etes vous sur de vouloire rendre cet emprunt ?",QMessageBox::Yes|QMessageBox::No);
    if(confirm==QMessageBox::No)return ;
    if(ConnexionBd::rendreEmprunt(tab[ligne]))
    {
        deleteEmpruntRow(ligne);
    }
    else{
        QMessageBox::warning(this,"suppression","Impossible de rendre cet emprunt");
    }
    }
    else{
        QMessageBox::warning(this,"suppression","Vous devez d'abord selectionner un enregistrement");
    }
}

void EmpruntWindow::on_ajouterButton_clicked()
{
    QDialog *m=new Add_Emprunt(this,*new Emprunt());
    m->setWindowTitle("Emprunt");
    m->show();

}


void EmpruntWindow::on_rafraichirButton_clicked()
{
    for(int i=Emprunt::nbre; i >=0  ; i--)ui->tableWidget->removeRow(i);
    ui->tableWidget->setRowCount(0);
    for (int i=0; i<Emprunt::nbre; i++)
          insertEmpruntRow(i, tab[i]);
}
