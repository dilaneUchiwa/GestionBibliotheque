#ifndef ADHERENTWINDOW_H
#define ADHERENTWINDOW_H
#include "connexionbd.h"
#include "add_modifyadherent.h"
#include "adherent.h"
#include <QWidget>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFileDialog>
#include<QDialog>
#include<QtDebug>
#include<QProcess>
#include <QSqlError>
#include<QToolButton>
#include<QLabel>
#include<QTableWidgetItem>


namespace Ui {
class AdherentWindow;
}

class AdherentWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdherentWindow(QWidget *parent = nullptr);
    ~AdherentWindow();
    void insertAdherentRow(int ligne,Adherent l);
    void deleteAdherentRow(int ligne);
    void affichageDesAdherents();
    static Adherent *tab;


private slots:
    void on_supprimerButton_clicked();

    void on_modifierButton_clicked();

    void on_ajouterButton_clicked();


    void on_rafraichirButton_clicked();


private:
    Ui::AdherentWindow *ui;
};
#endif // ADHERENTWINDOW_H
