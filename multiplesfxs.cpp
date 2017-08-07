#include "multiplesfxs.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QTableView>
#include <QScreen>
#include <QApplication>
#include <QSqlError>
#include <QDate>

#include "agregartarea.h"
#include "modificartarea.h"
#include "buscartarea.h"
#include "eliminartarea.h"
#include "weekview.h"
/*#include "utaskfolder.h"
#include "ipchoose.h"*/




QSqlDatabase qsldb; //Esto NO se hace!!
ApiQServer *aqs;

multiplesFxs::multiplesFxs()
{
}

void multiplesFxs::whatWindow(QWidget * parent, int var)
{
    if (qsldb.isOpen()) //Verifica si la base de datos está conectada.
    {

        qDebug()<<"NEW::API::: "<<aqs->getIndividual();
        QMessageBox::critical(parent,"Error en Base de Datos","Base de Datos no conectada, Conecte la base de datos primero.");
        dbConnect(parent,"127.0.0.1");
        //ipchoose * w = new ipchoose();
        //w->show();
    }
    else
    {
        dbConnect(parent,"127.0.0.1");
        switch (var)
        {
        case multiplesFxs::AGREGARUTASK:
            { //This {} are necessary because C++ turns angry if you declared into a case...
                 AgregarTarea * win_Aobj = new AgregarTarea();
                 win_Aobj->show();
            }
            break;
        case multiplesFxs::BUSCARUTASK:
            {
                BuscarTarea * win_Bobj = new BuscarTarea();
                win_Bobj->show();
            }
            break;
        case multiplesFxs::MODIFICARUTASK:
            {
                ModificarTarea * win_Mobj = new ModificarTarea();
                win_Mobj->show();
            }
            break;
        case multiplesFxs::ELIMINARUTASK:
            {
                EliminarTarea * win_Eobj = new EliminarTarea();
                win_Eobj->show();
            }
            break;

        case multiplesFxs::BUSCASEMANA:
            {
               WeekView * win_WView = new WeekView();
               win_WView->show();
            }
            break;
        /*case multiplesFxs::ASIGFOLDER:
            {
                uTaskFolder * win_Af = new uTaskFolder();
                win_Af->show();
            }*/

        }


        //qDebug()<<"Está abierto.";
    }
    //qDebug()<<"Val: "<<var;
}


void multiplesFxs::dbConnect(QWidget * parent,QString IPaddr)
{
    aqs = new ApiQServer(IPaddr,parent);
        /*QMessageBox * msg = new QMessageBox(parent);
        msg->information(parent,"Estatus de la Base de Datos",aqs->getIndividual());*/

}

void multiplesFxs::updateDB(QComboBox * cbo, QString Table, QString column)
{
    QString queryS;
    if(Table!="uTask")
        queryS="SELECT "+column+" FROM "+Table+";";
    else
        queryS="SELECT "+column+" FROM "+Table+" WHERE PORC<100";
    qDebug()<<"THE::QUERY::"<<queryS;
    aqs->doQueries(queryS);
    cbo->setModel(aqs->getModel());
}

void multiplesFxs::updateDB(QComboBox *cbo, QString Table, QString column, QString filter)
{
    QString queryS;
    if(Table != "uTask")
        queryS="SELECT "+column+" FROM "+Table+" WHERE "+column+" LIKE "+"'%"+filter+"%'"+";";
    else
        queryS="SELECT "+column+" FROM "+Table+" WHERE "+column+" LIKE "+"'%"+filter+"%'"+" AND PORC<100;";

    QSqlQuery * query = new QSqlQuery();
    aqs->doQueries(queryS);
    cbo->setModel(aqs->getModel());

}

void multiplesFxs::updateDB(QComboBox *cbo, QString Table, QString column, QString column2, QString filter)
{
    QString queryS;
    if(Table != "uTask")
        queryS="SELECT "+column+" FROM "+Table+" WHERE "+column+" LIKE "+"'%"+filter+"%' OR "+column2+" LIKE '%"+filter+"%';";
    else
        queryS="SELECT "+column+" FROM "+Table+" WHERE "+column+" LIKE "+"'%"+filter+"%' OR "+column2+" LIKE '%"+filter+"%';";
        //queryS="SELECT "+column+" FROM "+Table+" WHERE "+column+" LIKE "+"'%"+filter+"%' OR "+column2+" LIKE '%"+filter+"%' AND PORC<100;";
        //BUG: Why the discrimination?, for this, can't modify 100% task...
    aqs->doQueries(queryS);
    cbo->setModel(aqs->getModel());

}

QString multiplesFxs::getID(QString Table, QString id_col, QString col, QString qVal)
{
    QString queryS = "SELECT "+id_col+" FROM "+Table+" WHERE "+col+" LIKE '%"+qVal+"%';";
    aqs->doQueries(queryS);
    QString result=aqs->getIndividual();
    return result;
}

QString multiplesFxs::getAtribute(QString Table, QString col, QString id_col, QString id )
{
    QString queryS = "SELECT "+col+" FROM "+Table+" WHERE "+id_col+" LIKE '%"+id+"%';";
    QString result;
    aqs->doQueries(queryS);
    result=aqs->getIndividual();
    return result;

}


void multiplesFxs::fixmyScreen(QWidget * widget)
{
    QScreen * screen = QApplication::screens().at(0);
    int x=screen->size().width();
    int y=screen->size().height();
    widget->setFixedWidth(x);
    widget->setFixedHeight(y-70);

}

QDate multiplesFxs::get_monday(QDate sDate)
{
    QDate uDate;
    if(sDate.dayOfWeek() == 1)
    {
        return sDate;
    }
    else
    {
        uDate = sDate;
        while (uDate.dayOfWeek() != 1)
        {
            uDate=uDate.addDays(-1);
        }
        return uDate;
    }

}

QList<QString> multiplesFxs::getStrings(QDate sDate)
{
    int i;
    QList<QString> ctoDates;
    QDate cDate;
    cDate=multiplesFxs::get_monday(sDate);
    for(i=0;i<7;i++)
    {
        ctoDates<<cDate.toString("dd/MM/yyyy");
        cDate=cDate.addDays(1);
    }
    return ctoDates;

}
