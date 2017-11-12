#ifndef ONSCONTROLLER_H
#define ONSCONTROLLER_H
#include <QObject>
#include "CommonStructs.h"
#include "../QMLController/QMLController.h"
#include <QStack>

enum class ONS_NOTICE : int
{
    ONS_ADD_ONE = 0xF0,
    ONS_REMOVE_ONE,
    ONS_REMOVE_ALL,
};

class OnsController : public QObject
{
    Q_OBJECT
public:

    static OnsController* getInstance();
    OnsController(OnsController const&)   = delete;
    void operator=(OnsController const&)  = delete;

    void showOnscreen(unsigned int OnsID );
    void hideOnscreen(unsigned int OnsID );
    void deleteAllOSD();
    //Onscreen timeout function
    void timeoutDeleteOnscreen(unsigned int OnsID);
    QStack<uint> getListOnsShowing();
    void updateOnsHistory(uint onsID, ONS_NOTICE act);
private:
    QStack<uint> onsHistory;
    explicit OnsController();
    virtual ~OnsController();
    OSD_DATA  selectedOns;
    OSD_DATA CurrentshowOnsTbl[ONSCOUNT_MAX];
    bool getOnscreenInfo(unsigned int OnsID );
    void setOnscreenTbl();

signals:
    void onsHistoryChanged();
};

#endif // ONSCONTROLLER_H
