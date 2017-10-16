#ifndef ONSCONTROLLER_H
#define ONSCONTROLLER_H

#include "CommonStructs.h"
#include "QMLController.h"
#include <QStack>
class OnsController
{

public:

    static OnsController* getInstance(SCREENTYPE_T type);
    OnsController(OnsController const&)   = delete;
    void operator=(OnsController const&)  = delete;

    void showOnscreen(unsigned int OnsID );
    void hideOnscreen(unsigned int OnsID );
    void deleteAllOSD();
    //Onscreen timeout function
    void timeoutDeleteOnscreen(unsigned int OnsID);
    QStack<uint> getListOnsShowing();

private:
    QStack<uint> onsHistory;
    explicit OnsController(SCREENTYPE_T type);
    virtual ~OnsController();
    OSD_DATA  selectedOns;
    OSD_DATA CurrentshowOnsTbl[ONSCOUNT_MAX];
    bool getOnscreenInfo(unsigned int OnsID );
    void setOnscreenTbl();

    SCREENTYPE_T getScrenType();
    SCREENTYPE_T m_screen;
};

#endif // ONSCONTROLLER_H
