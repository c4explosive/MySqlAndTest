#ifndef ELIMINARTAREA_H
#define ELIMINARTAREA_H

#include <QMainWindow>
#include "utask.h"
#include "multiplesfxs.h"

namespace Ui {
class EliminarTarea;
}

class EliminarTarea : public QMainWindow
{
    Q_OBJECT

public:
    explicit EliminarTarea(QWidget *parent = 0);
    ~EliminarTarea();

public slots:
    void orientCh(const QRect);
private slots:
    void on_btnSearch_clicked();

    void on_btnDelete_clicked();

    void on_cboTask_currentIndexChanged(int index);

    void on_btnCancelar_2_clicked();


    void on_actionCopy_triggered();

    void on_actionFix_Screen_triggered();

    void on_actionH_img_triggered();

private:
    Ui::EliminarTarea *ui;
    uTask * task;
};

#endif // ELIMINARTAREA_H
