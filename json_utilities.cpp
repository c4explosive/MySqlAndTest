#include "json_utilities.h"

json_utilities::json_utilities()
{

}

QJsonTableModel::Headerz json_utilities::get_header(QByteArray qba)
{
    QJsonDocument njson = QJsonDocument::fromJson(qba);
    QJsonArray njs = njson.array();
    QJsonArray njsn2 = njs.at(0).toArray();
    QJsonTableModel::Headerz header;
    for(int i=0;i<njsn2.size();i++)
    {
        header.push_back(njsn2.at(i).toObject().keys().at(0));
    }
    //qDebug()<<"FORGET THE PAST AND ENJOY WITHOUT ANY SHIT!!!!!!!!!";
    return header;
}

