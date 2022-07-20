#ifndef LIVREWINDOW_H
#define LIVREWINDOW_H
#include "connexionbd.h"
#include "livre.h"
#include "add_modifylivre.h"
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
class LivreWindow;
}

class LivreWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LivreWindow(QWidget *parent = nullptr);
    ~LivreWindow();
    void insertLivreRow(int ligne,Livre l);
    void deleteLivreRow(int ligne);
    void affichageDesLivres();
    QStandardItemModel *model;
    static Livre *tab;


private slots:
    void on_supprimerButton_clicked();

    void on_modifierButton_clicked();

    void on_ajouterButton_clicked();


    void on_rafraichirButton_clicked();

    void on_cleEdit_textChanged(const QString &arg1);

    void on_cleEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::LivreWindow *ui;
};

#endif // LIVREWINDOW_H
