#include "WriterIn.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

#define DRIVER_TYPE             "driverType"
#define COMPONENT_ID            "componentId"
#define NAME                    "name"
#define VALUE                   "value"
#define IP                      "ip"
#define PORT                    "port"

QJsonObject WriterIn::generateToJson() const
{
    QJsonObject jObj;
    jObj.insert(DRIVER_TYPE, this->driverType);
    jObj.insert(COMPONENT_ID, this->componentId);
    jObj.insert(NAME, this->name);
    jObj.insert(VALUE, this->value);
    jObj.insert(IP, this->ip);
    jObj.insert(PORT, this->port);

    return jObj;
}

bool WriterIn::generatedFromJson(const QString& json)
{
    bool ok;
    QJsonObject jObj = BaseModel::validateJson(json, ok);
    if( !ok )
    {
        return false;
    }

    SET_PROPERTY(driverType, String, DRIVER_TYPE, jObj)
    SET_PROPERTY(componentId, Int, COMPONENT_ID, jObj)
    SET_PROPERTY(name, String, NAME, jObj)
    SET_PROPERTY(value, String, VALUE, jObj)
    SET_PROPERTY(ip, String, IP, jObj)
    SET_PROPERTY(port, Int, PORT, jObj)

    return true;
}

QString WriterIn::generateToJsonStr() const
{
    QJsonObject jObj = generateToJson();
    QJsonDocument jDoc(jObj);
    return QString(jDoc.toJson(QJsonDocument::Compact));
}
