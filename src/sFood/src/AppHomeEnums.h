#ifndef APPHOMEENUMS_H
#define APPHOMEENUMS_H

#include <QObject>

class AppHomeEnums : public QObject
{
    Q_OBJECT
    Q_ENUMS( ENUM_LANGUAGE )
    Q_ENUMS( ENUM_LIST_TYPE )

public:
    typedef enum{
        E_LIST_INVALID,
        E_LIST_HOME_PAGE, // list all menus
        E_LIST_SETUP_MAIN,
        E_LIST_MENU_HOME,
        E_LIST_MEDIA_GATE,
    } ENUM_LIST_TYPE;

    enum ENUM_LANGUAGE {

        E_LANGUAGE_UNKNOWN = 0,
        E_LANGUAGE_KO,
        E_LANGUAGE_EN_US,
        E_LANGUAGE_EN_UK,            //< English (UK)
        E_LANGUAGE_CN_SC,            //< Peoples Republic Of China (Simplified Chinese)
        E_LANGUAGE_CN_TC,            //< Peoples Republic Of China (Traditional Chinese)
        E_LANGUAGE_FR,               //< European French
        E_LANGUAGE_ES,               //< European Spanish
        E_LANGUAGE_AR,               //< Arabic
        E_LANGUAGE_CS,               //< Czech
        E_LANGUAGE_DA,               //< Danish
        E_LANGUAGE_DE,               //< German
        E_LANGUAGE_IT,               //< Italian
        E_LANGUAGE_NL,               //< Dutch
        E_LANGUAGE_PL,               //< Polish
        E_LANGUAGE_PT,               //< Europeen Portuguese
        E_LANGUAGE_RU,               //< Russian
        E_LANGUAGE_SK,               //< Slovakia
        E_LANGUAGE_SV,               //< Swedish
        E_LANGUAGE_TR,               //< Turkish
        E_LANGUAGE_FR_NA,            //< French (US)
        E_LANGUAGE_ES_NA,            //< Spanish (US)
        //  E_LANGUAGE_EN_IN,            //< English (INDIA) - Not Used
        E_LANGUAGE_NR        = 0x17, //< Norwegian
        E_LANGUAGE_FN,               //< Finnish
        //  E_LANGUAGE_INA,              //< Indonesian - Not Used
        E_LANGUAGE_PT_BR     = 0x1A, //< Brazillian Portuguese
        //  E_LANGUAGE_MAS,              //< Malaysia (Malay)  - Not Used
        E_LANGUAGE_HU        = 0x1C, //< Hungarian
        E_LANGUAGE_EN_AU,            //< English (AUS)
        E_LANGUAGE_JP        = 0x1E, //< Japanese
        E_LANGUAGE_INVALID   = 0xFF  // Invalid

    };

};

#endif // APPHOMEENUMS_H
