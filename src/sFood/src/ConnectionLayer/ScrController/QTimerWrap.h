#ifndef QTIMERWRAP_H
#define QTIMERWRAP_H

#include <QObject>
#include <QTimer>

class QTimerWrap : public QTimer
{
    Q_OBJECT
public:
    QTimerWrap(int type, unsigned int  targetID);
    ~QTimerWrap();
private:
    unsigned int p_targetID;      //OnsID
    int m_screen;
public slots:
    void timeout_exec();
};
#endif // QTIMERWRAP_H
