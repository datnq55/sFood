#include "AppManager.h"
#include "../QMLController/QMLController.h"
#include "../ScrController/OnsController.h"
//#include "AppHomeModel.h"
//#include "View/AppHome_ScreenDefs.h"

AppManager* AppManager::getInstance()
{
    static AppManager instanceFront;
    return &instanceFront;
}

AppManager::AppManager()
{
    qRegisterMetaType<MSG_INF>("MSG_INF");
    QObject::connect(OnsController::getInstance(), SIGNAL(onsHistoryChanged()), this, SIGNAL(onsHistoryChanged()));
    QObject::connect(QMLController::getInstance(), SIGNAL(scrHistoryChanged()), this, SIGNAL(scrHistoryChanged()));
}

AppManager::~AppManager()
{

}

// Add msg to stack and transition screen
bool AppManager::addMsgToQueue(uint msgID, QVariant data)
{
    return recieveMsgData(msgID, data);
}

// change top screen stack and transition screen
bool AppManager::reqChangeTopMsg(uint msgID, QVariant data)
{
    return recieveReqChangeTopMsg(msgID, data);
}

// Clears the screen history stack
void AppManager::clearScrHistoryStack()
{
    scrHistory.clear();
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
                    qDebug() << "FPT-Debug: pop to history Qstack, total = " << scrHistory.length();
                    evtID = scrHistory.top();
                    OnsController::getInstance()->deleteAllOSD();
                    retValue = QMLController::getInstance()->showScreen(evtTranstion[evtID].toForm);
                }
            }
            else{
                // Push event to stackview history
                scrHistory.push(msgID);
                qDebug() << "FPT-Debug: Push to history Qstack" << scrHistory.length();
                if(NULL != evtTranstion[msgID].func){
                    evtTranstion[msgID].func(data);
                }
                evtID = scrHistory.top();
                OnsController::getInstance()->deleteAllOSD();
                retValue = QMLController::getInstance()->showScreen(evtTranstion[evtID].toForm);
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
                evtOperation[msgID].func(data);
            }
        }
    }

    MSG_INF msgInf;
    msgInf.eventID = msgID;
    msgInf.evtData = data;
    emit screenTriggerHandled(msgInf);

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
            qDebug() << "FPT-Debug: Push to history Qstack" << scrHistory.length();

        }
        else {
            scrHistory.push(msgID);
            qDebug() << "FPT-Debug: Push to history Qstack" << scrHistory.length();

        }

        // Call back funtion trigger
        if(NULL != evtTranstion[msgID].func){
            evtTranstion[msgID].func(data);
        }

        // Get screen of top
        evtID = scrHistory.top();

        // Show screen
        OnsController::getInstance()->deleteAllOSD();
        retValue = QMLController::getInstance()->showScreen(evtTranstion[evtID].toForm);

        MSG_INF msgInf;
        msgInf.eventID = msgID;
        msgInf.evtData = data;
        emit screenTriggerHandled(msgInf);
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
            qDebug() << "FPT-Debug: Push to history Qstack" << scrHistory.length();
            scrHistory.push(msgID);

            // Get screen of top
            uint evtID = scrHistory.top();

            if(evtID != current.top()){
                // Show screen
                OnsController::getInstance()->deleteAllOSD();
                QMLController::getInstance()->showScreen(evtTranstion[evtID].toForm);

                MSG_INF msgInf;
                msgInf.eventID = msgID;
                msgInf.evtData = data;
                emit screenTriggerHandled(msgInf);
            }
        }
        current.clear();
        retValue = true;
    }
    return retValue;
}

bool AppManager::recieveReqInitScrCache(uint msgID, QVariant data)
{
    Q_UNUSED(msgID)
    Q_UNUSED(data)
    QMLController::getInstance()->initCachedScreen();
    return true;
}

void AppManager::reqShowOnscreen(uint OnsID)
{
    OnsController::getInstance()->showOnscreen(OnsID);
//    if(OnsID != ONSID_HOME_OPTION_MENU)
//    {
//        AppHomeModel::instance()->setIsOnScrShowing(true);
//    }
}

void AppManager::reqHideOnscreen(uint OnsID)
{
    OnsController::getInstance()->hideOnscreen(OnsID);
//    if(OnsID != ONSID_HOME_OPTION_MENU)
//    {
//        AppHomeModel::instance()->setIsOnScrShowing(false);
//    }
}

QStack<uint> AppManager::getOnscreenHistory()
{
    return OnsController::getInstance()->getListOnsShowing();
}

QStack<uint> AppManager::getScreenHistory(){
    return scrHistory;
}

void AppManager::reqEvtHardKeyHandler(int e, int data)
{
    emit AppManager::getInstance()->eventHardKeyHandler(e, data);
}

void AppManager::reqRefreshDisp(){
    if(scrHistory.length() > 0){
        int evtID = scrHistory.top();
        QMLController::getInstance()->showScreen(evtTranstion[evtID].toForm);
    }

    QList<uint> currentOns = getOnscreenHistory().toList();
    if(!currentOns.isEmpty())
    {
        OnsController::getInstance()->deleteAllOSD();
        for (int i = 0; i < currentOns.count(); i++) {
            reqShowOnscreen(currentOns[i]);
        }
    }
}

void AppManager::reqTrimComponentCached()
{
    QMLController::getInstance()->reqTrimComponentCached();
}

void AppManager::addObjectFocus(QObject* obj)
{
    _fObj.insert(0, obj);
    for (QObject* obj: _fObj) {
        QObject::disconnect(AppManager::getInstance(), SIGNAL(eventHardKeyHandler(int, int)),
                            obj, SIGNAL(eventHardKeyHandler(int, int)));
        // Set property isOnTop = false
        obj->setProperty("isOnTop", false);
    }
    QObject::connect(AppManager::getInstance(), SIGNAL(eventHardKeyHandler(int, int)),
                     _fObj.first(), SIGNAL(eventHardKeyHandler(int, int)));

    // Set property isOnTop = true
    _fObj.first()->setProperty("isOnTop", true);
}

void AppManager::remObjectFocus(QObject* obj)
{
    _fObj.removeOne(obj);

    if(_fObj.count() > 0){
        for (QObject* obj: _fObj) {
            QObject::disconnect(AppManager::getInstance(), SIGNAL(eventHardKeyHandler(int, int)),
                                obj, SIGNAL(eventHardKeyHandler(int, int)));

            // Set property isOnTop = false
            obj->setProperty("isOnTop", false);
        }
        QObject::connect(AppManager::getInstance(), SIGNAL(eventHardKeyHandler(int, int)),
                         _fObj.first(), SIGNAL(eventHardKeyHandler(int, int)));

        // Set property isOnTop = true
        _fObj.first()->setProperty("isOnTop", true);
    }
}

void AppManager::clearTopScreenStack()
{
    if( !scrHistory.isEmpty() )
    {
        scrHistory.pop();
    }
}
