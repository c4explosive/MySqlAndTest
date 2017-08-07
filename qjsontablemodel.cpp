#include "qjsontablemodel.h"
#include <QJsonObject>

QJsonTableModel::QJsonTableModel( const QJsonTableModel::Headerz& header, QObject * parent )
    : QAbstractTableModel( parent )
    , m_header( header )
{

}

/*bool QJsonTableModel::setJson(const QJsonDocument &json)
{
    return setJson( json.array() );
}*/

bool QJsonTableModel::setJson( const QJsonDocument& array )
{
    beginResetModel();
    m_json = array;
    //qDebug()<< "Mi querido:: "<< m_json.array().size();
    rows=m_json.array().size();
    endResetModel();
    return true;
}

QVariant QJsonTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( role != Qt::DisplayRole )
    {
        return QVariant();
    }

    switch( orientation )
    {
    case Qt::Horizontal:
        return m_header[section];
    }

}

int QJsonTableModel::rowCount(const QModelIndex &parent ) const
{
    return rows;
}

int QJsonTableModel::columnCount(const QModelIndex &parent ) const
{
    return m_header.size();
}


QJsonObject QJsonTableModel::getJsonObject( const QModelIndex &index ) const
{
    /*const QJsonValue& value = m_json[index.row() ];
    return value.toObject();*/
}

QVariant QJsonTableModel::data( const QModelIndex &index, int role ) const
{
 switch( role )
    {
    case Qt::DisplayRole:
    {
        return QString(m_json.array().at(index.row()).toArray()
                .at(index.column()).toObject()
                .value(m_header[index.column()]).toString());
    }
    case Qt::ToolTipRole:
        return QVariant();
    default:
        return QVariant();
    }
}
