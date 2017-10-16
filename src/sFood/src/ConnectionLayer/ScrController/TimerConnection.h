#ifndef TIMERONSCONTROLLER_H
#define TIMERONSCONTROLLER_H

#include <QObject>
#include <QTimer>
#include "OnsController.h"

class OnsController;

class TimerConnection: public QObject
{
    Q_OBJECT
public:

    //Singleton model
    static TimerConnection* getInstance(SCREENTYPE_T type);
    TimerConnection(TimerConnection const&) = delete;
    void operator=(TimerConnection const&)  = delete;

    void reqShowOSDTimer(unsigned int onsid, unsigned int param);                           /* Set one-shot timer request for Onscreen management       */
    void reqHideOSDCountDown(unsigned int onsid);                                         /* Delete one-shot timer request for Onscreen management    */
    void timout_OnsTimer(unsigned int onsid);

private:
    explicit TimerConnection(SCREENTYPE_T type);
    virtual ~TimerConnection();
    void setOnsTimerTbl(void);                                                                  /* Create Onscreen timer table */

   TIMER_CTRL       mng_Timer[TIMER_SET_MAX];                                               /* Managerment table for basic application requirement */
   ONS_TIMER_CTRL   mng_OnsTimer[ONS_DELTIMER_MAX];                                         /* Managerment table for Onscreen delete timer control */

   unsigned char timSetPos;
   unsigned char onsTimSetPos;

   SCREENTYPE_T getScrenType();
   SCREENTYPE_T m_screen;
};
#endif // TIMERONSCONTROLLER_H
