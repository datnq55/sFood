#include "AppManager.h"
#include "QMLController.h"
#include "OnsController.h"

AppManager* AppManager::getInstance(SCREENTYPE_T type)
{
    if(FRONT_SCREEN == type){
        static AppManager instanceFront(FRONT_SCREEN);
        return &instanceFront;
    }
    else{
        static AppManager instanceRear(REAR_SCREEN);
        return &instanceRear;
    }
}

AppManager::AppManager(SCREENTYPE_T type): m_screen(type)
{
    qRegisterMetaType<MSG_INF>("MSG_INF");
    qRegisterMetaType<SCREENTYPE_T>("SCREENTYPE_T");
}

AppManager::~AppManager()
{

}

SCREENTYPE_T AppManager::getScrenType()
{
    return m_screen;
}

// Add msg to stack and transition screen
bool AppManager::addMsgToQueue(uint msgID, QVariant data)
{
    qDebug() << "msgID" <<msgID<< "data" << data;
    return recieveMsgData(msgID, data);
}

// change top screen stack and transition screen
bool AppManager::reqChangeTopMsg(uint msgID, QVariant data)
{
    return recieveReqChangeTopMsg(msgID, data);
}

// Init stack history screen
bool AppManager::reqInitStackHis(uint msgID, QVariant data)
{
    return recieveReqInitStackHis(msgID, data);
}

// Clear screen cached
bool AppManager::reqInitScrCache(uint msgID, QVariant data)
{
    return recieveReqInitScrCache(msgID, data);
}

bool AppManager::recieveMsgData(uint msgID, QVariant data)
{
    // Check event is event transition or event operation
    bool retValue = false;
    uint evtID;
    if(!evtTranstion.empty())
    {
        // Is transition event
        if(evtTranstion.contains(msgID))
        {
            if(EVT_TRANS_BACK == msgID)
            {
                // Back to previous screen
                // Pop event in stackview history
                if(scrHistory.length() > 1){
                    scrHistory.pop();
                    evtID = scrHistory.top();
                    OnsController::getInstance(getScrenType())->deleteAllOSD();
                    retValue = QMLController::getInstance(getScrenType())->showScreen(evtTranstion[evtID].toForm);
                }
            }
            else{
                // Push event to stackview history
                scrHistory.push(msgID);
                if(NULL != evtTranstion[msgID].func){
                    evtTranstion[msgID].func(data, (int)getScrenType());
                }
                evtID = scrHistory.top();
                OnsController::getInstance(getScrenType())->deleteAllOSD();
                retValue = QMLController::getInstance(getScrenType())->showScreen(evtTranstion[evtID].toForm);
            }
        }
    }
    // Is operation event
    if(!evtOperation.empty())
    {
        if(evtOperation.contains(msgID))
        {
            // Call function callback
            if(NULL != evtOperation[msgID].func){
                evtOperation[msgID].func(data, (int)getScrenType());
            }
        }
    }

    MSG_INF msgInf;
    msgInf.eventID = msgID;
    msgInf.evtData = data;
    qDebug() << "emit screenTriggerHandled getScrenType()" << getScrenType() << "msgID" << msgID << "data" << data;
    emit screenTriggerHandled(getScrenType(), msgInf);

    return retValue;
}

bool AppManager::recieveReqChangeTopMsg(uint msgID, QVariant data)
{
    // Check event is event transition or event operation
    bool retValue = false;
    uint evtID;
    if(!evtTranstion.empty())
    {
        // Is transition event
        if(evtTranstion.contains(msgID))
        {
            // Remove top stack
            if(!scrHistory.isEmpty()){
                scrHistory.pop();
            }
            // Push event to stackview
            scrHistory.push(msgID);
        }
        else {
            scrHistory.push(msgID);
        }

        // Call back funtion trigger
        if(NULL != evtTranstion[msgID].func){
            evtTranstion[msgID].func(data, (int)getScrenType());
        }

        // Get screen of top
        evtID = scrHistory.top();

        // Show screen
        OnsController::getInstance(getScrenType())->deleteAllOSD();
        retValue = QMLController::getInstance(getScrenType())->showScreen(evtTranstion[evtID].toForm);

        MSG_INF msgInf;
        msgInf.eventID = msgID;
        msgInf.evtData = data;
        qDebug() << "emit screenTriggerHandled getScrenType()" << getScrenType() << "msgID" << msgID << "data" << data;
        emit screenTriggerHandled(getScrenType(), msgInf);
    }
    return retValue;
}

bool AppManager::recieveReqInitStackHis(uint msgID, QVariant data)
{
    bool retValue = false;
    if(!scrHistory.isEmpty()){
        QStack<uint>  current = scrHistory;
        scrHistory.clear();
        if(evtTranstion.contains(msgID))
        {
            // Push event to stackview
            scrHistory.push(msgID);

            // Get screen of top
            uint evtID = scrHistory.top();

            if(evtID != current.top()){
                // Show screen
                OnsController::getInstance(getScrenType())->deleteAllOSD();
                QMLController::getInstance(getScrenType())->showScreen(evtTranstion[evtID].toForm);

                MSG_INF msgInf;
                msgInf.eventID = msgID;
                msgInf.evtData = data;
                qDebug() << "emit screenTriggerHandled getScrenType()" << getScrenType() << "msgID" << msgID << "data" << data;
                emit screenTriggerHandled(getScrenType(), msgInf);
            }
        }
        current.clear();
        retValue = true;
    }
    return retValue;
}

bool AppManager::recieveReqInitScrCache(uint msgID, QVariant data)
{
    QMLController::getInstance(getScrenType())->initCachedScreen();
    return true;
}

void AppManager::reqShowOnscreen(uint OnsID)
{
    qDebug() << "OnsID " << OnsID;
    OnsController::getInstance(getScrenType())->showOnscreen(OnsID);
}

void AppManager::reqHideOnscreen(uint OnsID)
{
    qDebug() << "OnsID" << OnsID;
    OnsController::getInstance(getScrenType())->hideOnscreen(OnsID);
}

QStack<uint> AppManager::getOnscreenHistory()
{
    return OnsController::getInstance(getScrenType())->getListOnsShowing();
}

QStack<uint> AppManager::getScreenHistory(){
    return scrHistory;
}

void AppManager::reqEvtHardKeyHandler(int e, int data)
{
    emit AppManager::getInstance(getScrenType())->eventHardKeyHandler(e, data);
}

void AppManager::reqRefreshDisp(){
    if(scrHistory.length() > 0){
        int evtID = scrHistory.top();
        QMLController::getInstance(getScrenType())->showScreen(evtTranstion[evtID].toForm);
    }
}

void AppManager::addObjectFocus(QObject* obj)
{
    _fObj.insert(0, obj);
    for (QObject* obj: _fObj) {
        QObject::disconnect(AppManager::getInstance(getScrenType()), SIGNAL(eventHardKeyHandler(int, int)),
                            obj, SIGNAL(eventHardKeyHandler(int, int)));
        // Set property isOnTop = false
        obj->setProperty("isOnTop", false);
    }
    QObject::connect(AppManager::getInstance(getScrenType()), SIGNAL(eventHardKeyHandler(int, int)),
                     _fObj.first(), SIGNAL(eventHardKeyHandler(int, int)));
    // Set property isOnTop = true
    _fObj.first()->setProperty("isOnTop", true);
}

void AppManager::remObjectFocus(QObject* obj)
{
    _fObj.removeOne(obj);

    if(_fObj.count() > 0){
        for (QObject* obj: _fObj) {
            QObject::disconnect(AppManager::getInstance(getScrenType()), SIGNAL(eventHardKeyHandler(int, int)),
                                obj, SIGNAL(eventHardKeyHandler(int, int)));
            // Set property isOnTop = false
            obj->setProperty("isOnTop", false);
        }
        QObject::connect(AppManager::getInstance(getScrenType()), SIGNAL(eventHardKeyHandler(int, int)),
                         _fObj.first(), SIGNAL(eventHardKeyHandler(int, int)));
    }

    // Set property isOnTop = true
    _fObj.first()->setProperty("isOnTop", true);
}
