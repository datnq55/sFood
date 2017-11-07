#ifndef ROUTER_H
#define ROUTER_H

#include <QString>
#include <QMap>
#include <QList>
#include <qhttprequest.h>
#include "ControllerInfo.h"

#define URL_ROOT                        "/api"
#define URL_ADD_SENSOR                  "/api/sensor"
#define URL_DELETE_SENSOR               "/api/sensor/delete"
#define URL_WRITE                       "/api/write"
#define URL_WRITE_CONFIG                "/api/write/config"
#define URL_WRITE_BATCH                 "/api/writebatch"
#define URL_TRANSFER_CONFIG             "/api/config/import"
#define URL_SERVICE_READ_NODE           "/api/service/node/read/$driverId([0-9]+)"

class Router
{
private:
    QList<ControllerInfo> m_mapping;
public:
    Router();
    virtual ~Router();
    void storeMapping();
    void registerUrl(QString urlRex, QString controllerName, QMap<QHttpRequest::HttpMethod, QString> methods);
    void addControllerToMapping(ControllerInfo controller);
    QList<ControllerInfo> getMapping();
};

#endif // ROUTER_H
