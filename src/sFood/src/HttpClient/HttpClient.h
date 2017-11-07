#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "httpclient_global.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QTimer>
#include <QThread>

enum HTTP_METHOD
{
    GET = 0,
    POST = 1,
    PUT = 2,
    DELETE = 3
};

class HTTPCLIENTSHARED_EXPORT HttpClient
{
    static HttpClient* instance;
private:
    HttpClient();
public:
    static HttpClient* getInstance();
    bool send(QString url, QByteArray dataSender, HTTP_METHOD method, QByteArray& dataRecieved, int &messageCode, quint64 timeout = 1000);
};

#endif // HTTPCLIENT_H
