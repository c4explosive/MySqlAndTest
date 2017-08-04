#include "view_horary.h"
#include "ui_view_horary.h"

#include <QScreen>

view_horary::view_horary(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view_horary)
{
    ui->setupUi(this);
    const QString impath = "/storage/external_SD/H_A/H_1IL141_A.png";

    QScreen * screen = QApplication::screens().at(0);
    //int x=screen->size().width();
    int y=screen->size().height();
    /*ui->lbfix_Ab->setMinimumHeight(y/2);
    ui->lbfix_Ar->setMinimumHeight(y/2);*/
    int tm = (y/2)-((y/2)*.50);
    ui->lbfix_Ab->setFixedHeight(tm);
    ui->lbfix_Ar->setFixedHeight(tm);

    QImage image(impath);
    QImage image2 = image.scaled(2000,2000);
    ui->img_H->setScaledContents(true);
    ui->img_H->setPixmap(QPixmap::fromImage(image2));
    //multiplesFxs::fixmyScreen(ui->centralwidget);
}

view_horary::~view_horary()
{
    delete ui;
}

void view_horary::on_actionH_img_triggered()
{
    view_horary * vH = new view_horary(this);
    vH->show();
}
