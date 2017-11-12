#ifndef QTIMERWRAP_H
#define QTIMERWRAP_H

#include <QObject>
#include <QTimer>

class QTimerWrap : public QTimer
{
    Q_OBJECT
public:
    QTimerWrap(unsigned int  targetID);
    ~QTimerWrap();
private:
    unsigned int p_targetID;      //OnsID
public slots:
    void timeout_exec();
};
#endif // QTIMERWRAP_H
