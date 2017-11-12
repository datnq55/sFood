#include <QDebug>
#include <QObject>
#include "AppHomeView.h"
#include "../ConnectionLayer/AppManager/AppManager.h"
#include "../AppHomeEngine.h"
#include "../Model/AppHomeModel.h"

//#define HOME_MODEL   AppHomeModel::instance()

//void MAIN_SCREEN_MENU_GOTO_ALL_SCREEN_ITEMS(QVariant msg)
//{
//    int currentScr = -1;
//    if(!AppManager::getInstance()->getScreenHistory().isEmpty()){
//        currentScr = AppManager::getInstance()->getScreenHistory().top();
//    }
//    if (HOME_MODEL->isWideScr())
//    {
//        DLT_HIGH << "MAIN_SCREEN_MENU_GOTO_ALL_SCREEN_ITEMS = " << currentScr;
//        if(HMIEVENTS::EVT_GOTO_SCREEN_WIDE_ALL_ITEMS != currentScr)
//        {
//            DLT_HIGH << "LOADING WIDE SCREEN";
//            AppManager::getInstance()->clearScrHistoryStack();
//            AppManager::getInstance()->reqChangeTopMsg(HMIEVENTS::EVT_GOTO_SCREEN_WIDE_ALL_ITEMS, msg);
//        }
//    }
//    else
//    {
//        if(HMIEVENTS::EVT_GOTO_SCREEN_NORM_ALL_ITEMS != currentScr)
//        {
//            DLT_HIGH << "LOADING NORMAL SCREEN";
//            AppManager::getInstance()->clearScrHistoryStack();
//            AppManager::getInstance()->reqChangeTopMsg(HMIEVENTS::EVT_GOTO_SCREEN_NORM_ALL_ITEMS, msg);
//        }
//    }
////    else {
////        if(HMIEVENTS::EVT_GOTO_SCREEN_NORM_ALL_ITEMS != currentScr)
////        {
////            DLT_HIGH << "LOADING REAR SCREEN";
////            AppManager::getInstance()->reqChangeTopMsg(HMIEVENTS::EVT_GOTO_SCREEN_NORM_ALL_ITEMS, msg);
////        }
////    }
//}

//void MAIN_LIST_ITEMCLICKED_HANDLE(QVariant msg)
//{
//    DLT_HIGH << msg.toInt();
//}
//void SUBMENU_BLUELINK_ITEMCLICKED_HANDLE(QVariant msg)
//{
//    DLT_HIGH << msg.toInt();
//}
//void SUBMENU_MEDIA_ITEMCLICKED_HANDLE(QVariant msg)
//{
//    DLT_HIGH << msg.toInt();
//}
//void SUBMENU_SETUP_ITEMCLICKED_HANDLE(QVariant msg)
//{
//    DLT_HIGH << msg.toInt();
//}
//void SUBMENU_DATASERVICE_ITEMCLICKED_HANDLE(QVariant msg)
//{
//    DLT_HIGH << msg.toInt();
//}
//void SUBMENU_INFORMATION_ITEMCLICKED_HANDLE(QVariant msg)
//{
//    DLT_HIGH << msg.toInt();
//}

//void MYMENU_ITEMCLICKED_HANDLE(QVariant msg){
//    DLT_HIGH << msg.toInt();
//}

//void AW_GET_LIST_WIDGETS_HANDLE(QVariant msg){
//    DLT_HIGH << msg.toInt();
//    AppManager::getInstance()->reqShowOnscreen(ONSID_HOME_OPTION_MENU_AW);

//}


//void OPEN_OPTION_MENU_HANDLE(QVariant msg){
//    DLT_HIGH << msg.toInt();
//    AppManager::getInstance()->reqShowOnscreen(ONSID_HOME_OPTION_MENU);
//}

//void SET_AW_WIDGET_HANDLE(QVariant msg){
//    DLT_HIGH << msg.toInt();
//    int _keyListWG =   0;  //AW_WIDGET_NAME.key((AppHomeModel::instance(scrType)->listAWWidget().at(msg.toInt())));//AppHomeModel::instance(scrType)->listAWWidget()
//    QList<int>_listKey = AW_WIDGET_NAME.keys();
//    for(int i = 0; i < _listKey.count(); i ++){
//        if(AW_WIDGET_NAME.value(_listKey[i])  ==  AppHomeModel::instance()->listAWWidget().at(msg.toInt())){
//            _keyListWG = _listKey[i];
//            QDBusMessage info = QDBusMessage::createSignal(AW_PATH, AW_INTERFACE,AW_SIG_FOCUS);


//            info << _keyListWG;//msg.toInt();
//            DLT_HIGH<<"_keyListWG  "<< _keyListWG << "NAME WIDGET: "<<AW_WIDGET_NAME.value(_keyListWG);
//            QDBusConnection::sessionBus().send(info);
//            return;
//        }
//    }
//}

//void HOME_LIST_PAGE1_MOVING_HANDLE(QVariant msg)
//{
//    DLT_HIGH<< msg;
//    QList<QVariant> tmpdata = msg.toList();
//    int _from = tmpdata.value(0).toInt(); //change item form index "fromIdx" vs to "toIdx"
//    int _to = tmpdata.value(1).toInt();
//    HOME_MODEL->dragDropItemOfList(HMIEVENTS::EVT_HOME_LIST_PAGE1_MOVING, _from, _to);
//}


//void HOME_LIST_PAGE2_MOVING_HANDLE(QVariant msg)
//{
//    DLT_HIGH<< msg;
//    QList<QVariant> tmpdata = msg.toList();
//    int _from = tmpdata.value(0).toInt(); //change item form index "fromIdx" vs to "toIdx"
//    int _to = tmpdata.value(1).toInt();

//    HOME_MODEL->dragDropItemOfList(HMIEVENTS::EVT_HOME_LIST_PAGE2_MOVING, _from, _to);
//}


//void HOME_LIST_PAGE3_MOVING_HANDLE(QVariant msg)
//{
//    DLT_HIGH<< msg;
//    QList<QVariant> tmpdata = msg.toList();
//    int _from = tmpdata.value(0).toInt(); //change item form index "fromIdx" vs to "toIdx"
//    int _to = tmpdata.value(1).toInt();

//    HOME_MODEL->dragDropItemOfList(HMIEVENTS::EVT_HOME_LIST_PAGE3_MOVING, _from, _to);
//}


//void HOME_LIST_PAGE4_MOVING_HANDLE(QVariant msg)
//{
//    DLT_HIGH<< msg;
//    QList<QVariant> tmpdata = msg.toList();
//    int _from = tmpdata.value(0).toInt(); //change item form index "fromIdx" vs to "toIdx"
//    int _to = tmpdata.value(1).toInt();
//    HOME_MODEL->dragDropItemOfList(HMIEVENTS::EVT_HOME_LIST_PAGE4_MOVING, _from, _to);
//}

//void HOME_NOTIFY_SHOW_AV_WIDGET_PAGE_HANDLE(QVariant msg){

//}

//void SHOW_POPUP_AD_NOTIFY_HANDLER(QVariant msg){
//    DLT_HIGH << msg;
//    AppManager::getInstance()->reqShowOnscreen(ONSID_MYMENU_ADD_DELETE_NOTIFY);
//}


//// MY MENU
//void MY_MENU_ADD_DEL_HANDLER(QVariant msg)
//{
//    DLT_HIGH << msg;
//    switch (MY_MENU->popMyMenuConfirmType()) {
//    case AppHome_Enum::ADD_MYMENU_CONFRIM:
//    {
//        int numberExItemAdd = MY_MENU->getListMyMenuSize() + MY_MENU->getListItemWillAdd();
//        qDebug()<<"----------> numberExItemAdd: "<<numberExItemAdd;
//        if(numberExItemAdd <= 24){
//            AppManager::getInstance()->reqShowOnscreen(ONSID_MYMENU_ADD_DEL_CONFIRMATION);
//        }else{
//            AppManager::getInstance()->reqShowOnscreen(ONSID_MYMENU_ADD_FULL_NOTIFY);
//        }
//    }
//        break;
//    case AppHome_Enum::DELETE_MYMENU_CONFRIM:
//        AppManager::getInstance()->reqShowOnscreen(ONSID_MYMENU_ADD_DEL_CONFIRMATION);
//        break;
//    default:
//        break;
//    }
//}

//void MY_MENU_MOVE_ITEM_HANDLER(QVariant msg){
//    DLT_HIGH << msg;
//    MY_MENU->myMenuMoveItem(msg);
//}
//void MOVE_FOCUS_STATE_TO_AW_HANDLE(QVariant msg)
//{
//    DLT_HIGH << msg;
//}

//void MOVE_FOCUS_STATE_TO_THIS_APP_HANDLE(QVariant msg)
//{
//    DLT_HIGH << msg;
//}

//void OPEN_SXM_SUBCRIPTION_HANDLER(QVariant msg){
//    DLT_HIGH << msg;
//    AppManager::getInstance()->reqShowOnscreen(ONSID_HOME_POPUP_SXM_SUBCRIPTION);
//}

//void HOME_LIST_PAGE0_MOVING_HANDLE(QVariant msg)
//{
//    DLT_HIGH<< msg;
//    QList<QVariant> tmpdata = msg.toList();
//    int _from = tmpdata.value(0).toInt(); //change item form index "fromIdx" vs to "toIdx"
//    int _to = tmpdata.value(1).toInt();

//    HOME_MODEL->dragDropItemOfList(HMIEVENTS::EVT_HOME_LIST_PAGE0_MOVING, _from, _to);
//}

//void CLICK_DISP_OFF_HANDLE(QVariant msq)
//{
//    DLT_HIGH << msq << "CLICK_DISP_OFF_HANDLE";
//}

//void SHOW_POPUP_HANDLE(QVariant msg){
//    int _OSD_ID = msg.toInt();
//    AppManager::getInstance()->reqShowOnscreen(_OSD_ID);
//}

//void HIDE_POPUP_HANDLE(QVariant msg){
//    int _OSD_ID = msg.toInt();
//    AppManager::getInstance()->reqHideOnscreen(_OSD_ID);
//}


//void GOTO_HOME_CUSTOMIZE_HANDLE(QVariant msg)
//{
//    DLT_HIGH;
//    AppManager::getInstance()->reqChangeTopMsg(HMIEVENTS::EVT_GOTO_HOME_CUSTOMIZE_WIDE, msg);
//}

//void CLOSE_SETTING_WIDGET_HANDLE(QVariant msg){
//    DLT_HIGH << msg;
//    int _numberWidgetChecked = HOME_MODEL->getWidgetChecked();
//    if(_numberWidgetChecked == MAX_NUMBER_WIDGET_FRONT){
//        HOME_MODEL->SaveWidetSettingDB();
//        HOME_MODEL->updateWidgitBinding(true);
//        AppManager::getInstance()->addMsgToQueue(HMIEVENTS::EVT_BACK_TO_PREV_SCREEN);
//    }else{
//        HOME_MODEL->setPopupYesNoType(AppHome_Enum::E_POPUP_WIDGET_SETTING_WARNING);
//        AppManager::getInstance()->reqShowOnscreen(ONSID_HOME_POPUP_YES_NO);
//    }
//}

//void POPUP_YES_BUTTON_CLICK_HANDLER(QVariant msg){
//    DLT_HIGH << msg ;
//    switch (HOME_MODEL->popupYesNoType()) {
//    case (int)AppHome_Enum::E_POPUP_WIDGET_SETTING_WARNING:{
//        QStack<uint> _stackScreen = AppManager::getInstance()->getScreenHistory();
//        if(!_stackScreen.isEmpty()){
//            if(_stackScreen.top() == HMIEVENTS::EVT_GOTO_HOME_SETTING_WIDGET){
//                AppManager::getInstance()->addMsgToQueue(HMIEVENTS::EVT_BACK_TO_PREV_SCREEN);
//            }
//        }
//        HOME_MODEL->resetWidgetChecked();
//    }
//        break;
//    default:
//        DLT_HIGH << "default case";
//        break;
//    }
//    AppManager::getInstance()->reqHideOnscreen(ONSID_HOME_POPUP_YES_NO);
//}
//void POPUP_NO_BUTTON_CLICK_HANDLER(QVariant msg){
//    DLT_HIGH << msg;
//    //    switch (HOME_MODEL((SCREENTYPE_T)scrType)->popupYesNoType()) {
//    //    case (int)AppHome_Enum::E_POPUP_WIDGET_SETTING_WARNING:

//    //        break;
//    //    default:
//    //        DLT_HIGH << "default case";
//    //        break;
//    //    }
//    AppManager::getInstance()->reqHideOnscreen(ONSID_HOME_POPUP_YES_NO);
//}

//void BACK_TO_MAIN_LIST(QVariant msg)
//{
//    DLT_HIGH << msg;
//    int _current_scr =AppHomeModel::instance()->currentScreen();
//    switch (_current_scr) {
//    case HMIEVENTS::EVT_GOTO_SCREEN_SUBMENU_SETUP:
//        DLT_HIGH << "EVT_GOTO_SCREEN_SUBMENU_SETUP";
//        HOME_MODEL->setViewAtItem(ITEM_ID_SETUP);
//        break;
//    case HMIEVENTS::EVT_GOTO_SCREEN_SUBMENU_MEDIA:
//        DLT_HIGH << "EVT_GOTO_SCREEN_SUBMENU_MEDIA";
//        HOME_MODEL->setViewAtItem(ITEM_ID_MEDIA);
//        break;
//    case HMIEVENTS::EVT_GOTO_SCREEN_DATA_SERVICE:
//        DLT_HIGH << "EVT_GOTO_SCREEN_DATA_SERVICE";
//        HOME_MODEL->setViewAtItem(ITEM_ID_DATA_SERVICE);
//        break;
//    case HMIEVENTS::EVT_GOTO_SCREEN_SUBMENU_INFOMATION:
//        DLT_HIGH << "EVT_GOTO_SCREEN_SUBMENU_INFOMATION";
//        HOME_MODEL->setViewAtItem(ITEM_ID_INFORMATION);
//        break;
//    default:
//        DLT_HIGH << "default case";
//        break;
//    }
//    AppManager::getInstance()->addMsgToQueue(HMIEVENTS::EVT_GOTO_ALL_SCREEN_ITEMS);
//}
