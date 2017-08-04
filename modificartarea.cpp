#include "modificartarea.h"
#include "ui_modificartarea.h"
#include "view_horary.h"

#include <QClipboard>
#include <QScreen>
#include <QDebug>

ModificarTarea::ModificarTarea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModificarTarea)
{
    ui->setupUi(this);
    task = new uTask();
    multiplesFxs::updateDB(ui->cboTask,"uTask","DESCRP");
    multiplesFxs::updateDB(ui->cboMat_2,"Materias","Materia");
    ui->dtEnt_2->setDate(QDate::currentDate());
    ui->dtAd_2->setDate(QDate::currentDate());
    multiplesFxs::fixmyScreen(ui->centralwidget);
    QScreen *s = QApplication::screens().at(0);
    connect(s,SIGNAL(geometryChanged(const QRect)),
                     this,SLOT(orientCh(const QRect)));

}

void ModificarTarea::orientCh(const QRect)
{
    multiplesFxs::fixmyScreen(ui->centralwidget);
    //qDebug()<<":::::Funciono???";
}

ModificarTarea::~ModificarTarea()
{
    delete ui;
}

void ModificarTarea::on_cboTask_currentIndexChanged(int index)
{
    task->prepareRObj(ui->cboTask->currentText());
    ui->lblCod->setText(task->getCod());
    ui->cboMat_2->setCurrentIndex(ui->cboMat_2->findText(multiplesFxs::getAtribute(
                                                         "Materias","Materia","id_materia",task->getMateria())));
    ui->txtDescrp_2->setText(task->getDescripcion());

    if(task->getGrupo())
        ui->chkGrp_2->setChecked(true);
    else
        ui->chkGrp_2->setChecked(false);
    //qDebug()<<"ENT:: "<<task->getF_Comp();
    if(task->getF_Comp()=="RR")
        ui->chbERR_2->setChecked(true);
    else
    {
        ui->chbERR_2->setChecked(false);
        ui->dtEnt_2->setDate(QDate::fromString(task->getF_Comp(),"dd/MM/yyyy"));
    }
    //qDebug()<<"DO:: "<<task->getF_Do();
    if(task->getF_Do()=="RR")
        ui->chbARR_2->setChecked(true);
    else
    {
        ui->chbARR_2->setChecked(false);
        ui->dtAd_2->setDate(QDate::fromString(task->getF_Do(),"dd/MM/yyyy"));
    }

    ui->spnPrio_2->setValue(task->getPrioridad());
    ui->spnPorc_2->setValue(task->getPorc());
    ui->sliderProgress->setValue(ui->spnPorc_2->value());

}

void ModificarTarea::on_btnSearch_clicked()
{
    multiplesFxs::updateDB(ui->cboTask,"uTask","DESCRP","COD",ui->txtfilter->text());
}

void ModificarTarea::on_btnAccept_2_clicked()
{
    task->setMateria(multiplesFxs::getID("Materias","id_materia","Materia", ui->cboMat_2->currentText()));
    task->setDescripcion(ui->txtDescrp_2->toPlainText());
    task->setGrupo(ui->chkGrp_2->isChecked());

    if (ui->chbERR_2->isChecked())
        task->setF_Comp("RR");
    else
        task->setF_Comp(ui->dtEnt_2->text());
    if (ui->chbARR_2->isChecked())
        task->setF_Do("RR");
    else
        task->setF_Do(ui->dtAd_2->text());

    task->setPrioridad(ui->spnPrio_2->value());
    task->setPorc(ui->spnPorc_2->value());
    task->updateTask();
    delete task;
    this->close();

}

void ModificarTarea::on_btnCancelar_2_clicked()
{
    this->close();
}


void ModificarTarea::on_actionCopy_triggered()
{
    QClipboard * clip= QApplication::clipboard();
    ui->txtfilter->setText(clip->text());
}

void ModificarTarea::on_actionFix_Screen_triggered()
{
    multiplesFxs::fixmyScreen(ui->centralwidget);
}

void ModificarTarea::on_actionH_img_triggered()
{
   view_horary * vH = new view_horary(this);
    vH->show();

}

void ModificarTarea::on_actionCompleteUtask_triggered()
{
    //BUG: Repeated Code!!! [[ModificarTarea::on_btnAccept_2_clicked()]]
    task->setMateria(multiplesFxs::getID("Materias","id_materia","Materia", ui->cboMat_2->currentText()));
    task->setDescripcion(ui->txtDescrp_2->toPlainText());
    task->setGrupo(ui->chkGrp_2->isChecked());

    if (ui->chbERR_2->isChecked())
        task->setF_Comp("RR");
    else
        task->setF_Comp(ui->dtEnt_2->text());
    if (ui->chbARR_2->isChecked())
        task->setF_Do("RR");
    else
        task->setF_Do(ui->dtAd_2->text());

    task->setPrioridad(ui->spnPrio_2->value());
    task->setPorc(100);
    task->updateTask();
    delete task;
    this->close();

}

void ModificarTarea::on_sliderProgress_valueChanged(int value)
{
    ui->spnPorc_2->setValue(value);
}
