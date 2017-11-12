#ifndef APPHOMEDEFS_H
#define APPHOMEDEFS_H

#include <QObject>
#include <QString>
#include <qstringlist.h>
#include <QList>
#include<QTranslator>
#include <QMap>
#include <QHash>
#include "AppHomeEnums.h"

#define APPHOME_LANGUAGE_DIR            QString("/app/share/AppHomeScreen/localization/qm/")

#define VALUE_OF_BIT(target,pos) ((target) >> (pos) & 1)

#define DEFAULT_LANGUAGE             1           // EN is default language
#define DEFAULT_MEDIA_FOCUSINDEX     0
#define DEFAULT_BLUELINK_FOCUSINDEX  0
#define DEFAULT_SETUP_FOCUSINDEX     0

/* AV widget state */
#define DEF_AV_WIDGET_STATE_INVISIBLE       0
#define DEF_AV_WIDGET_STATE_VISIBLE         1
#define DEF_CLIMATE_WIDGET_STATE_INVISIBLE  0
#define DEF_CLIMATE_WIDGET_STATE_VISIBLE    1

/* REGIONAL LANGUAGE */

#define CA_EXT  "-CA.qm"
#define CH_EXT  "-CH.qm"
#define EU_EXT  "-EU.qm"
#define IR_EXT  "-IR.qm"
#define KO_EXT  "-KO.qm"
#define ME_EXT  "-ME.qm"
#define RU_EXT  "-RU.qm"
#define US_EXT  "-US.qm"
#define AU_EXT  "-AU.qm"
#define GENERAL_EXT ".qm"

#define LAN_EXT GENERAL_EXT
#define UNKNOW_DATA -1


#define APP_HOME_LAN_EN                  APPHOME_LANGUAGE_DIR+QString("translation_en")
#define APP_HOME_LAN_KO                  APPHOME_LANGUAGE_DIR+QString("translation_ko")
#define APP_HOME_LAN_ZH_CH               APPHOME_LANGUAGE_DIR+QString("translation_zh-cmn")
#define APP_HOME_LAN_ZH_YUE              APPHOME_LANGUAGE_DIR+QString("translation_zh-cmn")
#define APP_HOME_LAN_PT                  APPHOME_LANGUAGE_DIR+QString("translation_pt")
#define APP_HOME_LAN_EN_GB               APPHOME_LANGUAGE_DIR+QString("translation_en-gb")
#define APP_HOME_LAN_EN_US               APPHOME_LANGUAGE_DIR+QString("translation_en-DHPE")
#define APP_HOME_LAN_FR                  APPHOME_LANGUAGE_DIR+QString("translation_fr-eu")
#define APP_HOME_LAN_IT                  APPHOME_LANGUAGE_DIR+QString("translation_it")
#define APP_HOME_LAN_DE                  APPHOME_LANGUAGE_DIR+QString("translation_ge")
#define APP_HOME_LAN_ES                  APPHOME_LANGUAGE_DIR+QString("translation_es-eu")
#define APP_HOME_LAN_RU                  APPHOME_LANGUAGE_DIR+QString("translation_ru")
#define APP_HOME_LAN_NL                  APPHOME_LANGUAGE_DIR+QString("translation_nl")
#define APP_HOME_LAN_SV                  APPHOME_LANGUAGE_DIR+QString("translation_sv")
#define APP_HOME_LAN_PL                  APPHOME_LANGUAGE_DIR+QString("translation_pl")
#define APP_HOME_LAN_TR                  APPHOME_LANGUAGE_DIR+QString("translation_tr")
#define APP_HOME_LAN_CS                  APPHOME_LANGUAGE_DIR+QString("translation_cs")
#define APP_HOME_LAN_DA                  APPHOME_LANGUAGE_DIR+QString("translation_da")
#define APP_HOME_LAN_SK                  APPHOME_LANGUAGE_DIR+QString("translation_sk")
#define APP_HOME_LAN_AR                  APPHOME_LANGUAGE_DIR+QString("translation_ar")
#define APP_HOME_LAN_FR_NA               APPHOME_LANGUAGE_DIR+QString("translation_fr-na")
#define APP_HOME_LAN_ES_NA               APPHOME_LANGUAGE_DIR+QString("translation_es-na")

// Font Name
#define FONT_DIR                             "/app/share/fonts/"
#define CUBEB_30                             "30_CubeB.ttf"
#define CUBER_31                             "31_CubeR.ttf"
#define DFHEI5                               "DFHEI5.ttf"
#define DINNEXTPRO_FOR_HYUNDAI_MEDIUM        "DINNextPro_for_Hyundai-Medium.ttf"
#define DINNEXTPRO_FOR_HYUNDAI_REGULAR       "DINNextPro_for_Hyundai-Regular.ttf"
#define AMIRI_BOLD                           "amiri-bold.ttf"
#define AMIRI_REGULAR                        "amiri-regular-bold.ttf"
#define DROID_NASKH_SHIFT_ALT                "Droid Naskh Shift Alt.ttf"

#define DEF_SPECIAL_FONT_R                        "DFHeiW5-A"
#define DEF_ARABIC_FONT_R                         "Droid Naskh Shift Alt"
#define DEF_FE_FONT_R                             "DINNextPro_for_Hyundai"
#define DEF_RJ_FONT_R                             "CubeR"

#define DEF_SPECIAL_FONT_B                        "DFHeiW5-A"
#define DEF_ARABIC_FONT_B                         "Droid Naskh Shift Alt"
#define DEF_FE_FONT_B                             "DINNextPro_for_Hyundai_Medium"
#define DEF_RJ_FONT_B                             "CubeB"

#define HOME_RESOURCE_DIR                           "/app/share"
#define HOME_APPDATA_DIR                            "/app/share/AppHomeScreen/"
#define HOME_MAIN_QML                               HOME_APPDATA_DIR + QString("/qml/HomeScreen/main.qml")

#ifdef LOW_SPEC
#define CATEGORY_WIDTH                              168
#define STATUSBAR_HEIGHT                            64
#define Home_WIDTH                                  1280 - CATEGORY_WIDTH
#define Home_HEIGHT                                 720 - STATUSBAR_HEIGHT
#else
#define CATEGORY_WIDTH                              168
#define STATUSBAR_HEIGHT                            64
#define Home_WIDTH                                  1280 - CATEGORY_WIDTH
#define Home_HEIGHT                                 720 - STATUSBAR_HEIGHT

// Icon number of regions in main home sreen
#define MAIN_MENU_KR_NUM_ICONS                      7
#define MAIN_MENU_NA_NUM_ICONS                      8

#endif

//define onscreen duration
#define DURATION_10S                                10000
#define DURATION_5S                                 5000
#define DURATION_3S                                 3000

// define LCD display
#define LCD_BACK_LIGHT_CTL_LCD_ALL_OFF              0x00
#define LCD_BACK_LIGHT_CTL_LCD_ALL_ON               0x01
#define LCD_BACK_LIGHT_CTL_LCD_FRONT_OFF            0x10
#define LCD_BACK_LIGHT_CTL_LCD_FRONT_ON             0x11
#define LCD_BACK_LIGHT_CTL_LCD_REAR_1_OFF           0x20
#define LCD_BACK_LIGHT_CTL_LCD_REAR_1_ON            0x21
#define LCD_BACK_LIGHT_CTL_LCD_REAR_2_OFF           0x30
#define LCD_BACK_LIGHT_CTL_LCD_REAR_2_ON            0x31

#define AUDIO_BEEP_TYPE                             0x00


#define MICOM_SERVICE                               "com.lge.car.micom"
#define MICOM_PATH_IHU                              "/Ihu"
#define MICOM_AUDIOMANAGER_SERVICE                  "org.genivi.audiomanager"
#define MICOM_AUDIOMANAGER_PATH                     "/org/genivi/audiomanager/commandinterface"
#define MICOM_STATUS_MESSAGE                        "MICOM_STATUS_MESSAGE"


// define string key for AW Widgets List
#define STR_ASSISTANT_WINDOW_AVOFF                  "STR_ASSISTANT_WINDOW_AVOFF"            //"AVOFF"
#define STR_ASSISTANT_WINDOW_BT_AUDIO               "STR_ASSISTANT_WINDOW_BT_AUDIO"         //"Bluetooth Audio"
#define STR_ASSISTANT_WINDOW_BT_CALL                "STR_ASSISTANT_WIDGET_BT_CALL"          //"Bluetooth Call"
#define STR_ASSISTANT_WINDOW_CLIMATE                "STR_ASSISTANT_WINDOW_CLIMATE"          //"Climate"
#define STR_ASSISTANT_WINDOW_DMB                    "STR_ASSISTANT_WINDOW_DMB"              //"DMB"
#define STR_ASSISTANT_WINDOW_MEDIA                  "STR_ASSISTANT_WINDOW_MEDIA"            //"Media"
#define STR_ASSISTANT_WINDOW_NAVI                   "STR_ASSISTANT_WINDOW_NAVI"             //"Map"
#define STR_ASSISTANT_WINDOW_RADIO                  "STR_ASSISTANT_WINDOW_RADIO"            //"Radio"
#define STR_ASSISTANT_WINDOW_TELEMATICS             "STR_ASSISTANT_WINDOW_TELEMATICS"       //"Telematics"
#define STR_ASSISTANT_WINDOW_WEATHER                "STR_ASSISTANT_WINDOW_WEATHER"          //"Weather"
#define STR_ASSISTANT_WINDOW_CLOCK                  "STR_ASSISTANT_WINDOW_CLOCK"            //"Clock"
#define STR_ASSISTANT_WINDOW_SXMRADIO               "STR_ASSISTANT_WINDOW_SXMRADIO"         //"SMX"
#define STR_ASSISTANT_WINDOW_FCEV                   "STR_ASSISTANT_WINDOW_FCEV"             //"FCEV"
#define STR_ASSISTANT_WINDOW_AUDIO_SOURCE           "STR_ASSISTANT_WINDOW_AUDIO_SOURCE"
#define STR_HOME_NOTIFY_OSD_ONLY_AVAILABLE_FRONT    QObject::tr("STR_HOME_NOTIFY_OSD_ONLY_AVAILABLE_FRONT")
#define STR_HOME_NOTIFY_OSD_ONLY_AVAILABLE_REAR     QObject::tr("STR_HOME_NOTIFY_OSD_ONLY_AVAILABLE_REAR")

//my menu

#define DATA_PATH_COMMON                            "/app/data/"
#define APP_HOME_DATA_PATH                          "/app/data/AppHomeScreen/"

#define APP_HOME_CUSTOM_LAYOUT_FOLDER_PATH          "/app/data/AppHomeScreen/CustomLayout"
//#define APP_HOME_CUSTOM_LAYOUT_DATA_PATH            "/app/data/AppHomeScreen/CustomLayout/CustomLayout.ini"
#define APP_HOME_CUSTOM_LAYOUT_DATA_FILE_NAME       "CustomLayout.ini"
#define APP_HOME_CUSTOM_LAYOUT_DATA_PATH            "/app/data/AppHomeScreen/CustomLayoutDB/CustomLayoutDB"

#define CUSTOM_LAYOUT_DB_FOLDER_PATH                       "/app/data/AppHomeScreen/CustomLayoutDB/"
#define CUSTOM_LAYOUT_DB_CONNECTION_NAME                   "CustomLayoutDB_Connection"
#define CUSTOM_LAYOUT_DB_TABLE_NAME                        "CustomLayout"
#define CUSTOM_LAYOUT_DB_TABLE_NAME_FR                     "CustomLayoutFront"

// 26/04/2017_20170426001 Add begin
#define MENU_HOME_LAYOUT_NAME                      "MenuHome"
// 26/04/2017_20170426001 Add end

//20170616003_add +s
#define MENU_MEDIA_GATE_NAME                     "MenuMediaGate"
//20170616003_add +e

#define CUSTOM_WIDGET_SETTING_DB_TABLE_NAME_FR                      "WidgetSettingFront"

#define CUSTOM_LAYOUT_DB_NAME                              "CustomLayoutDB"
#define CUSTOM_LAYOUT_DB_HOST_NAME                         "CustomLayout_HostName"
#define CUSTOM_LAYOUT_DB_USER_NAME                         "CustomLayout_AppHome"
#define CUSTOM_LAYOUT_DB_PASSWORD                       "LG@AppHome@CustomLayout"

// 20170427001_Add Begin: setup main screen layout
#define SETUP_DATA_PATH                             "/app/data/AppHomeScreen/SetupDB/SetupDB"
#define SETUP_DB_FOLDER_PATH                        "/app/data/AppHomeScreen/SetupDB/"
#define SETUP_DB_CONNECTION_NAME                    "SetupDB_Connection"
#define SETUP_DB_TABLE_NAME                         "Setup"


#define SETUP_DB_NAME                               "SetupDB"
#define SETUP_DB_HOST_NAME                          "Setup_HostName"
#define SETUP_DB_USER_NAME                          "Setup_AppHome"
#define SETUP_DB_PASSWORD                           "LG@AppHome@Setup"

#define MYMENU_DB_FOLDER_PATH                       "/app/data/AppHomeScreen/MyMenuDB/"
#define MYMENU_DB_CONNECTION_NAME                   "MyMenuDB_Connection"
#define MYMENU_DB_TABLE_NAME                        "MyMenu"
#define MYMENU_DB_TABLE_NAME_FR                     "MyMenuFront"
#define MYMENU_DB_TABLE_NAME_R                      "MyMenuRear"
#define MYMENU_DB_NAME                              "MyMenuDB"
#define MYMENU_DB_HOST_NAME                         "MyMenu_HostName"
#define MYMENU_DB_USER_NAME                         "MyMenu_AppHome"
#define MYMENU_DB_PASSWORD                          "LG@AppHome@MyMenu"

#define MAX_NUMBER_WIDGET_FRONT        2

#define NAVI_GUIDANCE_TEXT          "STR_MYMENU_NAVI_ROUTE_RESUME"
#define NAVI_STOP_GUIDANCE_TEXT     "STR_MYMENU_NAVI_ROUTE_STOP"

#define MAX_MYMENU_ITEMS            25
//Common define
#define IS_VEHICLE_SP(_ACTUAL_CONDITION, _SP_CONDITION)     ((bool)(0x00030000 & _ACTUAL_CONDITION & _SP_CONDITION))
#define IS_REGION_SP(_ACTUAL_CONDITION, _SP_CONDITION)      ((bool)(0x000007FF &_ACTUAL_CONDITION & _SP_CONDITION))
#define IS_ITEM_SP(_ACTUAL_CONDITION, _SP_CONDITION)  IS_VEHICLE_SP(_ACTUAL_CONDITION, _SP_CONDITION) && IS_REGION_SP(_ACTUAL_CONDITION, _SP_CONDITION)

#define SP_NONE             0x00000000
//#define SP_FRONT            0x10000000
//#define SP_REAR             0x20000000
#define SP_ALL_SCREEN       0x30000000
#define SP_RJ               0x00010000
#define SP_FE               0x00020000
#define SP_RJ_FE            (SP_RJ | SP_FE)
#define SP_ALL_REGION       0x000007FF
#define SP_KR               0x00000001 // 0000 0000 0001
#define SP_US               0x00000002 // 0000 0000 0010
#define SP_CN               0x00000004 // 0000 0000 0100
#define SP_GN               0x00000008 // 0000 0000 1000
#define SP_ME               0x00000010 // 0000 0001 0000
#define SP_EU               0x00000020 // 0000 0010 0000
#define SP_CA               0x00000040 // 0000 0100 0000
#define SP_RU               0x00000080 // 0000 1000 0000
#define SP_TK               0x00000100 // 0001 0000 0000
#define SP_AU               0x00000200 // 0010 0000 0000
#define SP_JP               0x00000400 // 0100 0000 0000
#define SP_EN               0x00000800 // 1000 0000 0000
#define SP_NA               (SP_US | SP_CA)

//car state
#define CAR_PARKING_STATE                           0x04
#define CAR_IS_DRIVING                              0x00
#define CAR_IS_STOPED                               0x01
#define IGN_STATUS                                  0x01

#define CUSTOM_BUTTON                               0x00
#define CUSTOM_HOME                                 0x04
#define CUSTOM_UVO                                  0x01
#define CUSTOM_MYMENU                               0x05
#define CUSTOM_DISPLAY_OFF                          0x08
#define CUSTOM_INFORMATION                          0x09
#define CUSTOM_INVALID                              -1
#define CUSTOM_BUTTON_LIST                          0x00

struct POPUP_DATA
{
    int ucDisplay;
    int ucAction;
    int ucType;
    int nNotiId;
    int nTimeOut;
    int nTitleSize;
    int nBodySize;
};

/*
                   * Language setting
                   */
typedef struct {
    AppHomeEnums::ENUM_LANGUAGE value;
} languageSetting_t;

typedef struct{
    char type; //General, Alert, Volume, Status
    char evt; //EVT
    char show; // hide = 0 , show = 1
    char timeOut;  //
    char appID;
    char icon[5];
    //QString text;
}CMD_t;

typedef struct {
    int type;
    int evt;
    int specification; // (ex. AV OSD, SOS OSD, diag OSD, etc)
    int show;
    int timeOut;
    int appID;
    int icon[5];
} OSD_DATA_t ;


typedef enum{
    STATUS_ICON,
    STATUS_CLOCK,
    OSD_GENERAL,
    OSD_ALERT,
    OSD_VOLUME,
    STATUS_HOME,
}EVT_T;

const QHash<AppHomeEnums::ENUM_LANGUAGE, QString> m_multiLanguageMap = {

    { AppHomeEnums::E_LANGUAGE_UNKNOWN    ,     "en-us" },
    { AppHomeEnums::E_LANGUAGE_KO         ,     "ko" },
    { AppHomeEnums::E_LANGUAGE_EN_US      ,     "en-us" },
    { AppHomeEnums::E_LANGUAGE_EN_UK      ,     "en-gb" },
    { AppHomeEnums::E_LANGUAGE_CN_SC      ,     "zh-cmn" },
    { AppHomeEnums::E_LANGUAGE_CN_TC      ,     "zh-cmn" },
    { AppHomeEnums::E_LANGUAGE_FR         ,     "fr-eu" },
    { AppHomeEnums::E_LANGUAGE_ES         ,     "es-eu" },
    { AppHomeEnums::E_LANGUAGE_AR         ,     "ar" },
    { AppHomeEnums::E_LANGUAGE_CS         ,     "cs" },
    { AppHomeEnums::E_LANGUAGE_DA         ,     "da" },
    { AppHomeEnums::E_LANGUAGE_DE         ,     "ge" },
    { AppHomeEnums::E_LANGUAGE_IT         ,     "it" },
    { AppHomeEnums::E_LANGUAGE_NL         ,     "nl" },
    { AppHomeEnums::E_LANGUAGE_PL         ,     "pl" },
    { AppHomeEnums::E_LANGUAGE_PT         ,     "pt" },
    { AppHomeEnums::E_LANGUAGE_RU         ,     "ru" },
    { AppHomeEnums::E_LANGUAGE_SK         ,     "sk" },
    { AppHomeEnums::E_LANGUAGE_SV         ,     "sv" },
    { AppHomeEnums::E_LANGUAGE_TR         ,     "tr" },
    { AppHomeEnums::E_LANGUAGE_FR_NA      ,     "fr-na" },
    { AppHomeEnums::E_LANGUAGE_ES_NA      ,     "es-na" },
    //        { AppHomeEnums::E_LANGUAGE_EN_IN      ,     "en" },
    { AppHomeEnums::E_LANGUAGE_NR         ,     "norwe" },
    { AppHomeEnums::E_LANGUAGE_FN         ,     "sv" },
    //        { AppHomeEnums::E_LANGUAGE_INA        ,     "en" },
    { AppHomeEnums::E_LANGUAGE_PT_BR      ,     "pt" },
    //        { AppHomeEnums::E_LANGUAGE_MAS        ,     "en" },
    { AppHomeEnums::E_LANGUAGE_HU         ,     "hung" },
    { AppHomeEnums::E_LANGUAGE_EN_AU      ,     "en-gb" },
    { AppHomeEnums::E_LANGUAGE_JP         ,     "jp" },
    { AppHomeEnums::E_LANGUAGE_INVALID    ,     "en-us" },
};

typedef enum {
    //main List
    ITEM_ID_FCEV                    = 0,
    ITEM_ID_MAP                     ,
    ITEM_ID_NAVI                    ,
    ITEM_ID_QIBLA                   ,
    ITEM_ID_RADIO                   ,
    ITEM_ID_EV                      ,
    ITEM_ID_NMODE                   ,
    ITEM_ID_AUX                     ,
    ITEM_ID_ANDROID_AUTO            ,
    ITEM_ID_APPLE_CARPLAY           ,
    ITEM_ID_SOUND_MOOD              ,//10
    ITEM_ID_QUICKGUIDE              ,
    ITEM_ID_DMB                     ,
    ITEM_ID_SIRIUSXM                ,
    ITEM_ID_DAB                     ,
    ITEM_ID_MEDIA                   ,
    ITEM_ID_DATA_SERVICE            ,
    ITEM_ID_SXMDATA                 ,
    ITEM_ID_PHONE                   ,
    ITEM_ID_PROJECTION              ,
    ITEM_ID_UVO_BLUELINK            ,//20
    ITEM_ID_CLIMATE                 ,
    ITEM_ID_VOICE_MEMO              ,
    ITEM_ID_MYMENU                  ,
    ITEM_ID_SETUP                   ,
    ITEM_ID_PLUGIN_NAVI             ,
    ITEM_ID_PLUGIN_AV               ,
    ITEM_ID_PLUGIN_CLIMATE          ,
    ITEM_ID_PLUGIN_CLOCK            ,
    ITEM_ID_INFORMATION             ,
    ITEM_ID_CONTACTS                ,//30
    ITEM_ID_ALLMENU                 ,
    //UVO
    ITEM_ID_UVO_DRIVING_INFO        = 100,
    ITEM_ID_UVO_SEND_TO_CAR         ,
    ITEM_ID_UVO_VEHICLE_DIAG        ,
    ITEM_ID_UVO_CONCIERGE           ,
    ITEM_ID_UVO_SETUP               ,
    ITEM_ID_UVO_SEND_TO_CAR_NA      ,
    ITEM_ID_UVO_MAINTENANCE         ,
    ITEM_ID_UVO_SOS                 ,
    ITEM_ID_UVO_ACN                 ,
    ITEM_ID_UVO_LOCAL_SHARE         ,
    ITEM_ID_UVO_ROADSIDE_ASSIT      ,
    ITEM_ID_UVO_ESERVICES_GUIDE     ,
    ITEM_ID_UVO_MY_POIS             ,
    ITEM_ID_UVO_911_CONNECT         ,

    //data services
    ITEM_ID_DS_HD_WEATHER           = 200,
    ITEM_ID_DS_HD_TRAFFIC           ,
    ITEM_ID_DS_SIRIUSXM_WEATHER     ,
    ITEM_ID_DS_SIRIUSXM_TRAFFIC     ,
    ITEM_ID_DS_SIRIUSXM_FUEL_PRICES ,
    ITEM_ID_DS_SIRIUSXM_STOCK       ,
    ITEM_ID_DS_SIRIUSXM_SPORTS      ,
    ITEM_ID_DS_SIRIUSXM_MOVIES      ,
    ITEM_ID_DS_HD_DOPPLER_RADAR     ,

    //infor
    ITEM_ID_INFO_TRAFFIC            = 300,
    ITEM_ID_INFO_LIVE_POI           ,
    ITEM_ID_INFO_WEATHER            ,
    ITEM_ID_INFO_PARKING            ,
    ITEM_ID_INFO_FUEL               ,
    ITEM_ID_INFO_SATELLITE          ,
    //media
    ITEM_ID_MEDIA_MYMUSIC           = 400,
    ITEM_ID_MEDIA_USB_MUSIC_FRONT   ,
    ITEM_ID_MEDIA_USB_VIDEO_FRONT   ,
    ITEM_ID_MEDIA_USB_MUSIC_REAR    ,
    ITEM_ID_MEDIA_USB_VIDEO_REAR    ,
    ITEM_ID_MEDIA_IPOD_FRONT        ,
    ITEM_ID_MEDIA_IPOD_REAR         ,
    ITEM_ID_MEDIA_BT_MUSIC          ,
    ITEM_ID_MEDIA_DISC_CD           ,
    ITEM_ID_MEDIA_DISC_DVD          ,
    ITEM_ID_MEDIA_DISC_MP3          ,
    ITEM_ID_MEDIA_AUX               ,
    ITEM_ID_MEDIA_APPLE_CARPLAY     ,
    ITEM_ID_MEDIA_ANDROID_AUTO      ,
    ITEM_ID_MEDIA_MIRROR_LINK       ,
    ITEM_ID_MEDIA_BAIDU_CARLIFE     ,

    //setup
    ITEM_ID_SETUP_VEHICLE           = 500,
    ITEM_ID_SETUP_NAVI              ,
    ITEM_ID_SETUP_SOUND             ,
    //20170517_Add Begin: add new app id
    //20170606004_Add Begin: remove engineSound
    ITEM_ID_SETUP_DISPLAY           ,
    ITEM_ID_SETUP_BLUETOOTH         ,
    ITEM_ID_SETUP_PHONE_PROJECTION  ,
    ITEM_ID_SETUP_CUSTOM_BUTTON     ,
    ITEM_ID_SETUP_WIFI              ,
    ITEM_ID_SETUP_DATE_TIME         ,
    ITEM_ID_SETUP_LANGUAGE          ,
    ITEM_ID_SETUP_KEYPAD            ,
    ITEM_ID_SETUP_SCREENSAVER       ,
    ITEM_ID_SETUP_REAR_LOCK         ,
    ITEM_ID_SETUP_ADVANCED          ,
    ITEM_ID_SETUP_SYSTEM_INFO       ,
    ITEM_ID_SETUP_HEADLIGHT_OFF_ALERT,
    ITEM_ID_SETUP_HOME_SCREEN       ,
    ITEM_ID_SETUP_UNIT              ,
    ITEM_ID_SETUP_GENERAL           ,
    ITEM_ID_SETUP_VOICE             ,
    //ITEM_ID_SETUP_EMANUAL             ,
    ITEM_ID_SETUP_UVO_BLUELINK      ,
    ITEM_ID_PLUGIN_FCEV             ,
    ITEM_ID_PLUGIN_WEATHER          ,
    //QuangNV16-20170622003_B
    ITEM_ID_HYBIRD,
    ITEM_ID_PHEV,
    //QuangNV16-20170622003_E
    //20170707005_add +s
    ITEM_ID_PLUGIN_PHEV             ,
    ITEM_ID_PLUGIN_N_MODE           ,
    //20170707005_add +s
    ITEM_ID_DRIVER_PROFILE,
    ITEM_ID_MAX,
} HOME_ITEM_INDX;

#endif // APPHOMEDEFS_H
