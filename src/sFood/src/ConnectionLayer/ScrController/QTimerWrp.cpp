#include "QTimerWrap.h"
#include "TimerConnection.h"

QTimerWrap::QTimerWrap(unsigned int  targetID)
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

    TimerConnection::getInstance()->timout_OnsTimer(p_targetID);
}
