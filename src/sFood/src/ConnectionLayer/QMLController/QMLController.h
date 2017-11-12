#ifndef QMLCONTROLLER_H
#define QMLCONTROLLER_H

#include <QObject>

#include <QQuickItem>
#include <QQmlContext>
#include <QQuickView>
#include <QVariantList>
#include <QMap>
#include "../ScrController/CommonStructs.h"
#include "ScreenQueue.h"


class QMLController : public QObject
{
    Q_OBJECT
public:
    static QMLController* getInstance();
    QMLController(QMLController const&)   = delete;
    void operator=(QMLController const&)  = delete;

    bool construct(QQuickView *viewer);
    QQuickView * getViewer();
    bool showScreen(QString scrName);
    void showOSD(OSD_DATA* onsTbl);
    void reqTrimComponentCached();
    void initCachedScreen();
signals:
    void scrHistoryChanged();
private slots:
    void slotVisibleChanged(bool state);
private:
    explicit QMLController();
    virtual ~QMLController();

    QQmlComponentPtr getComponent(QObject *parent, QString screen);
    QVariantList p_mOnsData;
    ScreenQueue cacheScreen;

    bool	initialized;
    QQuickView *viewer;
    QObject* root_Obj;
    void collectGarbage();
};
#endif // QMLCONTROLLER_H
