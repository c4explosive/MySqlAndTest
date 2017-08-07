#ifndef HTTP_MANAGER_H
#define HTTP_MANAGER_H

#include <QUrl>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QDebug>
#include <QString>
#include <QJsonDocument>
#include <QEventLoop>


class http_manager
{

private:
    QUrl* myURL;
    QNetworkRequest * request;
    QNetworkAccessManager nmgr;
    QUrl params;
    QNetworkReply *reply;
    QEventLoop eventLoop;
    QString response;
    QByteArray bin_response;
    QString IP;
public:
    http_manager();
    void set_IP(QString);
    QByteArray http_post_get(QString zquery, int);
};

#endif // HTTP_MANAGER_H
