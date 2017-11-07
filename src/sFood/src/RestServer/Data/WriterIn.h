#ifndef WRITERIN_H
#define WRITERIN_H


#include "../Model/BaseModel.h"

class WriterIn : public BaseModel
{
public:
    QString driverType;
    quint16 componentId;
    QString name;
    QString value;
    QString ip;
    int port;

protected:
    QJsonObject generateToJson() const;

public:
    virtual bool generatedFromJson(const QString &json);
    virtual QString generateToJsonStr() const;
};

#endif // WRITERIN_H
