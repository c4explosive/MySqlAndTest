#include "utask.h"

#include <QSqlQuery>

QString uTask::getCod() const
{
    return cod;
}

void uTask::setCod(const QString &value)
{
    cod = value;
}

QString uTask::getMateria() const
{
    return Materia;
}

void uTask::setMateria(const QString &value)
{
    Materia = value;
}

QString uTask::getDescripcion() const
{
    return Descripcion;
}

void uTask::setDescripcion(const QString &value)
{
    Descripcion = value;
}

bool uTask::getGrupo() const
{
    return Grupo;
}

void uTask::setGrupo(bool value)
{
    Grupo = value;
}

int uTask::getPrioridad() const
{
    return Prioridad;
}

void uTask::setPrioridad(int value)
{
    Prioridad = value;
}

QString uTask::getF_Comp() const
{
    return F_Comp;
}

void uTask::setF_Comp(const QString &value)
{
    F_Comp = value;
}

QString uTask::getF_Do() const
{
    return F_Do;
}

void uTask::setF_Do(const QString &value)
{
    F_Do = value;
}

double uTask::getPorc() const
{
    return Porc;
}

void uTask::setPorc(double value)
{
    Porc = value;
}

QString uTask::getDirectorio() const
{
    return Directorio;
}

void uTask::setDirectorio(const QString &value)
{
    Directorio = value;
}

uTask::uTask()
{
    cod=getCode();
}

QString uTask::boolToText(bool data)
{
    if(data)
        return "TRUE";
    else
        return "FALSE";
}

bool uTask::TextToBool(QString data)
{
    if(data=="TRUE")
        return true;
    else
        return false;
}

void uTask::updateITask(QString column, QString value)
{
    QSqlQuery * query = new QSqlQuery();
    QString queryS;
    queryS="UPDATE uTask"
            " SET "+column+"='"+value+"'"+
            " WHERE COD='"+cod+"';";
    //qDebug()<<"SQL::"<<queryS;
    query->prepare(queryS);
    query->exec();

}

void uTask::updateITask(QString column, int value)
{
    QSqlQuery * query = new QSqlQuery();
    QString queryS;
    queryS="UPDATE uTask"
            " SET "+column+"="+QString::number(value)+
            " WHERE COD='"+cod+"';";
    //qDebug()<<"SQL::"<<queryS;
    query->prepare(queryS);
    query->exec();

}


void uTask::updateITask(QString column, double value)
{
    QSqlQuery * query = new QSqlQuery();
    QString queryS;
    queryS="UPDATE uTask"
            " SET "+column+"="+QString::number(value)+
            " WHERE COD='"+cod+"';";
    //qDebug()<<"SQL::"<<queryS;
    query->prepare(queryS);
    query->exec();

}
void uTask::updateTask()
{

    updateITask("MATERIA",Materia);
    updateITask("DESCRP",Descripcion);
    updateITask("GRUPO",boolToText(Grupo));
    updateITask("PRIORITY",Prioridad);
    updateITask("F_COMP",F_Comp);
    updateITask("F_DO",F_Do);
    updateITask("PORC",Porc);

}

void uTask::putTask()
{
    QSqlQuery * query = new QSqlQuery();
    QString queryS;
    queryS="INSERT INTO uTask (COD,MATERIA,DESCRP,GRUPO,PRIORITY,F_COMP,F_DO,PORC)"
           " VALUES('"+cod+"','"+Materia+"','"+Descripcion+"','"+boolToText(Grupo)+
            "',"+QString::number(Prioridad)+",'"+F_Comp+"','"+F_Do+"',"+QString::number(Porc)+");";
    //qDebug()<<"SQL::"<<queryS;
    query->prepare(queryS);
    query->exec();
}

void uTask::deleteTask()
{
    QSqlQuery * query = new QSqlQuery();
    QString queryS;
    queryS="DELETE FROM uTask WHERE COD LIKE '%"+cod+"%'";
    //qDebug()<<"SQL::"<<queryS;
    query->prepare(queryS);
    query->exec();

}

void uTask::prepareRObj(QString descr)
{
    setCod(multiplesFxs::getID("uTask","COD","DESCRP",descr));
    Materia=multiplesFxs::getAtribute("uTask","MATERIA","COD",cod);
    Descripcion=multiplesFxs::getAtribute("uTask","DESCRP","COD",cod);
    Grupo=TextToBool(multiplesFxs::getAtribute("uTask","GRUPO","COD",cod));
    Prioridad=multiplesFxs::getAtribute("uTask","PRIORITY","COD",cod).toInt();
    F_Comp=multiplesFxs::getAtribute("uTask","F_COMP","COD",cod);
    F_Do=multiplesFxs::getAtribute("uTask","F_DO","COD",cod);
    Porc=multiplesFxs::getAtribute("uTask","PORC","COD",cod).toDouble();
}
