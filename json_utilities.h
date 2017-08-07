#ifndef JSON_UTILITIES_H
#define JSON_UTILITIES_H

#include "qjsontablemodel.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

class json_utilities
{
public:
    json_utilities();
    static QJsonTableModel::Headerz get_header(QByteArray);
};

#endif // JSON_UTILITIES_H
