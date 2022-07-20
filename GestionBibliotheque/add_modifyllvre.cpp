#include "add_modifyllvre.h"
#include "ui_add_modifyllvre.h"

add_modifylLvre::add_modifylLvre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_modifylLvre)
{
    ui->setupUi(this);
}

add_modifylLvre::~add_modifylLvre()
{
    delete ui;
}
