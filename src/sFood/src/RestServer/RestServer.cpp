/*
 * RestServer.cpp
 *
 *  Created on: May 05, 2017
 *      Author: trungnd
 */

#include <QDebug>
#include "RestServer.h"
#include "Controller/BaseController.h"
#include "Controller/SensorController.h"
#include "ErrorCode.h"

RestServer::RestServer()
{
    this->m_router.storeMapping();
}

RestServer::~RestServer()
{

}

void RestServer::init(quint16 port)
{
    this->m_pServer = new HttpServer();
    connect(this->m_pServer, SIGNAL(handleRequest(QHttpRequest*, QHttpResponse*)),this, SLOT(onRecieved(QHttpRequest*, QHttpResponse*)));
    this->m_pServer->listen(port);
    qDebug() << "listening on port: " << port;
}

void RestServer::onRecieved(QHttpRequest* req, QHttpResponse* resp)
{
    bool isValid = false;
    BaseController* controller = nullptr;
    QList<ControllerInfo> mapping = this->m_router.getMapping();
    for(int i = 0; i < mapping.count(); i++)
    {
        QRegExp rex = mapping[i].getRegex();
        if(rex.indexIn(req->path()) != -1)
        {
            if(!mapping[i].getMethods().contains(req->method()))
            {
                break;
            }
            isValid = true;
            QMap<QString, QString> params;
            for(int j = 0; j < rex.captureCount(); j++)
            {
                params.insert(mapping[i].getParams()[j], rex.cap(j + 1));
            }
            int id = QMetaType::type(mapping[i].getName().toLatin1());
            if (id == 0)
            {
                break;
            }

            controller = static_cast<BaseController *>(QMetaType::create(id));
            QMetaObject::invokeMethod(controller, "init", Qt::DirectConnection,
                       Q_ARG(QHttpRequest*, req), Q_ARG(QHttpResponse*, resp), Q_ARG(StringVectorMap, params));
            QMetaObject::invokeMethod(controller, mapping[i].getMethods()[req->method()].toLatin1(), Qt::DirectConnection);
            QMetaType::destroy(id, controller);
            break;
        }
    }

    if(!isValid)
    {
        this->m_pServer->response("", ErrorCode::NOT_FOUND);
    }
}

