#include "snd.h"
#include "ui_snd.h"

snd::snd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::snd)
{
    ui->setupUi(this);
}

snd::~snd()
{
    delete ui;
}

void snd::on_close_clicked()
{
    this->close();
}
