#ifndef EXEMPLAIREWINDOW_H
#define EXEMPLAIREWINDOW_H
#include "connexionbd.h"
#include "exemplaire.h"
#include "add_modifyexemplaire.h"
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
class ExemplaireWindow;
}

class ExemplaireWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ExemplaireWindow(QWidget *parent = nullptr);
    ~ExemplaireWindow();
    void insertExemplaireRow(int ligne,Exemplaire l);
    void deleteExemplaireRow(int ligne);
    void affichageDesExemplaires();
    static Exemplaire *tab;


private slots:
    void on_supprimerButton_clicked();

    void on_modifierButton_clicked();

    void on_ajouterButton_clicked();


    void on_rafraichirButton_clicked();

private:
    Ui::ExemplaireWindow *ui;
};
#endif // EXEMPLAIREWINDOW_H
