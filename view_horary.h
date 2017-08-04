#ifndef VIEW_HORARY_H
#define VIEW_HORARY_H

#include <QMainWindow>

namespace Ui {
class view_horary;
}

class view_horary : public QMainWindow
{
    Q_OBJECT

public:
    explicit view_horary(QWidget *parent = 0);
    ~view_horary();

private slots:
    void on_actionH_img_triggered();

private:
    Ui::view_horary *ui;
};

#endif // VIEW_HORARY_H
