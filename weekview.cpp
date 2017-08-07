#include "ui_weekview.h"
#include "weekview.h"

#include <QDebug>
#include <QDate>
#include <QScroller>
#include <QScreen>
#include <QLinkedList>
#include <QCheckBox>
#include <QClipboard>

WeekView::WeekView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WeekView)
{
    ui->setupUi(this);
    ui->dtEnt->setDate(QDate::currentDate());
    filter=new uFilter(this);
    multiplesFxs::updateDB(ui->cboMat,"Materias","Materia");
    ui->chbNot100->setChecked(true);
    multiplesFxs::fixmyScreen(ui->centralwidget);

    ui->tblRes->setHorizontalHeader(new QHeaderView(Qt::Horizontal));
    QPalette * pal = new QPalette();
    pal->setColor(QPalette::Base,Qt::black);
    pal->setColor(QPalette::AlternateBase,Qt::black);
    pal->setColor(QPalette::Window,Qt::black);
    pal->setColor(QPalette::Button,Qt::black);
    ui->tblRes->horizontalHeader()->setPalette(*pal);
    ui->tblRes->setVerticalHeader(new QHeaderView(Qt::Vertical));
    pal->setColor(QPalette::Button,Qt::black);
    ui->tblRes->verticalHeader()->setPalette(*pal);

    ui->tblRes->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tblRes->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller::grabGesture(ui->tblRes->viewport(),QScroller::LeftMouseButtonGesture);
    QScreen *s = QApplication::screens().at(0);
    connect(s,SIGNAL(geometryChanged(const QRect)),
                     this,SLOT(orientCh(const QRect)));

}

void WeekView::AbstractBool()
{
    QLinkedList<QCheckBox*> ChBArray;
    QLinkedList<bool*> boolfArray;
    ChBArray<<ui->chbMat<<ui->chbNot100<<ui->chbAd<<ui->chbEnt<<ui->chbGroup<<ui->chbPrio;
    boolfArray<<&filter->FMateria<<&filter->FN100<<&filter->FAdelantar<<&filter->FEntrega<<&filter->FGrupo<<&filter->FPriority;
    QLinkedList<bool*>::Iterator nBool;
    nBool=boolfArray.begin();
    foreach(QCheckBox* chb,ChBArray)
    {
        if (chb->isChecked())
           **nBool=true;
        else
           **nBool=false;
        nBool++;
    } //i'm worried... 15042017 some things are not good... ouch...
    //delete &ChBArray;
    /*foreach(bool ndata,boolfArray)
    {
        qDebug()<<"CHK:: "<<ndata;
    }*/
    //delete &boolfArray;*/

}

WeekView::~WeekView()
{
    delete ui;
}

void WeekView::on_btnSearch_clicked()
{
    int i;
    QList<QString> ctoDates;
    ctoDates=multiplesFxs::getStrings(ui->dtEnt->date());
    AbstractBool();
    filter->setDescripcion(ui->txtfilter->text());
    filter->setMateria(multiplesFxs::getID("Materias","id_materia","Materia",ui->cboMat->currentText())); //Ver lo de las materias
    filter->setPrioridad(ui->spbPrio->value());
    /*filter->setF_Comp(ui->dtEnt->text());
    filter->setF_Do(ui->dtAd->text());*/
    filter->getResults(ui->tblRes,ctoDates);

    //qDebug()<<"My Monday: "<<multiplesFxs::get_monday(cDate).toString("dd/MM/yyyy");
}

void WeekView::on_tblRes_clicked(const QModelIndex &index)
{
    int Perc;
    ui->txtDescrp->setText(ui->tblRes->model()->data(ui->tblRes->currentIndex()).toString());
    //qDebug()<<"Rows Progress:: "<<index.sibling(index.row(),5).data();
    Perc=index.sibling(index.row(),5).data().toInt();
    ui->pbarProgress->setValue(Perc);
    ui->lblPrPr->setText(QString::number(Perc)+"%");

}

void WeekView::on_tblRes_doubleClicked(const QModelIndex &index)
{
    QClipboard * clip = QApplication::clipboard();
    clip->setText(ui->tblRes->model()->data(ui->tblRes->currentIndex()).toString());
}

void WeekView::on_actionFix_Screen_triggered()
{
    multiplesFxs::fixmyScreen(ui->centralwidget);

}

