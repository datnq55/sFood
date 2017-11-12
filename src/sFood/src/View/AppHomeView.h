#ifndef APPHOMEVIEW_H
#define APPHOMEVIEW_H
#include "QDebug"
#include "AppHome_ScreenDefs.h"
#include "HMIEvents.h"
#include "../ConnectionLayer/ScrController/CommonStructs.h"
#include "../Model/AppHomeModel.h"
#include "../ConnectionLayer/AppManager/AppManager.h"
#include "../AppHomeEngine.h"

void MAIN_SCREEN_MENU_GOTO_ALL_SCREEN_ITEMS(QVariant msg);
void MAIN_LIST_ITEMCLICKED_HANDLE(QVariant msg);
void SUBMENU_BLUELINK_ITEMCLICKED_HANDLE(QVariant msg);
void SUBMENU_MEDIA_ITEMCLICKED_HANDLE(QVariant msg);
void SUBMENU_SETUP_ITEMCLICKED_HANDLE(QVariant msg);
void SUBMENU_DATASERVICE_ITEMCLICKED_HANDLE(QVariant msg);
void SUBMENU_INFORMATION_ITEMCLICKED_HANDLE(QVariant msg);
void MYMENU_ITEMCLICKED_HANDLE(QVariant msg);
void AW_GET_LIST_WIDGETS_HANDLE(QVariant msg);
void OPEN_OPTION_MENU_HANDLE(QVariant msg);
void SET_AW_WIDGET_HANDLE(QVariant msg);
void CLICK_DISP_OFF_HANDLE(QVariant msq);

void ALL_MENUS_LIST_PAGE_MOVING_HANDLE(QVariant msg);
void HOME_LIST_PAGE0_MOVING_HANDLE(QVariant msg);
void HOME_LIST_PAGE1_MOVING_HANDLE(QVariant msg);
void HOME_LIST_PAGE2_MOVING_HANDLE(QVariant msg);
void HOME_LIST_PAGE3_MOVING_HANDLE(QVariant msg);
void HOME_LIST_PAGE4_MOVING_HANDLE(QVariant msg);
//20170427001_Add Begin
void SETUP_LIST_PAGE1_MOVING_HANDLE(QVariant msg);
void SETUP_LIST_PAGE2_MOVING_HANDLE(QVariant msg);
void SETUP_LIST_PAGE3_MOVING_HANDLE(QVariant msg);
void HOME_NOTIFY_SHOW_AV_WIDGET_PAGE_HANDLE(QVariant msg);
// For PopUp
void SHOW_POPUP_AD_NOTIFY_HANDLER(QVariant msg);
// For My menu
void MY_MENU_ADD_DEL_HANDLER(QVariant msg);
void MY_MENU_MOVE_ITEM_HANDLER(QVariant msg);
void MOVE_FOCUS_STATE_TO_AW_HANDLE(QVariant msg);
void MOVE_FOCUS_STATE_TO_THIS_APP_HANDLE(QVariant msg);
void OPEN_SXM_SUBCRIPTION_HANDLER(QVariant msg);


void SHOW_POPUP_HANDLE(QVariant msg);
void HIDE_POPUP_HANDLE(QVariant msg);
void GOTO_HOME_CUSTOMIZE_HANDLE(QVariant msg);
void CLOSE_SETTING_WIDGET_HANDLE(QVariant msg);

void POPUP_YES_BUTTON_CLICK_HANDLER(QVariant msg);
void POPUP_NO_BUTTON_CLICK_HANDLER(QVariant msg);

// For Back to Main List
void BACK_TO_MAIN_LIST(QVariant msg);


QMap<uint, EVT_TRIGGER> evtOperation =
{
//    { HMIEVENTS::EVT_GOTO_ALL_SCREEN_ITEMS,                             {false,     MAIN_SCREEN_MENU_GOTO_ALL_SCREEN_ITEMS,                 "" }},
//    { HMIEVENTS::EVT_MAIN_LIST_ITEMCLICKED,                             {false,     MAIN_LIST_ITEMCLICKED_HANDLE,                           "" }},
//    { HMIEVENTS::EVT_SUBMENU_BLUELINK_ITEMCLICKED,                      {false,     SUBMENU_BLUELINK_ITEMCLICKED_HANDLE,                    "" }},
//    { HMIEVENTS::EVT_SUBMENU_MEDIA_ITEMCLICKED,                         {false,     SUBMENU_MEDIA_ITEMCLICKED_HANDLE,                       "" }},
//    { HMIEVENTS::EVT_SUBMENU_SETUP_ITEMCLICKED,                         {false,     SUBMENU_SETUP_ITEMCLICKED_HANDLE,                       "" }},
//    { HMIEVENTS::EVT_SUBMENU_DATASERVICE_ITEMCLICKED,                   {false,     SUBMENU_DATASERVICE_ITEMCLICKED_HANDLE,                 "" }},
//    { HMIEVENTS::EVT_SUBMENU_INFORMATION_ITEMCLICKED,                   {false,     SUBMENU_INFORMATION_ITEMCLICKED_HANDLE,                 "" }},
//    { HMIEVENTS::EVT_MYMENU_ITEMCLICKED,                                {false,     MYMENU_ITEMCLICKED_HANDLE,                              "" }},
//    { HMIEVENTS::EVT_OPEN_AW_OPION_MENU,                                {false,     AW_GET_LIST_WIDGETS_HANDLE,                             "" }},
//    { HMIEVENTS::EVT_OPEN_OPION_MENU,                                   {false,     OPEN_OPTION_MENU_HANDLE,                                "" }},
//    { HMIEVENTS::EVT_SET_AW_WIDGET,                                     {false,     SET_AW_WIDGET_HANDLE,                                   "" }},
//    { HMIEVENTS::EVT_CLICK_DISP_OFF,                                    {false,     CLICK_DISP_OFF_HANDLE,                                  "" }},
//    { HMIEVENTS::EVT_CLOSE_SETTING_WIDGET,                              {false,     CLOSE_SETTING_WIDGET_HANDLE,                  "" }},

//    { HMIEVENTS::EVT_HOME_LIST_PAGE0_MOVING,                            {false,     HOME_LIST_PAGE0_MOVING_HANDLE,                          "" }},
//    { HMIEVENTS::EVT_HOME_LIST_PAGE1_MOVING,                            {false,     HOME_LIST_PAGE1_MOVING_HANDLE,                          "" }},
//    { HMIEVENTS::EVT_HOME_LIST_PAGE2_MOVING,                            {false,     HOME_LIST_PAGE2_MOVING_HANDLE,                          "" }},
//    { HMIEVENTS::EVT_HOME_LIST_PAGE3_MOVING,                            {false,     HOME_LIST_PAGE3_MOVING_HANDLE,                          "" }},
//    { HMIEVENTS::EVT_HOME_LIST_PAGE4_MOVING,                            {false,     HOME_LIST_PAGE4_MOVING_HANDLE,                          "" }},

//    { HMIEVENTS::EVT_HOME_NOTIFY_SHOW_WIDGET_PAGE,                   {false,     HOME_NOTIFY_SHOW_AV_WIDGET_PAGE_HANDLE,                          "" }},

//    //  FOR MY MENU
//    { HMIEVENTS::EVT_ADD_DEL_MY_MENU,                                   {false,     MY_MENU_ADD_DEL_HANDLER,                                "" }},
//    { HMIEVENTS::EVT_MOVE_MY_MENU,                                      {false,     MY_MENU_MOVE_ITEM_HANDLER,                              "" }},
//    //EVT_SHOW_POPUP_AD_NOTIFY
//    { HMIEVENTS::EVT_SHOW_POPUP_AD_NOTIFY,                              {false,     SHOW_POPUP_AD_NOTIFY_HANDLER,                           "" }},
//    { HMIEVENTS::EVT_MOVE_FOCUS_STATE_TO_AW,                            {false,     MOVE_FOCUS_STATE_TO_AW_HANDLE,                          "" }},
//    { HMIEVENTS::EVT_MOVE_FOCUS_STATE_TO_THIS_APP,                      {false,     MOVE_FOCUS_STATE_TO_THIS_APP_HANDLE,                    "" }},
//    { HMIEVENTS::EVT_OPEN_SXM_SUBCRIPTION,                              {false,     OPEN_SXM_SUBCRIPTION_HANDLER,                           "" }},

//    // FOR POPUP ONSCREEN
//    { HMIEVENTS::EVT_REQUEST_SHOW_POPUP,                              {false,     SHOW_POPUP_HANDLE,                           "" }},
//    { HMIEVENTS::EVT_REQUEST_HIDE_POPUP,                              {false,     HIDE_POPUP_HANDLE,                           "" }},
//    { HMIEVENTS::EVT_GOTO_HOME_CUSTOMIZE,                             {false,     GOTO_HOME_CUSTOMIZE_HANDLE,                  "" }},
//    { HMIEVENTS::EVT_POPUP_YES_BUTTON_CLICK,                          {false,     POPUP_YES_BUTTON_CLICK_HANDLER,              "" }},
//    { HMIEVENTS::EVT_POPUP_NO_BUTTON_CLICK,                           {false,     POPUP_NO_BUTTON_CLICK_HANDLER,               "" }},

//    //FOR BACK TO MAIN LIST
//    { HMIEVENTS::EVT_BACK_TO_MAIN_LIST,                                 {false,     BACK_TO_MAIN_LIST,               "" }},
};

// evtTranstion
QMap<uint, EVT_TRIGGER> evtTranstion =
{
//    { HMIEVENTS::EVT_GOTO_SCREEN_WIDE_ALL_ITEMS,         {true,  NULL,                              SCREEN_HOMESCREEN_WIDE_ALL_ITEMS        }},
//    { HMIEVENTS::EVT_GOTO_SCREEN_NORM_ALL_ITEMS,         {true,  NULL,                              SCREEN_HOMESCREEN_NORM_ALL_ITEMS        }},
//    { HMIEVENTS::EVT_GOTO_SCREEN_ALL_MENUS,              {true,  NULL,                              SCREEN_HOMESCREEN_ALL_MENUS             }},

//    { HMIEVENTS::EVT_GOTO_SCREEN_HOMESCREEN_QUICK_GUIDE, {true,  NULL,                              SCREEN_HOMESCREEN_QUICK_GUIDE           }},
//    { HMIEVENTS::EVT_GOTO_QUICK_GUIDE_BASICLAYOUT,       {true,  NULL,                              SCREEN_HOMESCREEN_QUICKGUIDE_BASICLAYOUT        }},
//    { HMIEVENTS::EVT_GOTO_SCREEN_SUBMENU_SETUP,          {true,  NULL,                              SCREEN_HOMESCREEN_SUBMENU_SETUP         }},
//    { HMIEVENTS::EVT_GOTO_SCREEN_SUBMENU_MEDIA,          {true,  NULL,                              SCREEN_HOMESCREEN_SUBMENU_MEDIA         }},
//    { HMIEVENTS::EVT_GOTO_SCREEN_DATA_SERVICE,           {true,  NULL,                              SCREEN_HOMESCREEN_SUBMENU_DATA_SERVICE  }},
//    { HMIEVENTS::EVT_GOTO_SCREEN_SUBMENU_INFOMATION,     {true,  NULL,                              SCREEN_HOMESCREEN_SUBMENU_INFORMATION   }},
//    { HMIEVENTS::EVT_GOTO_SCREEN_SUBMENU_EDIT_WIDGETS,   {true,  NULL,                              SCREEN_HOMESCREEN_SUBMENU_EDIT_WIDGETS  }},
//    { HMIEVENTS::EVT_GOTO_SCREEN_SUBMENU_EDIT_MENUS,     {true,  NULL,                              SCREEN_HOMESCREEN_SUBMENU_EDIT_MENUS    }},
//    //20170623002_add +s
//    { HMIEVENTS::EVT_GOTO_SCREEN_SUBMENU_SETTING_HOMESCREEN,	{true,  NULL,                              SCREEN_HOMESCREEN_SUBMENU_SETTING_HOMESCREEN   }},
//    //20170623002_add +e
//    //MY MENU
//    { HMIEVENTS::EVT_GOTO_MENU_MYMENU,                   {true,  NULL,                              SCREEN_HOMESCREEN_MYMENU                    }},
//    { HMIEVENTS::EVT_GOTO_MENU_MYMENU_SHORTCUTS_1ST,     {true,  NULL,                              SCREEN_HOMESCREEN_MYMENU_SHORTCUTS_1ST      }},
//    { HMIEVENTS::EVT_GOTO_MENU_MYMENU_SHORTCUTS_2ND,     {true,  NULL,                              SCREEN_HOMESCREEN_MYMENU_SHORTCUTS_2ND      }},
//    { HMIEVENTS::EVT_GOTO_MENU_MYMENU_SHORTCUTS_3RD,     {true,  NULL,                              SCREEN_HOMESCREEN_MYMENU_SHORTCUTS_3RD      }},
//    { HMIEVENTS::EVT_GOTO_MENU_MYMENU_DELETE,            {true,  NULL,                              SCREEN_HOMESCREEN_MYMENU_DELETE             }},
//    { HMIEVENTS::EVT_GOTO_MENU_MYMENU_MOVE,              {true,  NULL,                              SCREEN_HOMESCREEN_MYMENU_MOVE               }},
//    { HMIEVENTS::EVT_GOTO_HOME_CUSTOMIZE_WIDE,           {true,  NULL,                              SCREEN_HOME_CUSTOMIZE_WIDE_QML              }},
//    { HMIEVENTS::EVT_GOTO_HOME_CUSTOMIZE_NORM,           {true,  NULL,                              SCREEN_HOME_CUSTOMIZE_NORM_QML              }},
//    { HMIEVENTS::EVT_BACK_TO_PREV_SCREEN,                {true,  NULL,                              ""                                          }},

//    { HMIEVENTS::EVT_GOTO_HOME_SETTING_WIDGET,           {true,  NULL,                              SCREEN_HOME_SETTING_WIDGET_QML              }},
};

// ** Onscreen manager table //
OSD_DATA maptableOnsManager[] =
{
//    {ONSID_MYMENU_ADD_DEL_CONFIRMATION,                 OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_MYMENU_ADD_DEL_CONFIRMATION      },
//    {ONSID_MYMENU_ADD_DELETE_NOTIFY,                    OSDTYPE_NONE,       DURATION_5S,          QML_ONSCREEN_MYMENU_ADD_DELETE_NOTIFY         },
//    {ONSID_MYMENU_ADD_FULL_NOTIFY,                      OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_MYMENU_ADD_FULL_NOTIFY           },
//    {ONSID_HOME_POPUP_PHONEPROJECTION,                  OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_HOMESCREEN_PHONEPROJECTION       },
//    {ONSID_HOME_POPUP_PHONEPROJECTION_DURING_CALL,      OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_HOMESCREEN_SETUP_CONNECTIVITY_DURING_CALL       },
//    {ONSID_HOME_POPUP_PHONEPROJECTION_TMU_DURING_CALL,  OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_HOMESCREEN_SETUP_CONNECTIVITY_TMU_DURING_CALL       },
//    {ONSID_HOME_POPUP_PROJECTION_NOSET_AA,              OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_HOMESCREEN_SETUP_PROJECTION_NOSET_AA       },
//    {ONSID_HOME_POPUP_OK,                               OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_HOMESCREEN_OK    },
//    {ONSID_HOME_POPUP_MEDIA_NODEVICES,                  OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_HOMESCREEN_MEDIA_NODEVICES       },
//    {ONSID_HOME_POPUP_UNAVAILABLE,                      OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_HOMESCREEN_UNAVAILABLE       },
//    {ONSID_HOME_POPUP_FEATURE_UNAVAILABLE,              OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_HOMESCREEN_FEATURE_UNAVAILABLE       },
//    {ONSID_HOME_POPUP_SETUP_VR,                         OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_SUBMENU_SETUP_VOICE_RECOGNIZE    },
//    {ONSID_HOME_OPTION_MENU_AW,                         OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_OPTION_MENU_AW                   },
//    {ONSID_HOME_OPTION_MENU,                            OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_OPTION_MENU                      },
//    {ONSID_HOME_POPUP_SETUP_BLUETOOTH,                  OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_HOMESCREEN_SETUP_BLUETOOTH    },
//    {ONSID_HOME_POPUP_SETUP_SYSINFO_INACCESSIBLE,       OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_SUBMENU_SETUP_SYSINFO_INACCESSIBLE    },
//    {ONSID_HOME_SUBMENU_EMANUL_NOT_SUPPORT,             OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_SUBMENU_EMANUL_NOT_SUPPORT    },
//    {ONSID_HOME_POPUP_SXM_SUBCRIPTION,                  OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_OPTION_MENU_SXM_SUBCRIPTION    },
//    {ONSID_HOME_POPUP_YES_NO,                           OSDTYPE_NONE,       ONSFOREVER,           QML_ONSCREEN_POPUP_YES_NO    },

};

size_t _onsIDcnt = sizeof(maptableOnsManager)/sizeof(OSD_DATA);

#endif // SCREENEVTDEFINES_H
