#ifndef SND_H
#define SND_H

#include <QMainWindow>

namespace Ui {
class snd;
}

class snd : public QMainWindow
{
    Q_OBJECT

public:
    explicit snd(QWidget *parent = 0);
    ~snd();

private slots:
    void on_close_clicked();

private:
    Ui::snd *ui;
};

#endif // SND_H
