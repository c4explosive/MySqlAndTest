#ifndef MODIFICARTAREA_H
#define MODIFICARTAREA_H

#include <QMainWindow>
#include "utask.h"
#include "multiplesfxs.h"

namespace Ui {
class ModificarTarea;
}

class ModificarTarea : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModificarTarea(QWidget *parent = 0);
    ~ModificarTarea();

public slots:
    void orientCh(const QRect);
private slots:
    void on_cboTask_currentIndexChanged(int index);

    void on_btnSearch_clicked();

    void on_btnAccept_2_clicked();

    void on_btnCancelar_2_clicked();


    void on_actionCopy_triggered();

    void on_actionFix_Screen_triggered();

    void on_actionH_img_triggered();

    void on_actionCompleteUtask_triggered();

    void on_sliderProgress_valueChanged(int value);

private:
    Ui::ModificarTarea *ui;
    uTask * task;
};

#endif // MODIFICARTAREA_H
