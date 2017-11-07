#include "ControllerInfo.h"

ControllerInfo::ControllerInfo()
{

}

ControllerInfo::~ControllerInfo()
{

}

QMap<int, QString> ControllerInfo::getParams()
{
    return this->m_params;
}

void ControllerInfo::setParams(QMap<int, QString> params)
{
    this->m_params = params;
}

QMap<QHttpRequest::HttpMethod, QString> ControllerInfo::getMethods()
{
    return this->m_methods;
}

void ControllerInfo::setMethods(QMap<QHttpRequest::HttpMethod, QString> methods)
{
    this->m_methods = methods;
}

QString ControllerInfo::getName()
{
    return this->m_sName;
}

void ControllerInfo::setName(QString name)
{
    this->m_sName = name;
}

QRegExp ControllerInfo::getRegex()
{
    return this->m_regex;
}

void ControllerInfo::setRegex(QRegExp regex)
{
    this->m_regex = regex;
}
