/*
 * HttpServer.h
 *
 *  Created on: April 25, 2017
 *      Author: trungnd
 */


#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QObject>
#include "httpserver_global.h"
#include "qhttpserverfwd.h"
#include <qhttprequest.h>
#include <qhttpresponse.h>

class HTTPSERVERSHARED_EXPORT HttpServer : public QObject
{
    Q_OBJECT
private:
    QHttpServer* m_pServer;
    QHttpRequest* m_pReq;
    QHttpResponse* m_pResp;
public:
    HttpServer();
    virtual ~HttpServer();
    QHttpServer* getServer();
    void setServer(QHttpServer* server);
    bool listen(quint16 port);
    void response(QByteArray data, int messageCode);
signals:
    void handleRequest(QHttpRequest* req, QHttpResponse *resp);
public slots:
    void onRecieved(QHttpRequest* req, QHttpResponse* resp);
    void endData();
};

#endif // HTTPSERVER_H
