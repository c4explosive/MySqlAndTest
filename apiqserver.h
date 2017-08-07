#ifndef APIQSERVER_H
#define APIQSERVER_H

#include<QString>
#include<QJsonObject>
#include<QJsonValue>

#include "json_utilities.h"
#include "qjsontablemodel.h"


class ApiQServer
{
public:
    ApiQServer(QString IP,QObject *);
    QString doQueries(QString query);
    QJsonTableModel * getModel();
    void postQuery();
    QString getIndividual();
private:
    QString IP;
    QString response;
    http_manager* htm;
    QByteArray qba;
    QJsonTableModel::Headerz header;
    QJsonTableModel *Qjmt;
    QObject *parent;
};

#endif // APIQSERVER_H
