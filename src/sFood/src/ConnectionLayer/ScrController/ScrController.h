#ifndef ScrController_H
#define ScrController_H

#include <QObject>
#include <QVariant>
#include "AppManager.h"
#include <QStack>

class ScrController : public QObject
{
    Q_OBJECT

public:
    //Singleton model    
    static ScrController* getInstance(SCREENTYPE_T type);
    ScrController(ScrController const&)   = delete;
    void operator=(ScrController const&)  = delete;

    Q_INVOKABLE void qmlSendEvtKey(QVariant keyEvent, QVariant data = QVariant());
    Q_INVOKABLE void qmlChangeTopMsg(QVariant keyEvent, QVariant data = QVariant());
    Q_INVOKABLE void qmlInitStackHis(QVariant keyEvent, QVariant data = QVariant());
    Q_INVOKABLE void qmlInitScrCache(QVariant keyEvent, QVariant data = QVariant());

    Q_INVOKABLE void registerScreen(QObject* scr);
    Q_INVOKABLE void unRegisterScreen(QObject* scr);
private:
    explicit ScrController(SCREENTYPE_T type);
    virtual ~ScrController();
    QVariant p_keyEvent;      //Key event from QML data
    SCREENTYPE_T getScrenType();
    SCREENTYPE_T m_screen;
};
#endif // ScrController_H
