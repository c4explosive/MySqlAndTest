#include "http_manager.h"


http_manager::http_manager()
{

}

QByteArray http_manager::http_post_get(QString zquery, int mode)
{
    myURL = new QUrl(QString("http://"+IP+":3000/api/viewall"));
    request = new QNetworkRequest(*myURL);
    //request->setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    params.setQuery("zquery="+zquery,QUrl::TolerantMode);
    switch (mode) {
    case 0:
        //qDebug()<<"0Q:: "<<params;
        //qDebug()<<"Whats URL wrong::: "<<params;
        reply = nmgr.post(*request,params.toEncoded());
        break;
    case 1:
        reply = nmgr.get(*request);
        break;
    default:
        break;
    }
    QObject::connect(&nmgr,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    eventLoop.exec();

    bin_response=reply->readAll();
    response = QObject::tr(bin_response);

    //qDebug() << "In String" << response;
    //qDebug() << "In Binary" << bin_response;

    return bin_response;
}

void http_manager::set_IP(QString IP)
{
    this->IP=IP;
}
