#ifndef UTASK_H
#define UTASK_H

#include <QString>
#include <QDebug>

#include "entitiesfxs.h"
#include "multiplesfxs.h"
#include "apiqserver.h"

class uTask : EntitiesFxs
{
private:
    QString cod;
    bool Grupo;
    double Porc;
    ApiQServer * aqs;
    QString Directorio;
    void updateITask(QString column, int value);
    void updateITask(QString column, QString value);
    void updateITask(QString column, double value);
    public:
    QString Materia;
    QString Descripcion;
    int Prioridad;
    QString F_Comp;
    QString F_Do;


    uTask();
    uTask(QObject *);
    QString getCod() const;
    void setCod(const QString &value);
    QString getMateria() const;
    void setMateria(const QString &value);
    QString getDescripcion() const;
    void setDescripcion(const QString &value);
    bool getGrupo() const;
    void setGrupo(bool value);
    int getPrioridad() const;
    void setPrioridad(int value);
    QString getF_Comp() const;
    void setF_Comp(const QString &value);
    QString getF_Do() const;
    void setF_Do(const QString &value);
    double getPorc() const;
    void setPorc(double value);
    QString getDirectorio() const;
    void setDirectorio(const QString &value);
    QString boolToText(bool data);
    bool TextToBool(QString data);
    void putTask();
    void prepareRObj(QString descr);
    void updateTask();
    void deleteTask();
};

#endif // UTASK_H
