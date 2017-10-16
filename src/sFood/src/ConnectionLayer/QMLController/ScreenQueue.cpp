#include "ScreenQueue.h"

ScreenQueue::ScreenQueue(int max_deep, QObject *parent) : QObject(parent),m_MaxDeep(max_deep)
{

}

ScreenQueue::~ScreenQueue()
{

}
bool ScreenQueue::contains(QString& id){
    for(int i = 0; i < m_screenList.size(); i++){
        if( m_screenList.at(i).scrName ==  id)
            return  true;
    }
    return false;
}

QQmlComponentPtr ScreenQueue::getScreen(QString& scrName){
    for(int i = 0; i < m_screenList.size(); i++){
        if( m_screenList.at(i).scrName ==  scrName)
            return  m_screenList.at(i).qml;
    }
    return QQmlComponentPtr();
}

void ScreenQueue::insert(QString& scrName, QQmlComponentPtr qml){
    if(m_screenList.count() >= m_MaxDeep){
        m_screenList.removeLast();
    }
    SCREEN_T t = {scrName, qml};
    m_screenList.insert(0,t);
}

int ScreenQueue::count(){
    return m_screenList.count();
}

void ScreenQueue::setMaxDeep(int max_deep){
    m_MaxDeep = max_deep;
    if(m_MaxDeep < m_screenList.count()){
        int gap = m_screenList.count() - m_MaxDeep;
        for(int i =0; i < gap; i++){
            m_screenList.removeLast();
        }
    }
}

QQmlComponentPtr ScreenQueue::operator[](QString scrName){
    return getScreen(scrName);
}

void ScreenQueue::initScreenQueue()
{
    while (m_screenList.count() > 1) {
        m_screenList.removeLast();
    }
}
