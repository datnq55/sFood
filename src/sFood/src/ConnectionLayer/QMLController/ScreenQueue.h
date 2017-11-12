#ifndef SCREENQUEUE_H
#define SCREENQUEUE_H

#include <QObject>
#include <QList>
#include <QQuickItem>
#include <QQmlContext>
#include <QSharedPointer>

#define MAX_DEEP_LIMIT 10
typedef QSharedPointer<QQmlComponent> QQmlComponentPtr;
struct SCREEN_T{
    QString scrName;
    QQmlComponentPtr qml;
};

class ScreenQueue : public QObject
{
    Q_OBJECT
protected:
    int m_MaxDeep;
    QList<SCREEN_T> m_screenList;
public:
    explicit ScreenQueue(int max_deep = MAX_DEEP_LIMIT, QObject *parent = 0);
    ~ScreenQueue();
    bool contains(QString& id);
    QQmlComponentPtr getScreen(QString& scrName);
    void insert(QString& scrName, QQmlComponentPtr qml);
    int count();
    void setMaxDeep(int max_deep);
    QQmlComponentPtr operator[](QString scrName);
    void initScreenQueue();
};

#endif // SCREENQUEUE_H
