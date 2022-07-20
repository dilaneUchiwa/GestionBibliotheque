#ifndef ADD_MODIFYLLVRE_H
#define ADD_MODIFYLLVRE_H

#include <QDialog>

namespace Ui {
class add_modifylLvre;
}

class add_modifylLvre : public QDialog
{
    Q_OBJECT

public:
    explicit add_modifylLvre(QWidget *parent = nullptr);
    ~add_modifylLvre();

private:
    Ui::add_modifylLvre *ui;
};

#endif // ADD_MODIFYLLVRE_H
