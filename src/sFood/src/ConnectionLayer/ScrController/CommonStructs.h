#ifndef COMMON_STRUCT
#define COMMON_STRUCT
#include <QObject>
#include "QTimerWrap.h"
#define CB_FUNC(funcname) void (*funcname)(QVariant msg, int scrType)
#define ONSCOUNT_MAX            10

#define TIMER_SET_MAX           50
#define ONS_DELTIMER_MAX        10
#define ONSID_MAX               65535
#define EVT_TRANS_BACK          65535
#define ONSFOREVER              0
#define ONS_DUR_5_SEC           5000
#define OSDTYPE_NONE            0
#define ACT_NONE              false
#define ACT_TRANSITION        true
typedef struct _evt_trigger
{
    bool            istrans;
    CB_FUNC(func);
    QString             toForm;
} EVT_TRIGGER;

typedef struct OnsDataStruct
{
    unsigned int OnscreenID;
    unsigned char OnsType;
    unsigned int DspTimer;
    QString  QmlPath;

} OSD_DATA;

typedef struct timer_ctrl
{
    unsigned int  timer_param;
    QTimerWrap* timtbl;

} TIMER_CTRL;

typedef struct ons_timer_ctrl
{
    unsigned int  onsID;
    unsigned int  timer_param;
    QTimerWrap* onstimtbl;
} ONS_TIMER_CTRL;

enum SCREENTYPE_T : int {
    FRONT_SCREEN = 0,
    REAR_SCREEN,
    SCREENTYPE_MAX
};

// For local popup
enum ENUM_LOCAL_ONS {
    E_LOCAL_ONS_SHOWING     = 0x0A,   // has ons is showing
    E_LOCAL_ONS_OFF         = 0x0B,        // has not ons showing
};


typedef enum
{
    LAYER_BASE = 0,
    LAYER_BASE_ONS = 1
} eLayerId;

// Onscreen manager table //
extern OSD_DATA maptableOnsManager[ONSID_MAX];


// Screen manager table //
extern QMap<uint, EVT_TRIGGER> evtOperation;
extern QMap<uint, EVT_TRIGGER> evtTranstion;

#endif //COMMON_STRUCT
