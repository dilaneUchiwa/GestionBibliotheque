#ifndef AUTEURWINDOW_H
#define AUTEURWINDOW_H
#include "connexionbd.h"
#include "add_modifyauteur.h"
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
class AuteurWindow;
}

class AuteurWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AuteurWindow(QWidget *parent = nullptr);
    ~AuteurWindow();
    void insertAuteurRow(int ligne,Auteur l);
    void deleteAuteurRow(int ligne);
    void affichageDesAuteurs();
    static Auteur *tab;


private slots:
    void on_supprimerButton_clicked();

    void on_modifierButton_clicked();

    void on_ajouterButton_clicked();


    void on_rafraichirButton_clicked();

    void on_cleEdit_textChanged(const QString &arg1);

private:
    Ui::AuteurWindow *ui;
};

#endif // AUTEURWINDOW_H
