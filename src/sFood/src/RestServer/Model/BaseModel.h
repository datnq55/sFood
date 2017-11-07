#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QVariant>
#include <QDebug>

#define SET_PROPERTY(name, Type, key, jsonSource) \
    if( jsonSource.contains(key) ) \
    { \
        name = jsonSource[key].to##Type(); \
    }

class BaseModel
{
public:
    virtual ~BaseModel() {}
    static QJsonObject validateJson(const QString& json, bool& ok);
    virtual bool generatedFromJson(const QString& json) = 0;
    virtual QString generateToJsonStr() const = 0;
};

#endif // BASEMODEL_H
