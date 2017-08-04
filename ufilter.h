#ifndef UFILTER_H
#define UFILTER_H

#include "multiplesfxs.h"
#include "utask.h"

#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

class uFilter:public uTask
{
private:
    QString uQuery;
    void ufPrepare();
    void ufPrepare(QList<QString>);
    public:
    bool FMateria;
    bool FN100;
    bool FGrupo;
    bool FPriority;
    bool FEntrega;
    bool FAdelantar;

    uFilter();
    bool getFMateria() const;
    void setFMateria(bool value);
    bool getFN100() const;
    void setFN100(bool value);
    bool getFGrupo() const;
    void setFGrupo(bool value);
    bool getFPriority() const;
    void setFPriority(bool value);
    bool getFEntrega() const;
    void setFEntrega(bool value);
    bool getFAdelantar() const;
    void setFAdelantar(bool value);
    void getResults(QTableView *widget);
    void getResults(QTableView *widget, QList<QString> slist);

};

#endif // UFILTER_H
