#ifndef MODIFYLIVRE_H
#define MODIFYLIVRE_H

#include <QWidget>

namespace Ui {
class ModifyLivre;
}

class ModifyLivre : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyLivre(QWidget *parent = nullptr);
    ~ModifyLivre();

private:
    Ui::ModifyLivre *ui;
};

#endif // MODIFYLIVRE_H
