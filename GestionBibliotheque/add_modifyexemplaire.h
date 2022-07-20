#ifndef ADD_MODIFYEXEMPLAIRE_H
#define ADD_MODIFYEXEMPLAIRE_H
#include "connexionbd.h"
#include "exemplaire.h"
#include "exemplairewindow.h"
#include <QDialog>
#include<QDate>
#include<QMessageBox>


namespace Ui {
class Add_modifyExemplaire;
}

class Add_modifyExemplaire : public QDialog
{
    Q_OBJECT

public:
    explicit Add_modifyExemplaire(QWidget *parent = nullptr,Exemplaire l=*new Exemplaire(),bool modify=false);
    ~Add_modifyExemplaire();
    bool modify;
    int *index_id;

private slots:
    void on_annuler_clicked();

    void on_valider_clicked();

private:
    Ui::Add_modifyExemplaire *ui;
};
#endif // ADD_MODIFYEXEMPLAIRE_H
