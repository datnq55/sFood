TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    RestHandler/RestServer.cpp \
    HttpServer/HttpServer.cpp \
    HttpClient/HttpClient.cpp \
    src/ConnectionLayer/AppManager/AppManager.cpp \
    src/ConnectionLayer/QMLController/QMLController.cpp \
    src/ConnectionLayer/QMLController/ScreenQueue.cpp \
    src/ConnectionLayer/ScrController/OnsController.cpp \
    src/ConnectionLayer/ScrController/QTimerWrp.cpp \
    src/ConnectionLayer/ScrController/ScrController.cpp \
    src/ConnectionLayer/ScrController/TimerConnection.cpp \
    src/HttpClient/HttpClient.cpp \
    src/HttpServer/HttpServer.cpp \
    src/RestHandler/RestServer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    RestHandler/RestServer.h \
    HttpServer/HttpServer.h \
    HttpClient/HttpClient.h \
    src/ConnectionLayer/AppManager/AppManager.h \
    src/ConnectionLayer/QMLController/QMLController.h \
    src/ConnectionLayer/QMLController/ScreenQueue.h \
    src/ConnectionLayer/ScrController/CommonStructs.h \
    src/ConnectionLayer/ScrController/OnsController.h \
    src/ConnectionLayer/ScrController/QTimerWrap.h \
    src/ConnectionLayer/ScrController/ScrController.h \
    src/ConnectionLayer/ScrController/TimerConnection.h \
    src/HttpClient/HttpClient.h \
    src/HttpServer/HttpServer.h \
    src/RestHandler/RestServer.h
