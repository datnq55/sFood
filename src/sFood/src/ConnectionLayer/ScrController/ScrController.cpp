#include "ScrController.h"
#include "../QMLController/QMLController.h"
#include "CommonStructs.h"

ScrController* ScrController::getInstance()
{
        static ScrController instanceFront;
        return &instanceFront;
}

ScrController::ScrController()
{
}

ScrController::~ScrController()
{
}

void ScrController::qmlSendEvtKey(QVariant keyEvent, QVariant data)
{
    p_keyEvent = keyEvent;
    uint msgid = 0;

    /* Check key Event */
    if(!keyEvent.isNull())
    {
        // convert keyEvent to uint32 type
        msgid = keyEvent.toInt();
    }
    else
    {
        //Nothing
    }
    AppManager::getInstance()->addMsgToQueue(msgid, data);
}

void ScrController::qmlChangeTopMsg(QVariant keyEvent, QVariant data)
{
    p_keyEvent = keyEvent;
    uint msgid = 0;

    /* Check key Event */
    if(!keyEvent.isNull())
    {
        // convert keyEvent to uint32 type
        msgid = keyEvent.toInt();
    }
    else
    {
        //Nothing
    }
    AppManager::getInstance()->reqChangeTopMsg(msgid, data);
}

void ScrController::qmlInitStackHis(QVariant keyEvent, QVariant data)
{
    p_keyEvent = keyEvent;
    uint msgid = 0;

    /* Check key Event */
    if(!keyEvent.isNull())
    {
        // convert keyEvent to uint32 type
        msgid = keyEvent.toInt();
    }
    else
    {
        //Nothing
    }
    AppManager::getInstance()->reqInitStackHis(msgid, data);
}

void ScrController::qmlInitScrCache(QVariant keyEvent, QVariant data)
{
    p_keyEvent = keyEvent;
    uint msgid = 0;

    /* Check key Event */
    if(!keyEvent.isNull())
    {
        // convert keyEvent to uint32 type
        msgid = keyEvent.toInt();
    }
    else
    {
        //Nothing
    }
    AppManager::getInstance()->reqInitScrCache(msgid, data);
}

void ScrController::reqTrimComponentCached()
{
    AppManager::getInstance()->reqTrimComponentCached();
}


void ScrController::registerScreen(QObject* scr)
{
    AppManager::getInstance()->addObjectFocus(scr);
}

void ScrController::unRegisterScreen(QObject* scr)
{
    AppManager::getInstance()->remObjectFocus(scr);
}

