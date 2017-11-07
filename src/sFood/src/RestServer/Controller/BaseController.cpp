/*
 * BaseController.cpp
 *
 *  Created on: May 05, 2017
 *      Author: trungnd
 */

#include "BaseController.h"

BaseController::BaseController()
{

}

BaseController::~BaseController()
{
    Q_UNUSED(this->m_pReq);
    Q_UNUSED(this->m_pResp);
}

void BaseController::response(QByteArray data, int messageCode)
{
    this->m_pResp->writeHead(messageCode);
    this->m_pResp->end(data);
}

void BaseController::init(QHttpRequest* req, QHttpResponse* resp, StringVectorMap params)
{
    this->m_pReq = req;
    this->m_pResp = resp;
    this->m_params = params;
}
