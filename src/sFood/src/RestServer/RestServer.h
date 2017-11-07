/*
 * RestServer.h
 *
 *  Created on: May 05, 2017
 *      Author: trungnd
 */

#ifndef RESTSERVER_H
#define RESTSERVER_H

#include <HttpServer.h>
#include "Router.h"

class RestServer : public QObject
{
    Q_OBJECT
private:
    HttpServer* m_pServer;
    Router m_router;
public:
    RestServer();
    virtual ~ RestServer();
    void init(quint16 port);
public slots:
    void onRecieved(QHttpRequest* req, QHttpResponse* resp);
};

#endif // RESTSERVER_H
