#ifndef EMPRUNTWINDOW_H
#define EMPRUNTWINDOW_H
#include "connexionbd.h"
#include "emprunt.h"
#include "add_emprunt.h"
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
class EmpruntWindow;
}

class EmpruntWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EmpruntWindow(QWidget *parent = nullptr);
    ~EmpruntWindow();
    void insertEmpruntRow(int ligne,Emprunt l);
    void deleteEmpruntRow(int ligne);
    void affichageDesEmprunts();
    static Emprunt *tab;


private slots:

    void on_modifierButton_clicked();

    void on_ajouterButton_clicked();

    void on_rafraichirButton_clicked();

private:
    Ui::EmpruntWindow *ui;
};

#endif // EMPRUNTWINDOW_H
