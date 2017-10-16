#include "QTimerWrap.h"
#include "TimerConnection.h"

QTimerWrap::QTimerWrap(int type, unsigned int  targetID): m_screen(type)
{
    p_targetID = targetID;
}

QTimerWrap::~QTimerWrap()
{
}

void QTimerWrap::timeout_exec()
{
    /* timeout slot function */
    this->stop();

    TimerConnection::getInstance((SCREENTYPE_T)m_screen)->timout_OnsTimer(p_targetID);
}
