#ifndef APPMAIN_ENGINE_H
#define APPMAIN_ENGINE_H

#include <QObject>
#include <QGuiApplication>
#include <QQuickView>
#include "ConnectionLayer/AppManager/AppManager.h"
#include "ConnectionLayer/ScrController/CommonStructs.h"

class AppHomeEngine : public QObject
{
    Q_OBJECT

public:
    explicit AppHomeEngine(int &argc, char *argv[], QObject *parent = 0);
    ~AppHomeEngine();
    void applicationStart();

public:
    int exec();
    void initEngine();
    void initAppication();
    void initQmlRegisterType();
    void initLanguage();
    void showFrontView();
    void hideFrontView();

public slots:
    void switchLanguage(int cmd);
    void triggerEvtHandler(MSG_INF msgInf);
    void slotScrHistoryChanged();
    void slotOnsHistoryChanged();
    void slotNotifyLanguageChanged(int langID);

private:
    void initFont();
    void loadSetting();
    void homeListSendToApp(const int itemID, const bool fromMyMenu = false);
    void closeAllPopup();
    void closeAllPopupOnScreen();
private:
    QGuiApplication             *m_pApp;
    QQuickView                  *m_Frontview;
    QTranslator                 *translator;
    int                         m_screenSize;
    int                         m_language;
    int                         currentTopScreen;
    bool                        isPreviousScreen;

};

#endif
