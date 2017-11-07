
#include <QMetaType>
#include <QDebug>
#include <QRegExp>
#include "Router.h"
#include "Controller/SensorController.h"

#define SENSOR_CONTROLLER   "SensorController"

Router::Router()
{

}

Router::~Router()
{

}

void Router::addControllerToMapping(ControllerInfo controller)
{
    this->m_mapping.append(controller);
}

void Router::registerUrl(QString urlRex, QString controllerName, QMap<QHttpRequest::HttpMethod, QString> methods)
{
    QStringList parts = urlRex.split("/");
    QMap<int, QString> params;
    int j = 0;
    for(int i = 0; i < parts.count(); i++)
    {
        QString part = parts.at(i);
        QString tmp;
        if(part.startsWith('$'))
        {
            QString expr = "([^/]+)";
            int index = part.indexOf("(");
            if(index != -1)
            {
                tmp = part.left(index).remove(0,1);
                expr = part.mid(index);
            }
            params.insert(j, tmp);
            parts[i] = expr;
            j++;
        }
    }

    QString regexPattern = "^" + parts.join('/') + "$";
    QRegExp regex;
    regex.setPattern(regexPattern);
    ControllerInfo controller;
    controller.setName(controllerName);
    controller.setRegex(regex);
    controller.setParams(params);
    controller.setMethods(methods);

    this->addControllerToMapping(controller);
}

QList<ControllerInfo> Router::getMapping()
{
    return this->m_mapping;
}

void Router::storeMapping()
{
    // Register controller
    qRegisterMetaType<SensorController>(SENSOR_CONTROLLER);

    // Mapping url to controller
    this->registerUrl(URL_ADD_SENSOR, SENSOR_CONTROLLER,
                      QMap<QHttpRequest::HttpMethod, QString>{{QHttpRequest::HttpMethod::HTTP_POST, "addSensor"}});

    this->registerUrl(URL_DELETE_SENSOR, SENSOR_CONTROLLER,
                      QMap<QHttpRequest::HttpMethod, QString>{{QHttpRequest::HttpMethod::HTTP_POST, "deleteSensor"}});

    this->registerUrl(URL_WRITE, SENSOR_CONTROLLER,
                      QMap<QHttpRequest::HttpMethod, QString>{{QHttpRequest::HttpMethod::HTTP_POST, "write"}});

    this->registerUrl(URL_WRITE_BATCH, SENSOR_CONTROLLER,
        QMap<QHttpRequest::HttpMethod, QString>{{QHttpRequest::HttpMethod::HTTP_POST, "writeBatch"}});

    this->registerUrl(URL_WRITE_CONFIG, SENSOR_CONTROLLER,
        QMap<QHttpRequest::HttpMethod, QString>{{QHttpRequest::HttpMethod::HTTP_POST, "writeConfig"}});

    this->registerUrl(URL_TRANSFER_CONFIG, SENSOR_CONTROLLER,
                          QMap<QHttpRequest::HttpMethod, QString>{{QHttpRequest::HttpMethod::HTTP_POST, "importConfig"}});

    this->registerUrl(URL_SERVICE_READ_NODE, SENSOR_CONTROLLER,
                      QMap<QHttpRequest::HttpMethod, QString>{{QHttpRequest::HttpMethod::HTTP_POST, "handleSpecificPostRequest"}});

}
