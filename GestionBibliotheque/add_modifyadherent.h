#ifndef ADD_MODIFYADHERENT_H
#define ADD_MODIFYADHERENT_H
#include "connexionbd.h"
#include "adherent.h"
#include "adherentwindow.h"
#include <QDialog>
#include<QDate>
#include<QMessageBox>


namespace Ui {
class Add_modifyAdherent;
}

class Add_modifyAdherent : public QDialog
{
    Q_OBJECT

public:
    explicit Add_modifyAdherent(QWidget *parent = nullptr,Adherent l=*new Adherent(),bool modify=false);
    ~Add_modifyAdherent();
    bool modify;
    int *index_id;

private slots:
    void on_annuler_clicked();

    void on_valider_clicked();

private:
    Ui::Add_modifyAdherent *ui;
};
#endif // ADD_MODIFYADHERENT_H
