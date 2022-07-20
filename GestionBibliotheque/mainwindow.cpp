#include "mainwindow.h"
#include "livrewindow.h"
#include "auteurwindow.h"
#include "adherentwindow.h"
#include "exemplairewindow.h"
#include "aproposwidget.h"
#include "aidewidget.h"
#include "empruntwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Gestion bibliothèque");
    this->setWindowIcon(QPixmap("livre.png"));


    //statusBar()->addWidget(ui->hacker);
    ui->diablo->setText("diablo was here !!!");
    statusBar()->addWidget(ui->diablo);

    QMenu *menuFichier=menuBar()->addMenu("&Fichier");
    QMenu *menuStructure=menuBar()->addMenu("&Structure");
    QMenu *menuGestion=menuBar()->addMenu("&Gestion");
    QMenu *menuAutre=menuBar()->addMenu("&?");


    // Creation des actions pour les menus

    QAction *actionQuitter=new QAction("&Quitter",this);
    menuFichier->addAction(actionQuitter);
    actionQuitter->setShortcut(QKeySequence("ctrl+q"));

    QAction *actionLivre=new QAction("&Livre",this);
    menuStructure->addAction(actionLivre);
    QAction *actionExemplaire=new QAction("&Exemplaire",this);
    menuStructure->addAction(actionExemplaire);
    actionLivre->setIcon(QIcon("icon.png"));
    QAction *actionAdherent=new QAction("&Adhérent",this);
    menuStructure->addAction(actionAdherent);
    QAction *actionAuteur=new QAction("&Auteur",this);
    menuStructure->addAction(actionAuteur);

    QAction *actionEmprunt=new QAction("&Emprunt",this);
    menuGestion->addAction(actionEmprunt);
    //QAction *actionReport=new QAction("&Journal",this);
    //menuGestion->addAction(actionReport);

    QAction *actionAide=new QAction("&Aide",this);
    menuAutre->addAction(actionAide);
    QAction *actionApropos=new QAction("&A propos",this);
    menuAutre->addAction(actionApropos);


    //creation de la barre d'outils

    QToolBar *toolBarFichier = addToolBar("Fichier");
    toolBarFichier->addAction(actionQuitter);
//    toolBarFichier->addAction(actionEmprunt);
//    toolBarFichier->addAction(actionAdherent);
//    toolBarFichier->addAction(actionLivre);
//    toolBarFichier->addAction(actionAuteur);
//    toolBarFichier->addAction(actionExemplaire);

    // Connexion à base de donnée

    ConnexionBd *conn=new ConnexionBd();

    // Connexion des actions avec les signaux et slots

    connect(actionQuitter,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(actionLivre,SIGNAL(triggered()),this,SLOT(displayLivre()));
    connect(actionExemplaire,SIGNAL(triggered()),this,SLOT(displayExemplaire()));
    connect(actionAuteur,SIGNAL(triggered()),this,SLOT(displayAuteur()));
    connect(actionAdherent,SIGNAL(triggered()),this,SLOT(displayAdherent()));
    connect(actionEmprunt,SIGNAL(triggered()),this,SLOT(displayEmprunt()));
    connect(actionApropos,SIGNAL(triggered()),this,SLOT(displayApropos()));
    connect(actionAide,SIGNAL(triggered()),this,SLOT(displayAide()));


    displayEmprunt();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::displayLivre(){
    setCentralWidget(new LivreWindow());
}
void MainWindow::displayAuteur(){
    setCentralWidget(new AuteurWindow());
}
void MainWindow::displayAdherent()
{
    setCentralWidget(new AdherentWindow());
}
void MainWindow::displayEmprunt()
{
    setCentralWidget(new EmpruntWindow());
}
void MainWindow::displayExemplaire()
{
    setCentralWidget(new ExemplaireWindow());
}
void MainWindow::displayApropos(){
    setCentralWidget(new AproposWidget());
}
void MainWindow::displayAide(){
    setCentralWidget(new AideWidget());
}
