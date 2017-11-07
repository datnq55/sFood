#include "ScrController.h"
#include "QMLController.h"
#include "CommonStructs.h"

ScrController* ScrController::getInstance(SCREENTYPE_T type)
{
    if(FRONT_SCREEN == type){
        static ScrController instanceFront(FRONT_SCREEN);
        return &instanceFront;
    }
    else{
        static ScrController instanceRear(REAR_SCREEN);
        return &instanceRear;
    }
}

SCREENTYPE_T ScrController::getScrenType()
{
    return m_screen;
}

ScrController::ScrController(SCREENTYPE_T type) : m_screen(type)
{
}

ScrController::~ScrController()
{
}

void ScrController::qmlSendEvtKey(QVariant keyEvent, QVariant data)
{
    qDebug() << "keyEvent" << keyEvent << "data" << data;
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
    AppManager::getInstance(getScrenType())->addMsgToQueue(msgid, data);
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
    AppManager::getInstance(getScrenType())->reqChangeTopMsg(msgid, data);
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
    AppManager::getInstance(getScrenType())->reqInitStackHis(msgid, data);
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
    AppManager::getInstance(getScrenType())->reqInitScrCache(msgid, data);
}


void ScrController::registerScreen(QObject* scr)
{
    AppManager::getInstance(getScrenType())->addObjectFocus(scr);
}

void ScrController::unRegisterScreen(QObject* scr)
{
    AppManager::getInstance(getScrenType())->remObjectFocus(scr);
}

