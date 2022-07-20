#ifndef ADD_MODIFYAUTEUR_H
#define ADD_MODIFYAUTEUR_H
#include "auteur.h"
#include "connexionbd.h"
#include "auteurwindow.h"
#include <QDialog>
#include<QDate>
#include<QMessageBox>


namespace Ui {
class Add_modifyAuteur;
}

class Add_modifyAuteur : public QDialog
{
    Q_OBJECT

public:
    explicit Add_modifyAuteur(QWidget *parent = nullptr,Auteur l=*new Auteur(),bool modify=false);
    ~Add_modifyAuteur();
    bool modify;
    int *index_id;


private slots:
    void on_annuler_clicked();

    void on_valider_clicked();

private:
    Ui::Add_modifyAuteur *ui;
};

#endif // ADD_MODIFYAUTEUR_H
