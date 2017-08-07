#ifndef QJSONTABLEMODEL_H
#define QJSONTABLEMODEL_H

#include "http_manager.h"

#include <QObject>
#include <QVector>
#include <QMap>
#include <QAbstractTableModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

class QJsonTableModel : public QAbstractTableModel
{
public:
    typedef QMap<QString,QString> Heading;
    typedef QVector<Heading> Header;
    typedef QVector<QString> Headerz;
    QJsonTableModel( const Headerz& header, QObject * parent = 0);

    bool setJson( const QJsonDocument& json );
    //bool setJson( const QJsonArray& array );

    virtual QJsonObject getJsonObject( const QModelIndex &index ) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
    Headerz m_header;
    QJsonDocument m_json;
    int rows;
    int cols;
};

#endif // QJSONTABLEMODEL_H
