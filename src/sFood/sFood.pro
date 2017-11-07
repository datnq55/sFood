include(./qtquick2applicationviewer/qtquick2applicationviewer.pri)
TEMPLATE = app

QT += qml quick core gui
QT += sql
QT += network
CONFIG += c++11

SOURCES += \
    src/ConnectionLayer/AppManager/AppManager.cpp \
    src/ConnectionLayer/QMLController/QMLController.cpp \
    src/ConnectionLayer/QMLController/ScreenQueue.cpp \
    src/ConnectionLayer/ScrController/OnsController.cpp \
    src/ConnectionLayer/ScrController/QTimerWrp.cpp \
    src/ConnectionLayer/ScrController/ScrController.cpp \
    src/ConnectionLayer/ScrController/TimerConnection.cpp \
    src/Controller/AppHomeController.cpp \
    src/Database/SqLite.cpp \
    src/HttpClient/HttpClient.cpp \
    src/HttpServer/HttpServer.cpp \
    src/HttpServer/qhttpconnection.cpp \
    src/HttpServer/qhttprequest.cpp \
    src/HttpServer/qhttpresponse.cpp \
    src/HttpServer/qhttpserver.cpp \
    src/Model/AppMainModel.cpp \
    src/RestServer/Controller/BaseController.cpp \
    src/RestServer/Controller/SensorController.cpp \
    src/RestServer/Data/WriterIn.cpp \
    src/RestServer/Model/basemodel.cpp \
    src/RestServer/Service/BaseService.cpp \
    src/RestServer/ControllerInfo.cpp \
    src/RestServer/RestServer.cpp \
    src/RestServer/Router.cpp \
    src/View/AppMainView.cpp \
    src/AppMainEngine.cpp \
    src/main.cpp \
    src/HttpServer/http-parser/contrib/parsertrace.c \
    src/HttpServer/http-parser/contrib/url_parser.c \
    src/HttpServer/http-parser/bench.c \
    src/HttpServer/http-parser/http_parser.c \
    src/HttpServer/http-parser/test.c

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/ConnectionLayer/AppManager/AppManager.h \
    src/ConnectionLayer/QMLController/QMLController.h \
    src/ConnectionLayer/QMLController/ScreenQueue.h \
    src/ConnectionLayer/ScrController/CommonStructs.h \
    src/ConnectionLayer/ScrController/OnsController.h \
    src/ConnectionLayer/ScrController/QTimerWrap.h \
    src/ConnectionLayer/ScrController/ScrController.h \
    src/ConnectionLayer/ScrController/TimerConnection.h \
    src/Controller/AppHomeController.h \
    src/Database/SqLite.h \
    src/HttpClient/HttpClient.h \
    src/HttpClient/httpclient_global.h \
    src/HttpServer/http-parser/http_parser.h \
    src/HttpServer/HttpServer.h \
    src/HttpServer/httpserver_global.h \
    src/HttpServer/qhttpconnection.h \
    src/HttpServer/qhttprequest.h \
    src/HttpServer/qhttpresponse.h \
    src/HttpServer/qhttpserver.h \
    src/HttpServer/qhttpserverapi.h \
    src/HttpServer/qhttpserverfwd.h \
    src/Model/AppMainModel.h \
    src/RestServer/Controller/BaseController.h \
    src/RestServer/Controller/SensorController.h \
    src/RestServer/Data/WriterIn.h \
    src/RestServer/Model/BaseModel.h \
    src/RestServer/Service/BaseService.h \
    src/RestServer/ControllerInfo.h \
    src/RestServer/ErrorCode.h \
    src/RestServer/RestServer.h \
    src/RestServer/Router.h \
    src/View/AppMainView.h \
    src/AppMainEngine.h \
    src/commonstructs.h
