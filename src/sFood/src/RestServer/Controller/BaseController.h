/*
 * BaseController.h
 *
 *  Created on: May 05, 2017
 *      Author: trungnd
 */

#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include <QObject>
#include <QByteArray>
#include <HttpServer.h>

typedef QMap<QString, QString> StringVectorMap;

class BaseController : public QObject
{
    Q_OBJECT
public:
    QHttpRequest* m_pReq;
    QHttpResponse* m_pResp;
    QMap<QString, QString> m_params;

public:
    BaseController();
    virtual ~BaseController();
    Q_INVOKABLE virtual void init(QHttpRequest* req, QHttpResponse* resp, StringVectorMap params);
    void response(QByteArray data, int messageCode);
};

#endif // BASECONTROLLER_H
