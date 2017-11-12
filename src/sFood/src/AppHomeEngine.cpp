#include <QQmlContext>
#include <QDir>
#include <QFontDatabase>
#include <QDebug>
#include <QtQml>
#include <QTranslator>
#include <QApplication>
#include <QPushButton>
#include <QEvent>

#include "AppHomeEngine.h"
#include "ConnectionLayer/QMLController/QMLController.h"
#include "ConnectionLayer/ScrController/ScrController.h"
#include "View/HMIEvents.h"
#include "View/AppHome_ScreenDefs.h"
#include "AppHomeEnums.h"
#include "AppHomeDefs.h"
#include <qpa/qplatformnativeinterface.h>

#define HOME_MODEL          AppHomeModel::instance()

AppHomeEngine::AppHomeEngine(int &argc, char *argv[], QObject *parent)
    :m_pApp                 (new QGuiApplication(argc, argv))
    ,m_Frontview            (new QQuickView)
    ,translator             (NULL)
    ,m_screenSize           (0)
    ,m_language             (AppHomeEnums::E_LANGUAGE_EN_US)
{
    setParent(parent);
}

AppHomeEngine::~AppHomeEngine()
{
    if(NULL != m_Frontview) {
        delete m_Frontview;
        m_Frontview = NULL;
    }

    if(NULL != m_pApp) {
        delete m_pApp;
        m_pApp = NULL;
    }

    if(NULL != translator) {
        delete translator;
        translator = NULL;
    }
    this->disconnect();
}

int AppHomeEngine::exec()
{
    if(m_pApp != NULL) {
        return m_pApp->exec();
    }
    return 0;
}

void AppHomeEngine::applicationStart() {
    loadSetting();
    //HOME_MODEL->loadMenuList(m_regionId,_tpFirm);

    QObject::connect(AppManager::getInstance(),SIGNAL(screenTriggerHandled(MSG_INF)),this, SLOT(triggerEvtHandler(MSG_INF)));

    QObject::connect(AppManager::getInstance(),SIGNAL(onsHistoryChanged()),this, SLOT(slotOnsHistoryChanged()));

    QObject::connect(AppManager::getInstance(),SIGNAL(scrHistoryChanged()),this, SLOT(slotScrHistoryChanged()));
    //scrHistoryChanged
    initFont();
    initLanguage();
    initQmlRegisterType();
    initEngine();
    initAppication();
}

void AppHomeEngine::initFont()
{
    QStringList fontFiles;
    if(!fontFiles.isEmpty()){
        fontFiles.clear();
    }
    QStringList fontNamesB, fontNamesR;
    if(!fontNamesB.isEmpty()){
        fontNamesB.clear();
    }
    if(!fontNamesR.isEmpty()){
        fontNamesR.clear();
    }

    // Add Font files to process
    fontFiles << QString("%1%2").arg(FONT_DIR).arg(CUBER_31);
    fontFiles << QString("%1%2").arg(FONT_DIR).arg(CUBEB_30);
    fontFiles << QString("%1%2").arg(FONT_DIR).arg(DROID_NASKH_SHIFT_ALT);
    fontFiles << QString("%1%2").arg(FONT_DIR).arg(DFHEI5);

    fontNamesR << DEF_RJ_FONT_R << DEF_ARABIC_FONT_R << DEF_SPECIAL_FONT_R;
    fontNamesB << DEF_RJ_FONT_B << DEF_ARABIC_FONT_B << DEF_SPECIAL_FONT_B;

    int fontID = UNKNOW_DATA;
    for(int nCnt = 0 ; nCnt < fontFiles.count() ; nCnt++)
    {
        fontID = QFontDatabase::addApplicationFont(fontFiles.at(nCnt));
        qDebug() << "LOADED: FONT >>>> " << fontFiles.at(nCnt) << ">>> FONT ID:" << fontID;
    }

    QFont::insertSubstitutions("HKMC_FONT_R", fontNamesR);
    QFont::insertSubstitutions("HKMC_FONT_B", fontNamesB);
    m_pApp->setFont(QFont("HKMC_FONT_B"));
    m_pApp->setFont(QFont("HKMC_FONT_R"));
}

void AppHomeEngine::initEngine()
{
    if(m_pApp == NULL) {
        return;
    }
    if(m_Frontview){
        //For front monitor
        //20170607007_ADD +s
        m_Frontview->setPersistentOpenGLContext(false);
        m_Frontview->setPersistentSceneGraph(false);
        //20170607007_ADD +e
        m_Frontview->setClearBeforeRendering(true);
        m_Frontview->setColor(QColor(Qt::transparent));
        m_Frontview->rootContext()->setContextProperty("AppHomeEngine", this);
        //m_Frontview->rootContext()->setContextProperty("AppHomeModel",  HOME_MODEL);
        m_Frontview->rootContext()->setContextProperty("DEVICE_WIDTH",  m_screenSize);
        //m_Frontview->rootContext()->setContextProperty("DEVICE_HEIGHT", DEVICE_HEIGHT );
        //m_Frontview->rootContext()->setContextProperty("RESOURCE_DIR",  QString("%1%2").arg(m_pApp->applicationDirPath()).arg(HOME_RESOURCE_DIR));
        m_Frontview->setSource(QUrl::fromLocalFile(SCREEN_HOMESCREEN_MAIN_QML));

        showFrontView();
    }
}

void AppHomeEngine::initQmlRegisterType(){
    qmlRegisterType<HMIEvents>("HMIEvents", 1, 0, "HMIEvents");
    qmlRegisterType<AppHomeEnums>("AppHomeEnums", 1, 0, "AppHomeEnums");
}

void AppHomeEngine::initAppication()
{
    if(m_Frontview){
        QMLController* form = QMLController::getInstance();
        m_Frontview->rootContext()->setContextProperty("QML_Handler", ScrController::getInstance());
        form->construct(m_Frontview);
        AppManager::getInstance()->addMsgToQueue(HMIEvents::EVT_GOTO_ALL_SCREEN_ITEMS);
    }
}

void AppHomeEngine::initLanguage()
{
    if(NULL == translator) {
        try {
            translator = new QTranslator();
        }
        catch (std::bad_alloc &msg) {
            qDebug() << "bad_alloc: " << msg.what();
            if (NULL != translator) {
                delete translator;
                translator = NULL;
            }
        }
    }

    if (NULL != translator) {
        ((QApplication *)qApp)->installTranslator(translator);
    }

    qDebug() << m_language;
    switchLanguage(m_language);
}

void AppHomeEngine::switchLanguage(int nLanguage)
{
    //AppHomeModel::instance()->setLanguage(nLanguage);
    QString lang_file = QString(APPHOME_LANGUAGE_DIR)+ "translation_";
    lang_file.append(m_multiLanguageMap.value((AppHomeEnums::ENUM_LANGUAGE)nLanguage)).append(".qm");
    if (NULL != m_pApp)
    {
        if (NULL != translator)
        {
            if(translator->load(lang_file) == false)
            {
                lang_file = APP_HOME_LAN_EN + ".qm";
            }
            translator->load(lang_file);
            qDebug() << "LANGUGE FILE: " << lang_file;
            qDebug() << "INSTALL LANGUAGE: " << m_pApp->installTranslator(translator);
            AppManager::getInstance()->reqRefreshDisp();
        }
    }
}

void AppHomeEngine::hideFrontView(){
    m_Frontview -> hide();
    QStack<uint> _popUpShow = AppManager::getInstance()->getOnscreenHistory();
    if(_popUpShow.count() > 0){
//        this->localPopupState(E_LOCAL_ONS_OFF);
    }
}

void AppHomeEngine::showFrontView(){
    m_Frontview->show();

    QGuiApplication::platformNativeInterface()->setWindowProperty(m_Frontview->handle(), QStringLiteral("displayPlane"), QStringLiteral("1"));
}

void AppHomeEngine::slotNotifyLanguageChanged(int langID)
{
    qDebug();
    switchLanguage(langID);
}

void AppHomeEngine::triggerEvtHandler(MSG_INF msgInf)
{
    qDebug() << msgInf.eventID << msgInf.evtData;
    switch (msgInf.eventID) {
    case HMIEvents::EVT_MAIN_LIST_ITEMCLICKED:
        homeListSendToApp(msgInf.evtData.toInt(), false);
        break;
    case HMIEvents::EVT_GOTO_SCREEN_ALL_MENUS:
//        HOME_MODEL->setInFirstDepth(false);
//        HOME_MODEL->m_lastEvt = msgInf.eventID;
//        requestShowHomeBtn(true);
        break;
    case HMIEvents::EVT_BACK_TO_PREV_SCREEN:{
        qDebug() << "HMIEvents::EVT_BACK_TO_PREV_SCREEN";
//        HOME_MODEL->setInFirstDepth(false);
//        QStack<uint> _stackScr = AppManager::getInstance()->getScreenHistory();
//        if(!_stackScr.isEmpty()){
//            HOME_MODEL->m_lastEvt = _stackScr.top();
//            if((_stackScr.top() == (uint)HMIEvents::EVT_GOTO_SCREEN_WIDE_ALL_ITEMS) ||(_stackScr.top() == (uint)HMIEvents::EVT_GOTO_SCREEN_NORM_ALL_ITEMS)){
//                HOME_MODEL->setInFirstDepth(true);
//                requestShowHomeBtn(false);
//            }
//        }
    }
        break;
    default:

        qDebug()<< "DO NONE";
        break;
    }
}

void AppHomeEngine::homeListSendToApp(const int itemID, const bool /*fromMyMenu*/){
    qDebug() << " itemID = " << itemID;
    switch (itemID) {
    //20170504006
    case ITEM_ID_ALLMENU:
        AppManager::getInstance()->addMsgToQueue(HMIEvents::EVT_GOTO_SCREEN_ALL_MENUS);
        break;
    default:
        qDebug() << "ITEM_ID INVALID";
        break;
    }
}

void AppHomeEngine::loadSetting()
{
}

void AppHomeEngine::closeAllPopup(){
    QStack<uint> _listPopUp = AppManager::getInstance()->getOnscreenHistory();
    if(!_listPopUp.isEmpty()){
        foreach (uint _popupID, _listPopUp) {
            AppManager::getInstance()->reqHideOnscreen(_popupID);
        }
    }
}

void AppHomeEngine::closeAllPopupOnScreen()
{
    QStack<uint> _listPopUp = AppManager::getInstance()->getOnscreenHistory();
    if(!_listPopUp.isEmpty()){
        qDebug() << "HIDE POPUP  > > > > >  > >  > > > >   ";
        //this->localPopupState(E_LOCAL_ONS_OFF);
        foreach (uint _popupID, _listPopUp) {
            AppManager::getInstance()->reqHideOnscreen(_popupID);
        }
    }
    else
        qDebug() << "THERE'S NO POPUP  > > > > >  > >  > > > >   ";
}

void AppHomeEngine::slotScrHistoryChanged()
{
    QStack<uint> _scrStack = AppManager::getInstance()->getScreenHistory();
    qDebug() << _scrStack;
    if(!_scrStack.isEmpty()){
        //int screenDepth = (HOME_MODEL->currentScreen()  == HMIEvents::EVT_GOTO_SCREEN_WIDE_ALL_ITEMS
        //                    || HOME_MODEL->currentScreen()  == HMIEvents::EVT_GOTO_SCREEN_NORM_ALL_ITEMS) ? 0 : 1;
        //HOME_MODEL->notifyScreenDepth(screenDepth);
        //HOME_MODEL->setCurrentScreen((int)_scrStack.top());

    }
}

void AppHomeEngine::slotOnsHistoryChanged()
{
    qDebug();
}
