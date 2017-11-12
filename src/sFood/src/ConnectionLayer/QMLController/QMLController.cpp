#include "QMLController.h"
#include <QTextCodec>
#include <QQmlEngine>
#include <QDebug>

QMLController* QMLController::getInstance()
{
        static QMLController instanceFront;
        return &instanceFront;
}

QMLController::QMLController() : initialized(false),viewer(NULL), root_Obj(NULL)
{
}

QMLController::~QMLController()
{
}

bool QMLController::construct(QQuickView *viewer)
{
    if (!initialized)
    {
        unsigned char cnt ;
        for(cnt = 0;cnt < ONSCOUNT_MAX; cnt++ )
        {
            p_mOnsData  << "";
        }

        this->viewer = viewer;
        this->root_Obj = viewer->rootObject();
        initialized = true;
    }

    QObject::connect(this->viewer, SIGNAL(visibleChanged(bool)), this, SLOT(slotVisibleChanged(bool)));

    return(initialized);
}

QQuickView * QMLController::getViewer()
{
    return (this->viewer);
}

bool QMLController::showScreen(QString scrName)
{
    bool _rest = false;
    if (!initialized) {
        // TODO
        return _rest;
    }

    if(!cacheScreen.contains(scrName)){
        cacheScreen.insert(scrName, getComponent(viewer->rootObject(), scrName));
    }

    this->collectGarbage();
    viewer->rootContext()->setContextProperty("screenNext", nullptr);
    viewer->rootContext()->setContextProperty("screenNext", cacheScreen[scrName].data());

#if 0
    //call invokeMethod to QML for Base Screent
    root_Obj->setProperty("isDrawed", false);
    qDebug() << "[3]" << Q_FUNC_INFO << "SCREEN_STATE" << " BFFFF: " << root_Obj->property("isDrawed");
#endif
    _rest = QMetaObject::invokeMethod(root_Obj, "screen_Transition");
#if 0
    while (1) {
        qDebug() << "[3]" << "SCREEN_STATE" << " AFFFF: " << root_Obj->property("isDrawed");
        if(root_Obj->property("isDrawed").toBool()){
            return true;
        }
    }
#endif
    if(_rest){
        emit scrHistoryChanged();
    }
    return _rest;
}

void QMLController::showOSD(OSD_DATA* onsTbl)
{
    if(!p_mOnsData.isEmpty()){
        for(int cnt = 0; cnt < ONSCOUNT_MAX; cnt++)
        {
            /* Compare Onscreen table */
            if(p_mOnsData[cnt] != onsTbl[cnt].QmlPath)
            {
                /* is overwrited by received Onscreen data. */
                p_mOnsData[cnt] = onsTbl[cnt].QmlPath;
            }
        }
    }
    /* call invokeMethod to QML for Onscreen */
    QMetaObject::invokeMethod(root_Obj, "load_OSD", Q_ARG(QVariant, QVariant::fromValue(p_mOnsData)));
}

void QMLController::reqTrimComponentCached()
{
    qDebug() << Q_FUNC_INFO;
    this->collectGarbage();
}

QQmlComponentPtr QMLController::getComponent(QObject *parent, QString screen) {
    QQmlEngine *engine = qmlEngine(parent);
    if(engine) {
        QQmlComponentPtr component = QQmlComponentPtr(new QQmlComponent(engine, screen, this));
        return component;
    }
    return QQmlComponentPtr(NULL);
}

void QMLController::initCachedScreen()
{
    cacheScreen.initScreenQueue();
}

void QMLController::slotVisibleChanged(bool state){
    if(!state){
        cacheScreen.initScreenQueue();
    }
    this->collectGarbage();
}

void QMLController::collectGarbage(){
    viewer->engine()->collectGarbage();
}
