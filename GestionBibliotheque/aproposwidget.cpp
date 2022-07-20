#include "aproposwidget.h"
#include "ui_aproposwidget.h"

AproposWidget::AproposWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AproposWidget)
{
    ui->setupUi(this);
    ui->creatorsLabel->setText("Crée par : SAGUEU WAKAM DILANE");
}

AproposWidget::~AproposWidget()
{
    delete ui;
}
