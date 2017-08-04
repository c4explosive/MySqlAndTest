#include "eliminartarea.h"
#include "ui_eliminartarea.h"
#include "view_horary.h"

#include <QClipboard>
#include <QScreen>

EliminarTarea::EliminarTarea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EliminarTarea)
{
    ui->setupUi(this);
    task = new uTask();
    multiplesFxs::updateDB(ui->cboTask,"uTask","DESCRP");
    multiplesFxs::fixmyScreen(ui->centralwidget);
    QScreen *s = QApplication::screens().at(0);
    connect(s,SIGNAL(geometryChanged(const QRect)),
                     this,SLOT(orientCh(const QRect)));

}

void EliminarTarea::orientCh(const QRect)
{
    multiplesFxs::fixmyScreen(ui->centralwidget);
    //qDebug()<<":::::Funciono???";
}

EliminarTarea::~EliminarTarea()
{
    delete ui;
}

void EliminarTarea::on_btnSearch_clicked()
{
    multiplesFxs::updateDB(ui->cboTask,"uTask","DESCRP","COD",ui->txtfilter->text());
}

void EliminarTarea::on_btnDelete_clicked()
{
    task->setCod(multiplesFxs::getID("uTask","COD","DESCRP",ui->cboTask->currentText()));
    task->deleteTask();
    this->close();

}

void EliminarTarea::on_cboTask_currentIndexChanged(int index)
{
    task->setCod(multiplesFxs::getID("uTask","COD","DESCRP",ui->cboTask->currentText()));
    ui->lblCod->setText(task->getCod());

}

void EliminarTarea::on_btnCancelar_2_clicked()
{
    this->close();
}


void EliminarTarea::on_actionCopy_triggered()
{
    QClipboard * clip= QApplication::clipboard();
    ui->txtfilter->setText(clip->text());

}

void EliminarTarea::on_actionFix_Screen_triggered()
{
    multiplesFxs::fixmyScreen(ui->centralwidget);

}

void EliminarTarea::on_actionH_img_triggered()
{
    view_horary * vH = new view_horary(this);
    vH->show();

}
