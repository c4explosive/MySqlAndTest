#include "agregartarea.h"
#include "ui_agregartarea.h"
#include "view_horary.h"

#include <QMessageBox>
#include <QScreen>

AgregarTarea::AgregarTarea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AgregarTarea)
{
    ui->setupUi(this);
    task=new uTask();
    ui->lblidObj->setText(task->getCod());
    ui->dtEnt->setDate(QDate::currentDate());
    ui->dtAd->setDate(QDate::currentDate());
    multiplesFxs::updateDB(ui->cboMat,"Materias","Materia");
    multiplesFxs::fixmyScreen(ui->centralwidget);
    QScreen *s = QApplication::screens().at(0);
    connect(s,SIGNAL(geometryChanged(const QRect)),
                     this,SLOT(orientCh(const QRect)));
    ui->spnPrio->setValue(55);

}

void AgregarTarea::orientCh(const QRect)
{
    multiplesFxs::fixmyScreen(ui->centralwidget);
    //qDebug()<<":::::Funciono???";
}


AgregarTarea::~AgregarTarea()
{
    delete ui;
}

void AgregarTarea::on_btnAccept_clicked()
{
    task->setMateria(multiplesFxs::getID("Materias","id_materia","Materia", ui->cboMat->currentText()));
    task->setDescripcion(ui->txtDescrp->toPlainText());
    task->setGrupo(ui->chkGrp->isChecked());

    if (ui->chbERR->isChecked())
        task->setF_Comp("RR");
    else
        task->setF_Comp(ui->dtEnt->text());
    if (ui->chbARR->isChecked())
        task->setF_Do("RR");
    else
        task->setF_Do(ui->dtAd->text());

    task->setPrioridad(ui->spnPrio->value());
    task->setPorc(ui->spnPorc->value());
    task->putTask();
    delete task;
    this->close();

}

void AgregarTarea::on_btnCancelar_clicked()
{
    this->close();
}

void AgregarTarea::on_actionFix_Screen_triggered()
{
    multiplesFxs::fixmyScreen(ui->centralwidget);
}

void AgregarTarea::on_actionH_img_triggered()
{
    view_horary * vH = new view_horary(this);
    vH->show();
}
