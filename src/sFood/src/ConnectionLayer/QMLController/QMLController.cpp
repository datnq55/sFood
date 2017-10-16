#include "QMLController.h"
#include <QTextCodec>
#include <QQmlEngine>
#include "Logger.h"

QMLController* QMLController::getInstance(SCREENTYPE_T type)
{
    if(FRONT_SCREEN == type){
        static QMLController instanceFront(FRONT_SCREEN);
        return &instanceFront;
    }
    else{
        static QMLController instanceRear(REAR_SCREEN);
        return &instanceRear;
    }
}

QMLController::QMLController(SCREENTYPE_T type) : initialized(false),viewer(NULL), root_Obj(NULL), m_screen(type)
{
}

QMLController::~QMLController()
{
}

bool QMLController::construct(QtQuick2ApplicationViewer *viewer)
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

QtQuick2ApplicationViewer * QMLController::getViewer()
{
    return (this->viewer);
}

bool QMLController::showScreen(QString scrName)
{
    if (!initialized) {
        // TODO
        return false;
    }

    if(!cacheScreen.contains(scrName)){
        cacheScreen.insert(scrName, getComponent(viewer->rootObject(), scrName));
    }

    viewer->engine()->collectGarbage();
    viewer->rootContext()->setContextProperty("screenNext", nullptr);
    viewer->rootContext()->setContextProperty("screenNext", cacheScreen[scrName].data());

    //call invokeMethod to QML for Base Screent
    root_Obj->setProperty("isDrawed", false);
    qDebug() << "[3]" << "SCREEN_STATE" << " BFFFF: " << root_Obj->property("isDrawed");

    QMetaObject::invokeMethod(root_Obj, "screen_Transition");

//    while (1) {
//        qDebug() << "[3]" << "SCREEN_STATE" << " AFFFF: " << root_Obj->property("isDrawed");
//        if(root_Obj->property("isDrawed").toBool()){
//            return true;
//        }
//    }

    return false;
}

void QMLController::showOSD(OSD_DATA* onsTbl)
{
    //DLT_HIGH << "onsTbl" << onsTbl;
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


QQmlComponentPtr QMLController::getComponent(QObject *parent, QString screen) {
    QQmlEngine *engine = qmlEngine(parent);
    if(engine) {
        QQmlComponentPtr component = QQmlComponentPtr(new QQmlComponent(engine, screen, this));
        return component;
    }
    return QQmlComponentPtr(NULL);
}

SCREENTYPE_T QMLController::getScrenType()
{
    return m_screen;
}

void QMLController::initCachedScreen()
{
    cacheScreen.initScreenQueue();
}

void QMLController::slotVisibleChanged(bool state){
    qDebug() << "[3]" << Q_FUNC_INFO << state;
    if(!state){
        cacheScreen.initScreenQueue();
        viewer->engine()->clearComponentCache();
    }
}
