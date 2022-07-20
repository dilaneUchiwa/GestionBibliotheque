#include "modifylivre.h"
#include "ui_modifylivre.h"

ModifyLivre::ModifyLivre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyLivre)
{
    ui->setupUi(this);
}

ModifyLivre::~ModifyLivre()
{
    delete ui;
}
