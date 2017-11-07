#include "HttpClient.h"


HttpClient* HttpClient::instance = nullptr;

HttpClient::HttpClient()
{
//    mgr = new QNetworkAccessManager();
}

HttpClient* HttpClient::getInstance()
{
    if(instance == nullptr)
    {
        instance = new HttpClient();
    }
    return instance;
}

bool HttpClient::send(QString url, QByteArray dataSender, HTTP_METHOD method, QByteArray &dataRecieved, int &messageCode, quint64 timeout)
{
    QNetworkAccessManager* mgr = new QNetworkAccessManager();
    qDebug() << "HttpClient::getInstance()->send";
    messageCode = 0;
    // create custom temporary event loop on stack
    QTimer timer;
    QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()" or timeout reach
    QObject::connect(mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QObject::connect(&timer, SIGNAL(timeout()), &eventLoop, SLOT(quit()));

    timer.setSingleShot(true);
    timer.start(timeout);

    // the HTTP request
    QNetworkRequest req;
    req.setRawHeader("content-type", "application/json");
    req.setUrl(QUrl(url));
    QNetworkReply *reply = nullptr;
    switch (method)
    {
    case GET:
        reply = mgr->get(req);
        break;
    case POST:
        reply = mgr->post(req, dataSender);
        break;
    case PUT:
        reply = mgr->put(req, dataSender);
        break;
    case DELETE:
        reply = mgr->deleteResource(req);
        break;
    default:
        break;
    }
    // reset timer when uploading/downloading a large data packet
    QObject::connect(reply, SIGNAL(uploadProgress(qint64,qint64)), &timer, SLOT(start()));
    QObject::connect(reply, SIGNAL(downloadProgress(qint64,qint64)), &timer, SLOT(start()));

    eventLoop.exec(); // blocks stack until "finished()" has been called

    QObject::disconnect(reply, SIGNAL(uploadProgress(qint64,qint64)), &timer, SLOT(start()));
    QObject::disconnect(reply, SIGNAL(downloadProgress(qint64,qint64)), &timer, SLOT(start()));

    if(timer.isActive())
    {
        timer.stop();
        if (reply->error() == QNetworkReply::NoError)
        {
            //success
            qDebug() << "Success";
            messageCode = 200;
            dataRecieved = reply->readAll();
            delete reply;
            return true;
        }
        else
        {
            //failure
            qDebug() << "Failure" << reply->errorString();
            dataRecieved = reply->errorString().toUtf8();
            delete reply;
            return false;
        }
    }
    else
    {
        qDebug() << "Request timeout";
        QObject::disconnect(mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
//        reply->abort();
        return false;
    }
    QObject::disconnect(mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
//    reply->abort();
    qDebug() << "Request timeout";
    reply->deleteLater();
    mgr->deleteLater();
    return false;
}
