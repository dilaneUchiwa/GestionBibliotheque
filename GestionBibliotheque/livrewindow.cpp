#include "livrewindow.h"
#include "ui_livrewindow.h"

Livre* LivreWindow::tab=new Livre[Livre::nbre];
LivreWindow::LivreWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LivreWindow)
{
    ui->setupUi(this);
    tab=ConnexionBd::listeLivre();
    affichageDesLivres();
}

LivreWindow::~LivreWindow()
{
    delete [] tab;
    delete ui;
}
void LivreWindow::affichageDesLivres()
{

        ui->tableWidget->setRowCount(0);
        for (int i=0; i<Livre::nbre; i++)
              insertLivreRow(i, tab[i]);

}
void LivreWindow::insertLivreRow(int ligne, Livre l)
{
    QTableWidget *table=ui->tableWidget;
    table->insertRow(ligne);

    QLabel* id = new QLabel(QString::number(l.getId_livre()));
    id->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    id->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* titre = new QLabel(l.getTitre());
    titre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* annee = new QLabel(QString::number(l.getAnnee()));
    annee->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* auteur_n = new QLabel(l.getAuteur().getNom());
    auteur_n->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel* auteur_p = new QLabel(l.getAuteur().getPrenom());
    auteur_p->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        // affectation aux cellules de la ligne numero ligne
    table->setCellWidget(ligne,0,id);
    table->setCellWidget(ligne,1,titre);
    table->setCellWidget(ligne,2,annee);
    table->setCellWidget(ligne,3,auteur_n);
    table->setCellWidget(ligne,4,auteur_p);

        //parametre de la table

    table->resizeColumnsToContents();
    table->horizontalHeader()->stretchLastSection();
    table->setSortingEnabled(true);
    table->sortByColumn(1);
    table->sortByColumn(2);
    table->sortByColumn(3);
    table->sortByColumn(4);


}
void LivreWindow::deleteLivreRow(int ligne){
    ui->tableWidget->removeRow(ligne);
}
void LivreWindow::on_supprimerButton_clicked()
{
    int ligne = ui->tableWidget->currentRow();
    if (ligne != -1){
    QMessageBox::StandardButton confirm;
    confirm=QMessageBox::question(this,"confirmation","Etes vous sur de vouloire supprimer le livre '"+tab[ligne].getTitre()+"'? ",QMessageBox::Yes|QMessageBox::No);
    if(confirm==QMessageBox::No)return ;
    if(ConnexionBd::supprimerLivre(tab[ligne]))
    {
        deleteLivreRow(ligne);
    }
    else{
        QMessageBox::warning(this,"suppression","Impossible de supprimer le livre '"+tab[ligne].getTitre()+"'");
    }
    }
    else{
        QMessageBox::warning(this,"suppression","Vous devez d'abord selectionner un livre");
    }
}

void LivreWindow::on_modifierButton_clicked()
{
    int ligne = ui->tableWidget->currentRow();
    if (ligne != -1){
        QDialog *m=new Add_modifyLivre(this,tab[ligne],true);
        m->setWindowTitle("Livre");
        m->show();
    }
    else{
        QMessageBox::warning(this,"suppression","Vous devez d'abord selectionnée un livre");
    }
}

void LivreWindow::on_ajouterButton_clicked()
{
    QDialog *m=new Add_modifyLivre(this,*new Livre());
    m->setWindowTitle("Livre");
    connect(m,SIGNAL(destroy()),this,SLOT(on_rafraichirButton_clicked()));
    m->show();

}


void LivreWindow::on_rafraichirButton_clicked()
{
    for(int i=Livre::nbre; i >=0  ; i--)ui->tableWidget->removeRow(i);
    ui->tableWidget->setRowCount(0);
    for (int i=0; i<Livre::nbre; i++)
          insertLivreRow(i, tab[i]);
}

void LivreWindow::on_cleEdit_textChanged(const QString &arg1)
{
//    tab=ConnexionBd::recherherLivre(ui->cleEdit->text());
//    on_rafraichirButton_clicked();
}

void LivreWindow::on_cleEdit_cursorPositionChanged(int arg1, int arg2)
{
//    tab=ConnexionBd::recherherLivre(ui->cleEdit->text());
//    on_rafraichirButton_clicked();
}
