#include "ufilter.h"




bool uFilter::getFMateria() const
{
    return FMateria;
}

void uFilter::setFMateria(bool value)
{
    FMateria = value;
}

bool uFilter::getFN100() const
{
    return FN100;
}

void uFilter::setFN100(bool value)
{
    FN100 = value;
}

bool uFilter::getFGrupo() const
{
    return FGrupo;
}

void uFilter::setFGrupo(bool value)
{
    FGrupo = value;
}

bool uFilter::getFPriority() const
{
    return FPriority;
}

void uFilter::setFPriority(bool value)
{
    FPriority = value;
}

bool uFilter::getFEntrega() const
{
    return FEntrega;
}

void uFilter::setFEntrega(bool value)
{
    FEntrega = value;
}

bool uFilter::getFAdelantar() const
{
    return FAdelantar;
}

void uFilter::setFAdelantar(bool value)
{
    FAdelantar = value;
}

uFilter::uFilter(QObject * parent)
{
    aqs = new ApiQServer("127.0.0.1",parent);
} //BUG: aqs is declared 2 times (see multiplesfxs).

void uFilter::ufPrepare()
{
    /*uQuery="SELECT COD [Código],m.Materia ,DESCRP [Descripción],"
           "F_COMP [Fecha de Completado],F_DO [Fecha Auxiliar],PORC [Porcentaje], Directorio [Directorio] "
           "FROM Materias m LEFT JOIN uTask u "
           "ON m.id_materia=u.Materia WHERE u.DESCRP LIKE '%"+Descripcion+"%'";*/
    uQuery="SELECT COD 'Código',m.Materia ,DESCRP 'Descripción',"
           "F_COMP 'Fecha de Completado',F_DO 'Fecha Auxiliar',PORC 'Porcentaje', u.PRIORITY 'Prioridad' " //Directorio 'Directorio'
           "FROM Materias m LEFT JOIN uTask u "
           "ON m.id_materia=u.Materia WHERE u.DESCRP LIKE '%"+Descripcion+"%'";
    if(FN100)
        uQuery+=" AND u.PORC<100";
    if(FMateria)
        uQuery+=" AND u.MATERIA LIKE '%"+Materia+"%'";
    if(FGrupo)
        uQuery+=" AND u.GRUPO LIKE '%TRUE%'";
    if(FPriority)
        uQuery+=" AND u.PRIORITY="+QString::number(Prioridad);
    if(FEntrega)
        uQuery+=" AND u.F_COMP LIKE '%"+F_Comp+"%'";
    if(FAdelantar)
        uQuery+=" AND u.F_DO LIKE '%"+F_Do+"%'";

    uQuery+=" ORDER BY u.PRIORITY";

}

void uFilter::ufPrepare(QList<QString> slist) //Semanal
{
    int i;

    uQuery="SELECT COD 'Código',m.Materia ,DESCRP 'Descripción',"
           "F_COMP 'Fecha de Completado',F_DO 'Fecha Auxiliar',PORC 'Porcentaje', u.PRIORITY 'Prioridad' " //Directorio 'Directorio'
           "FROM Materias m LEFT JOIN uTask u "
           "ON m.id_materia=u.Materia WHERE u.DESCRP LIKE '%"+Descripcion+"%' AND (";
    for(i=0;i<7;i++)
    {
        if(i==0)
            uQuery+="u.F_COMP LIKE '%"+slist.at(i)+"%'";
        else
            uQuery+=" OR u.F_COMP LIKE '%"+slist.at(i)+"%'";

    }
    uQuery+=" OR u.F_COMP LIKE '%RR%'";
    uQuery+=")";
    if(FN100)
        uQuery+=" AND u.PORC<100";
    if(FMateria)
        uQuery+=" AND u.MATERIA LIKE '%"+Materia+"%'";
    if(FGrupo)
        uQuery+=" AND u.GRUPO LIKE '%TRUE%'";
    uQuery+=" ORDER BY u.F_COMP";

    qDebug()<<"uQuery_PRE:: "<<uQuery;

}

void uFilter::getResults(QTableView * widget) //BUG?: This should be in a class...
{
    ufPrepare();
    QString queryS;
    queryS=uQuery;
    aqs->doQueries(queryS);
    widget->setModel(aqs->getModel());
}

void uFilter::getResults(QTableView * widget, QList<QString> slist) //BUG?: This should be in a class...
{
    ufPrepare(slist);
    QString queryS;
    queryS=uQuery;
    aqs->doQueries(queryS);
    widget->setModel(aqs->getModel());
}
