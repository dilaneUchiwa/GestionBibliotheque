#ifndef ADD_EMPRUNT_H
#define ADD_EMPRUNT_H
#include "connexionbd.h"
#include "emprunt.h"
#include "empruntwindow.h"
#include <QDialog>
#include<QDate>
#include<QMessageBox>


namespace Ui {
class Add_Emprunt;
}

class Add_Emprunt : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Emprunt(QWidget *parent = nullptr,Emprunt l=*new Emprunt(),bool modify=false);
    ~Add_Emprunt();
    bool modify;
    int *index_id;

private slots:
    void on_annuler_clicked();

    void on_valider_clicked();

private:
    Ui::Add_Emprunt *ui;
};
#endif // ADD_EMPRUNT_H
