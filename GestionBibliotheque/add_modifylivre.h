#ifndef ADD_MODIFYLIVRE_H
#define ADD_MODIFYLIVRE_H
#include "connexionbd.h"
#include "livre.h"
#include "livrewindow.h"
#include <QDialog>
#include<QDate>
#include<QMessageBox>


namespace Ui {
class Add_modifyLivre;
}

class Add_modifyLivre : public QDialog
{
    Q_OBJECT

public:
    explicit Add_modifyLivre(QWidget *parent = nullptr,Livre l=*new Livre(),bool modify=false);
    ~Add_modifyLivre();
    QWidget *parent;
    bool modify;
    int *index_id;

private slots:
    void on_annuler_clicked();

    void on_valider_clicked();

private:
    Ui::Add_modifyLivre *ui;
};

#endif // ADD_MODIFYLIVRE_H
