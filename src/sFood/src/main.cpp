#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "AppHomeEngine.h"

int main(int argc, char *argv[])
{
    //QGuiApplication app(argc, argv);

    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:qml/main.qml")));
    //return app.exec();
    AppHomeEngine engine(argc, argv);
    engine.applicationStart();

    return engine.exec();
}
