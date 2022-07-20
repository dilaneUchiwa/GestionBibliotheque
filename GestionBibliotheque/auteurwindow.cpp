#include "auteurwindow.h"
#include "ui_auteurwindow.h"

Auteur* AuteurWindow::tab=new Auteur[Auteur::nbre];
AuteurWindow::AuteurWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuteurWindow)
{
    ui->setupUi(this);
    tab=ConnexionBd::listeAuteur();
    affichageDesAuteurs();
}

AuteurWindow::~AuteurWindow()
{
    delete [] tab;
    delete ui;
}
void AuteurWindow::affichageDesAuteurs()
{

        ui->tableWidget->setRowCount(0);
        for (int i=0; i<Auteur::nbre; i++)
              insertAuteurRow(i, tab[i]);

}
void AuteurWindow::insertAuteurRow(int ligne, Auteur a)
{
    QTableWidget *table=ui->tableWidget;
    table->insertRow(ligne);
    QLabel* id = new QLabel(QString::number(a.getId_auteur()));
    id->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* nom = new QLabel(a.getNom());
    nom->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* prenom = new QLabel(a.getPrenom());
    prenom->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


        // affectation aux cellules de la ligne numero ligne
    table->setCellWidget(ligne,0,id);
    table->setCellWidget(ligne,1,nom);
    table->setCellWidget(ligne,2,prenom);

        //parametre de la table

    table->resizeColumnsToContents();
    table->horizontalHeader()->stretchLastSection();
    table->setSortingEnabled(true);
    table->sortByColumn(1);
    table->sortByColumn(2);

}
void AuteurWindow::deleteAuteurRow(int ligne){
    ui->tableWidget->removeRow(ligne);
}
void AuteurWindow::on_supprimerButton_clicked()
{
    int ligne = ui->tableWidget->currentRow();
    if (ligne != -1){
    QMessageBox::StandardButton confirm;
    confirm=QMessageBox::question(this,"confirmation","Etes vous sur de vouloire supprimer l'auteur '"+tab[ligne].getNom()+"'? ",QMessageBox::Yes|QMessageBox::No);
    if(confirm==QMessageBox::No)return ;
    if(ConnexionBd::supprimerAuteur(tab[ligne]))
    {
        deleteAuteurRow(ligne);
    }
    else{
        QMessageBox::warning(this,"suppression","Impossible de supprimer l'auteur '"+tab[ligne].getNom()+"'");
    }
    }
    else{
        QMessageBox::warning(this,"suppression","Vous devez d'abord selectionner un auteur");
    }
}

void AuteurWindow::on_modifierButton_clicked()
{
    int ligne = ui->tableWidget->currentRow();
    if (ligne != -1){
        QDialog *m=new Add_modifyAuteur(this,tab[ligne],true);
        m->setWindowTitle("Auteur");
        m->show();
    }
    else{
        QMessageBox::warning(this,"suppression","Vous devez d'abord selectionnée un auteur");
    }
}

void AuteurWindow::on_ajouterButton_clicked()
{
    QDialog *m=new Add_modifyAuteur(this,*new Auteur());
    m->setWindowTitle("Auteur");
    m->show();
}


void AuteurWindow::on_rafraichirButton_clicked()
{
    for(int i=Auteur::nbre; i >=0  ; i--)
        ui->tableWidget->removeRow(i);
    ui->tableWidget->setRowCount(0);
    for (int i=0; i<Auteur::nbre; i++)
        insertAuteurRow(i, tab[i]);
}

void AuteurWindow::on_cleEdit_textChanged(const QString &arg1)
{
    qDebug()<<"yo";
}
