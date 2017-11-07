#include "BaseModel.h"

QJsonObject BaseModel::validateJson(const QString &json, bool& ok)
{
    QJsonDocument jDoc = QJsonDocument::fromJson(json.toUtf8());
    if( jDoc.isNull() )
    {
        qDebug() << "ERROR: Document is not an object"<<json;
        ok = false;
        return QJsonObject();
    }

    if( !jDoc.isObject() )
    {
        qDebug() << "ERROR: " << "Invalid JSON...\n" << json;
        ok = false;
        return QJsonObject();
    }

    ok = true;
    return jDoc.object();
}
