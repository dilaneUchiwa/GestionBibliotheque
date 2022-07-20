#ifndef APROPOSWIDGET_H
#define APROPOSWIDGET_H

#include <QWidget>

namespace Ui {
class AproposWidget;
}

class AproposWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AproposWidget(QWidget *parent = nullptr);
    ~AproposWidget();

private:
    Ui::AproposWidget *ui;
};

#endif // APROPOSWIDGET_H
