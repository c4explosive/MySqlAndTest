#ifndef BUSCARTAREA_H
#define BUSCARTAREA_H

#include <QMainWindow>
#include "utask.h"
#include "ufilter.h"
#include "multiplesfxs.h"

namespace Ui {
class BuscarTarea;
}

class BuscarTarea : public QMainWindow
{
    Q_OBJECT

public:
    explicit BuscarTarea(QWidget *parent = 0);
    ~BuscarTarea();

protected slots:
    void orientCh(const QRect);
private slots:
    void on_btnSearch_clicked();

    void on_tblRes_doubleClicked(const QModelIndex &index);

    void on_tblRes_clicked(const QModelIndex &index);

    void on_actionFix_Screen_triggered();


    void on_actionH_img_triggered();

private:
    Ui::BuscarTarea *ui;
    uTask * task;
    uFilter * filter;
    void AbstractBool();
};

#endif // BUSCARTAREA_H
