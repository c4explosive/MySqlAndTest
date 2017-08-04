#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "multiplesfxs.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString impath;

public slots:
    void orientCh(const QRect);
    void openFileNameReady(QString fileName);
private slots:
    void on_btnAddTask_clicked();

    void on_actionOpenDatabase_triggered();

    void on_btnModTask_clicked();

    void on_btnShowTask_clicked();

    void on_btnDelTask_clicked();

    void on_actionS_intent_triggered();

    void on_actionH_img_triggered();

    void on_actionHsIntent_Testing_generic_triggered();

    void on_btnShowWeek_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
