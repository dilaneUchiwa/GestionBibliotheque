#ifndef AIDEWIDGET_H
#define AIDEWIDGET_H

#include <QWidget>

namespace Ui {
class AideWidget;
}

class AideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AideWidget(QWidget *parent = nullptr);
    ~AideWidget();

private:
    Ui::AideWidget *ui;
};

#endif // AIDEWIDGET_H
