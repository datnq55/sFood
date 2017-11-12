#include "OnsController.h"
#include "TimerConnection.h"
#include "CommonStructs.h"

OnsController::OnsController()
{
    /* Private Onscreen table initialize */
    for(int onscnt = 0; onscnt < ONSCOUNT_MAX; onscnt++)
    {
        //Clear current onscreen
        CurrentshowOnsTbl[onscnt].OnscreenID = ONSID_BLANK;
        CurrentshowOnsTbl[onscnt].DspTimer = 0;
        CurrentshowOnsTbl[onscnt].OnsType = 0;
        CurrentshowOnsTbl[onscnt].QmlPath = "";
    }
}

OnsController* OnsController::getInstance()
{
        static OnsController instanceFront;
        return &instanceFront;
}

OnsController::~OnsController()
{

}

void OnsController::showOnscreen(unsigned int OnsID )
{
    int onscnt;
    if(getOnscreenInfo(OnsID))
    {
        //Stack a request onscreen to current onscreen table
        for(onscnt = 0; onscnt < ONSCOUNT_MAX; onscnt++)
        {
            if(CurrentshowOnsTbl[onscnt].OnscreenID == ONSID_BLANK )
            {
                //Stack new onscreen
                CurrentshowOnsTbl[onscnt].OnscreenID    = selectedOns.OnscreenID;
                CurrentshowOnsTbl[onscnt].DspTimer      = selectedOns.DspTimer;
                CurrentshowOnsTbl[onscnt].OnsType       = selectedOns.OnsType;
                CurrentshowOnsTbl[onscnt].QmlPath       = selectedOns.QmlPath;

                //Call to FormCtrl function
                QMLController::getInstance()->showOSD(CurrentshowOnsTbl);
                //Call to timer function
                if(CurrentshowOnsTbl[onscnt].DspTimer != ONSFOREVER)
                {
                    TimerConnection::getInstance()->reqShowOSDTimer(CurrentshowOnsTbl[onscnt].OnscreenID,CurrentshowOnsTbl[onscnt].DspTimer );
                }

                updateOnsHistory(OnsID, ONS_NOTICE::ONS_ADD_ONE);
                break;
            }
            else if(CurrentshowOnsTbl[onscnt].OnscreenID== OnsID) //Requested Onscreen has already displayed
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
            TimerConnection::getInstance()->reqHideOSDCountDown(CurrentshowOnsTbl[onscnt].OnscreenID);
        }
    }

    if(!onsHistory.isEmpty()){
        updateOnsHistory(0, ONS_NOTICE::ONS_REMOVE_ALL);
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
                TimerConnection::getInstance()->reqHideOSDCountDown(OnsID);
            }
            break;
        }
    }

    if(!onsHistory.isEmpty()){
        updateOnsHistory(OnsID, ONS_NOTICE::ONS_REMOVE_ONE);
    }
}

void OnsController::timeoutDeleteOnscreen(unsigned int OnsID)
{
    unsigned char onscnt;

    //Check a request onscreen to current onscreen table
    for(onscnt = 0; onscnt < ONSCOUNT_MAX; onscnt++)
    {
        //Delete requested onscreen is hit
        if(CurrentshowOnsTbl[onscnt].OnscreenID == OnsID)
        {
            //Clear current onscreen
            CurrentshowOnsTbl[onscnt].OnscreenID = ONSID_BLANK;
            CurrentshowOnsTbl[onscnt].DspTimer = 0;
            CurrentshowOnsTbl[onscnt].OnsType = 0;
            CurrentshowOnsTbl[onscnt].QmlPath = "";

            //Re-positioning Onscreen table
            setOnscreenTbl();

            //Call to FormCtrl function
            QMLController::getInstance()->showOSD(CurrentshowOnsTbl);

            if(!onsHistory.isEmpty()){
                updateOnsHistory(OnsID, ONS_NOTICE::ONS_REMOVE_ONE);
            }
        }
    }
}

QStack<uint> OnsController::getListOnsShowing()
{
    return onsHistory;
}

void OnsController::updateOnsHistory(uint onsID, ONS_NOTICE act)
{
    switch (act) {
    case ONS_NOTICE::ONS_ADD_ONE :
        onsHistory.push(onsID);
        break;
    case ONS_NOTICE::ONS_REMOVE_ONE :
        if(onsHistory.contains(onsID)){
            onsHistory.removeOne(onsID);
        }
        break;
    case ONS_NOTICE::ONS_REMOVE_ALL :
        if(!onsHistory.isEmpty()){
            onsHistory.clear();
        }
        break;
    default:
        break;
    }
    emit onsHistoryChanged();
}

bool OnsController::getOnscreenInfo( unsigned int OnsID)
{
    bool ret = false;
    for (size_t cnt = 0; cnt < _onsIDcnt; cnt++) {
        if(maptableOnsManager[cnt].OnscreenID == OnsID)
        {
            selectedOns = maptableOnsManager[cnt];
            ret = true;
            break;
        }
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
        if(CurrentshowOnsTbl[cnt].OnscreenID == ONSID_BLANK)
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

