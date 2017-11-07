#ifndef CONTROLLERINFO_H
#define CONTROLLERINFO_H

#include <qhttprequest.h>
#include <QString>
#include <QMap>
#include <QRegExp>

class ControllerInfo
{
private:
    QMap<int, QString> m_params;
    QMap<QHttpRequest::HttpMethod, QString> m_methods;
    QString m_sName;
    QRegExp m_regex;
public:
    ControllerInfo();
    virtual ~ControllerInfo();
    QMap<int, QString> getParams();
    void setParams(QMap<int, QString> params);
    QMap<QHttpRequest::HttpMethod, QString> getMethods();
    void setMethods(QMap<QHttpRequest::HttpMethod, QString> methods);
    QString getName();
    void setName(QString name);
    QRegExp getRegex();
    void setRegex(QRegExp regex);
};

#endif // CONTROLLERINFO_H
