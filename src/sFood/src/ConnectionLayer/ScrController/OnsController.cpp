#include "OnsController.h"
#include "TimerConnection.h"
#include "CommonStructs.h"
#include "Logger.h"

OnsController::OnsController(SCREENTYPE_T type): m_screen(type)
{
    unsigned char onscnt;

    /* Private Onscreen table initialize */
    for(onscnt = 0; onscnt < ONSCOUNT_MAX; onscnt++)
    {
        //Clear current onscreen
        CurrentshowOnsTbl[onscnt].OnscreenID = ONSID_MAX;
        CurrentshowOnsTbl[onscnt].DspTimer = 0;
        CurrentshowOnsTbl[onscnt].OnsType = 0;
        CurrentshowOnsTbl[onscnt].QmlPath = "";
    }
}

OnsController* OnsController::getInstance(SCREENTYPE_T type)
{
    if(FRONT_SCREEN == type){
        static OnsController instanceFront(FRONT_SCREEN);
        return &instanceFront;
    }
    else{
        static OnsController instanceRear(REAR_SCREEN);
        return &instanceRear;
    }
}

OnsController::~OnsController()
{
}


SCREENTYPE_T OnsController::getScrenType()
{
    return m_screen;
}

void OnsController::showOnscreen(unsigned int OnsID )
{
    int onscnt;
    if(getOnscreenInfo(OnsID))
    {
        //Stack a request onscreen to current onscreen table
        for(onscnt = 0; onscnt < ONSCOUNT_MAX; onscnt++)
        {
            if(CurrentshowOnsTbl[onscnt].OnscreenID == ONSID_MAX )
            {
                //Stack new onscreen
                CurrentshowOnsTbl[onscnt].OnscreenID    = selectedOns.OnscreenID;
                CurrentshowOnsTbl[onscnt].DspTimer      = selectedOns.DspTimer;
                CurrentshowOnsTbl[onscnt].OnsType       = selectedOns.OnsType;
                CurrentshowOnsTbl[onscnt].QmlPath       = selectedOns.QmlPath;

                //Call to FormCtrl function
                QMLController::getInstance(getScrenType())->showOSD(CurrentshowOnsTbl);
                //Call to timer function
                if(CurrentshowOnsTbl[onscnt].DspTimer != ONSFOREVER)
                {
                    TimerConnection::getInstance(getScrenType())->reqShowOSDTimer(CurrentshowOnsTbl[onscnt].OnscreenID,CurrentshowOnsTbl[onscnt].DspTimer );
                }

                onsHistory.push(OnsID);
                break;
            }
            //Requested Onscreen has already displayed
            else if(CurrentshowOnsTbl[onscnt].OnscreenID== OnsID)
            {
                break;
            }
        }
    }
}

void OnsController::deleteAllOSD()
{
    for(unsigned char onscnt = 0; onscnt < ONSCOUNT_MAX; onscnt++)
    {
        if(CurrentshowOnsTbl[onscnt].DspTimer == ONSFOREVER)
        {
            timeoutDeleteOnscreen(CurrentshowOnsTbl[onscnt].OnscreenID);
        }
        else
        {
            TimerConnection::getInstance(getScrenType())->reqHideOSDCountDown(CurrentshowOnsTbl[onscnt].OnscreenID);
        }
    }

    if(!onsHistory.isEmpty()){
        onsHistory.clear();
    }
}

void OnsController::hideOnscreen( unsigned int OnsID  )
{
    //Check a request onscreen to current onscreen table
    for(unsigned char onscnt = 0; onscnt < ONSCOUNT_MAX; onscnt++)
    {
        //Delete requested onscreen is hit
        if(CurrentshowOnsTbl[onscnt].OnscreenID == OnsID )
        {
            if(CurrentshowOnsTbl[onscnt].DspTimer == ONSFOREVER)
            {
                timeoutDeleteOnscreen(OnsID);
            }
            else
            {
                TimerConnection::getInstance(getScrenType())->reqHideOSDCountDown(OnsID);
            }
            break;
        }
    }

    if(!onsHistory.isEmpty()){
        onsHistory.removeOne(OnsID);
    }
}

void OnsController::timeoutDeleteOnscreen(unsigned int OnsID)
{
    //DLT_HIGH << "OnsID " << OnsID;
    unsigned char onscnt;

    //Check a request onscreen to current onscreen table
    for(onscnt = 0; onscnt < ONSCOUNT_MAX; onscnt++)
    {
        //Delete requested onscreen is hit
        if(CurrentshowOnsTbl[onscnt].OnscreenID == OnsID)
        {
            //Clear current onscreen
            CurrentshowOnsTbl[onscnt].OnscreenID = ONSID_MAX;
            CurrentshowOnsTbl[onscnt].DspTimer = 0;
            CurrentshowOnsTbl[onscnt].OnsType = 0;
            CurrentshowOnsTbl[onscnt].QmlPath = "";

            //Re-positioning Onscreen table
            setOnscreenTbl();

            //Call to FormCtrl function
            QMLController::getInstance(getScrenType())->showOSD(CurrentshowOnsTbl);

            if(!onsHistory.isEmpty()){
                onsHistory.removeOne(OnsID);
            }
        }
    }
}

QStack<uint> OnsController::getListOnsShowing()
{
    return onsHistory;
}

bool OnsController::getOnscreenInfo( unsigned int OnsID)
{
    bool ret = false;
    int cnt = 0;

    while (maptableOnsManager[cnt].OnscreenID != ONSID_MAX)
    {

        /* Onscreen ID matched */
        if(maptableOnsManager[cnt].OnscreenID == OnsID)
        {
            selectedOns = maptableOnsManager[cnt];
            ret = true;
            break;
        }
        cnt++;
    }

    return ret;
}


void OnsController::setOnscreenTbl()
{
    unsigned char cnt;
    unsigned char sftcnt;

    for(cnt = 0; cnt < ONSCOUNT_MAX ; cnt++ )
    {
        //Find blank data
        if(CurrentshowOnsTbl[cnt].OnscreenID == ONSID_MAX)
        {
            //Shift Onscreen data up to max size
            for(sftcnt = cnt; sftcnt < ONSCOUNT_MAX-1; sftcnt++)
            {
                //Shift data
                CurrentshowOnsTbl[sftcnt].OnscreenID = CurrentshowOnsTbl[sftcnt+1].OnscreenID;
                CurrentshowOnsTbl[sftcnt].OnsType = CurrentshowOnsTbl[sftcnt+1].OnsType;
                CurrentshowOnsTbl[sftcnt].DspTimer = CurrentshowOnsTbl[sftcnt+1].DspTimer;
                CurrentshowOnsTbl[sftcnt].QmlPath = CurrentshowOnsTbl[sftcnt+1].QmlPath;
            }
        }

    }

}

