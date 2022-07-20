#include "aidewidget.h"
#include "ui_aidewidget.h"

AideWidget::AideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AideWidget)
{
    ui->setupUi(this);
    ui->creatorsLabel->setText("Crée par : SAGUEU WAKAM DILANE");
}

AideWidget::~AideWidget()
{
    delete ui;
}
