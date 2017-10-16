#include "TimerConnection.h"
#include "Logger.h"

TimerConnection* TimerConnection::getInstance(SCREENTYPE_T type)
{
    if(FRONT_SCREEN == type){
        static TimerConnection instanceFront(FRONT_SCREEN);
        return &instanceFront;
    }
    else{
        static TimerConnection instanceRear(REAR_SCREEN);
        return &instanceRear;
    }
}

TimerConnection::TimerConnection(SCREENTYPE_T type) : m_screen(type)
{
    timSetPos = 0;
    onsTimSetPos = 0;

    /* Private Onscreen table initialize */
    for(unsigned int timcnt = 0; timcnt < ONSCOUNT_MAX; timcnt++)
    {
        mng_OnsTimer[timcnt].onsID = ONSID_MAX;
        mng_OnsTimer[timcnt].timer_param = 0;
    }

}

TimerConnection::~TimerConnection()
{
}

SCREENTYPE_T TimerConnection::getScrenType()
{
    return m_screen;
}

void TimerConnection::reqShowOSDTimer(unsigned int onsid, unsigned int param)
{
    /* Set one-shot timer request for Onscreen management       */
    unsigned char timcnt;
    bool  settimer = true;

    /* Search Onscreen timer table */
    for(timcnt = 0; timcnt < ONS_DELTIMER_MAX; timcnt++)
    {
        /* Check whether same timer already registered or not */
        if(mng_OnsTimer[timcnt].onsID == onsid)
        {
            /* If same timer already registered, requests are ignore */
            settimer = false;
            break;
        }
    }

    /* New Onscreen timer  */
    if(settimer == true)
    {
        //To register timer parameter to timer management table
        mng_OnsTimer[onsTimSetPos].onsID = onsid;
        mng_OnsTimer[onsTimSetPos].timer_param = param;

        //Timer new
        mng_OnsTimer[onsTimSetPos].onstimtbl = new QTimerWrap((int)getScrenType(), onsid);
        //SIGNAL-SLOT connection
        QObject::connect(mng_OnsTimer[onsTimSetPos].onstimtbl , SIGNAL(timeout()),mng_OnsTimer[onsTimSetPos].onstimtbl, SLOT(timeout_exec()));
        //Timer start
        mng_OnsTimer[onsTimSetPos].onstimtbl->start(mng_OnsTimer[onsTimSetPos].timer_param);

        //Increment timer count
        onsTimSetPos++;
    }
}

void TimerConnection::reqHideOSDCountDown(unsigned int onsid)
{
    DLT_HIGH << "onsid  " << onsid;
    /* Delete one-shot timer request for Onscreen management    */
    unsigned char timcnt;
    bool  deltimer = false;

    /* Search timer table */
    for(timcnt = 0; timcnt < TIMER_SET_MAX; timcnt++)
    {
        /* Check whether same timer already registered or not */
        if(mng_OnsTimer[timcnt].onsID == onsid){
            /* If same timer already registered, requests are available */
            deltimer = true;
            break;
        }
    }

    /* Delete timer  */
    if(deltimer == true)
    {
        OnsController::getInstance(getScrenType())->timeoutDeleteOnscreen(mng_OnsTimer[timcnt].onsID);

        //To delete timer parameter to timer management table
        mng_OnsTimer[timcnt].onsID = ONSID_MAX;
        mng_OnsTimer[timcnt].timer_param = 0;

        //Timer stop (make sure)
        mng_OnsTimer[timcnt].onstimtbl->stop();
        //Timer delete
        delete mng_OnsTimer[timcnt].onstimtbl;

        //re-positioning timer table
        setOnsTimerTbl();
    }
    else
    {
    }
}

void TimerConnection::timout_OnsTimer(unsigned int onsid)
{
    //Timer clear
    reqHideOSDCountDown(onsid);

}

void TimerConnection::setOnsTimerTbl(void)
{
    unsigned char cnt;
    unsigned char sftcnt;

    for(cnt = 0; cnt < onsTimSetPos ; cnt++ )
    {
        //Find blank data
        if(mng_OnsTimer[cnt].onsID == ONSID_MAX)
        {
            //Shift timer data up to max size
            for(sftcnt = cnt; sftcnt < onsTimSetPos; sftcnt++)
            {
                //Shift data
                mng_OnsTimer[sftcnt].onsID = mng_OnsTimer[sftcnt+1].onsID;              //Onscreen ID
                mng_OnsTimer[sftcnt].timer_param = mng_OnsTimer[sftcnt+1].timer_param;  //Parameter
                mng_OnsTimer[sftcnt].onstimtbl = mng_OnsTimer[sftcnt+1].onstimtbl;        //QTimer pointer
            }
            //Decrement onscreen timer setting count
            onsTimSetPos--;
            break;
        }
    }
}
