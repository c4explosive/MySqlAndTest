#include "apiqserver.h"

ApiQServer::ApiQServer(QString IP,QObject* parent)
{
    this->IP=IP;
    this->parent=parent;
}

QJsonTableModel* ApiQServer::getModel()
{
    htm = new http_manager();
    htm->set_IP(IP);
    qba=htm->http_post_get("back to the future",1);
    header = json_utilities::get_header(qba);
    Qjmt = new QJsonTableModel(header,parent);
    Qjmt->setJson(QJsonDocument::fromJson(qba));
    return Qjmt;
}

QString ApiQServer::doQueries(QString query)
{
    //qDebug()<<"QU:: "<<query;
    htm = new http_manager();
    htm->set_IP(IP);
    response=QObject::tr(htm->http_post_get(query,0));
    return response;
}

QString ApiQServer::getIndividual()
{
    htm = new http_manager();
    htm->set_IP(IP);
    qba=htm->http_post_get("back to the future",1);
    QJsonDocument qjd = QJsonDocument::fromJson(qba);
    QString field=qjd.array().at(0).toArray().at(0)
            .toObject().keys().at(0);
    return qjd.array().at(0).toArray().at(0)
            .toObject().value(field).toString();
}

void ApiQServer::postQuery()
{
    htm = new http_manager();
    htm->set_IP(IP);
    qba=htm->http_post_get("back to the future",1);
}
