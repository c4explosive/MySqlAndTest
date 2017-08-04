#ifndef WEEKVIEW_H
#define WEEKVIEW_H

#include "multiplesfxs.h"
#include "ufilter.h"

#include <QMainWindow>

namespace Ui {
class WeekView;
}

class WeekView : public QMainWindow
{
    Q_OBJECT

public:
    explicit WeekView(QWidget *parent = 0);
    ~WeekView();

private slots:
    void on_btnSearch_clicked();

    void on_tblRes_clicked(const QModelIndex &index);
    void on_actionFix_Screen_triggered();
    void on_tblRes_doubleClicked(const QModelIndex &index);

private:
    Ui::WeekView *ui;
    uFilter * filter;
    void AbstractBool();

};

#endif // WEEKVIEW_H
