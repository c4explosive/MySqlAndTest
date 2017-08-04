#ifndef AGREGARTAREA_H
#define AGREGARTAREA_H

#include <QMainWindow>
#include "utask.h"
#include "multiplesfxs.h"

namespace Ui {
class AgregarTarea;
}

class AgregarTarea : public QMainWindow
{
    Q_OBJECT

public:
    explicit AgregarTarea(QWidget *parent = 0);
    ~AgregarTarea();

public slots:
    void orientCh(const QRect);
private slots:
    void on_btnAccept_clicked();

    void on_btnCancelar_clicked();

    void on_actionFix_Screen_triggered();

    void on_actionH_img_triggered();

private:
    Ui::AgregarTarea *ui;
    uTask * task;
};

#endif // AGREGARTAREA_H
