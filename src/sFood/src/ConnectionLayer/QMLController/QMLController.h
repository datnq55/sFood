#ifndef QMLCONTROLLER_H
#define QMLCONTROLLER_H

#include <QObject>

#include <QQuickItem>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include <QVariantList>
#include <QMap>
#include "CommonStructs.h"
#include "ScreenQueue.h"


class QMLController : public QObject
{
    Q_OBJECT
public:
    static QMLController* getInstance(SCREENTYPE_T type);
    QMLController(QMLController const&)   = delete;
    void operator=(QMLController const&)  = delete;

    bool construct(QtQuick2ApplicationViewer *viewer);
    QtQuick2ApplicationViewer * getViewer();
    bool showScreen(QString scrName);
    void showOSD(OSD_DATA* onsTbl);

    void initCachedScreen();
private slots:
    void slotVisibleChanged(bool state);
private:
    explicit QMLController(SCREENTYPE_T type);
    virtual ~QMLController();

    QQmlComponentPtr getComponent(QObject *parent, QString screen);
    SCREENTYPE_T getScrenType();
    SCREENTYPE_T m_screen;
    QVariantList p_mOnsData;
    ScreenQueue cacheScreen;

    bool	initialized;
    QtQuick2ApplicationViewer *viewer;
    QObject* root_Obj;
};
#endif // QMLCONTROLLER_H
