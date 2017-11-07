/*
 * HttpServer.cpp
 *
 *  Created on: April 25, 2017
 *      Author: trungnd
 */


#include "HttpServer.h"
#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>

HttpServer::HttpServer()
{
    this->m_pServer = new QHttpServer(this);
    connect(this->m_pServer, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
            this, SLOT(onRecieved(QHttpRequest*, QHttpResponse*)));
}

HttpServer::~HttpServer()
{

}

QHttpServer* HttpServer::getServer()
{
    return this->m_pServer;
}

void HttpServer::setServer(QHttpServer* server)
{
    this->m_pServer = server;
}

void HttpServer::onRecieved(QHttpRequest *req, QHttpResponse *resp)
{
    this->m_pReq = req;
    this->m_pResp = resp;

    this->m_pResp->setHeader("Access-Control-Allow-Origin", "*");
    this->m_pResp->setHeader("Access-Control-Allow-Headers", "authtokenkey");
    this->m_pResp->setHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS, PUT, DELETE");
    this->m_pResp->setHeader("Content-Type", "application/json");

    if(req->method() == QHttpRequest::HTTP_GET)
    {
        emit handleRequest(this->m_pReq, this->m_pResp);
    }
    else if(req->method() == QHttpRequest::HTTP_POST)
    {
        this->m_pReq->storeBody();
        connect(req, SIGNAL(end()), this, SLOT(endData()));
    }
    else
    {
        this->m_pResp->writeHead(200);
        this->m_pResp->end("");
    }
}

void HttpServer::endData()
{
    emit handleRequest(this->m_pReq, this->m_pResp);
}

bool HttpServer::listen(quint16 port)
{
    return this->m_pServer->listen(QHostAddress::Any, port);
}

void HttpServer::response(QByteArray data, int messageCode)
{
    this->m_pResp->writeHead(messageCode);
    this->m_pResp->end(data);
}


