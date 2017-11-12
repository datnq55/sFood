#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QVariant>
#include <QStack>
#include "../ScrController/CommonStructs.h"

struct MSG_INF{
    uint eventID;
    QString screenID;
    QVariant evtData;
    MSG_INF()
    {
        eventID = 0;
        screenID = QString();
        evtData = QVariant();
    }
};

class AppManager: public QObject
{
    Q_OBJECT
public:
    //Singleton model
    static AppManager *getInstance();
    AppManager(AppManager const&)      = delete;
    void operator=(AppManager const&)  = delete;
    // For HMI communication
    bool addMsgToQueue(uint msgID, QVariant data = QVariant());

    // change top screen stack
    bool reqChangeTopMsg(uint msgID, QVariant data = QVariant());

    // Init stack history screen
    bool reqInitStackHis(uint msgID, QVariant data = QVariant());
    void clearScrHistoryStack();

    // Clear screen cached
    bool reqInitScrCache(uint msgID, QVariant data = QVariant());

    // Show/Hide onscreen display
    void reqShowOnscreen(uint OnsID);
    void reqHideOnscreen(uint OnsID);
    QStack<uint> getOnscreenHistory();
    QStack<uint> getScreenHistory();
    // reset current screen (use in case change language)
    void reqRefreshDisp();
    void reqTrimComponentCached();
    // request handler hardkey event
    void reqEvtHardKeyHandler(int e, int data);
    void addObjectFocus(QObject* obj);
    void remObjectFocus(QObject* obj);
    // remove the top of screen stack (use in case back from quickguide to setup)
    void clearTopScreenStack();
private:
    AppManager();
    virtual ~AppManager();
    QList<QObject*> _fObj;
    QStack<uint> scrHistory;

signals:
    void eventHardKeyHandler(int e, int data);
    void screenTriggerHandled(MSG_INF m_inf);
    void onsHistoryChanged();
    void scrHistoryChanged();
private:
    bool recieveMsgData(uint msgID, QVariant data);
    bool recieveReqChangeTopMsg(uint msgID, QVariant data);
    bool recieveReqInitStackHis(uint msgID, QVariant data);
    bool recieveReqInitScrCache(uint msgID, QVariant data);
};

#endif // APPMANAGER_H
