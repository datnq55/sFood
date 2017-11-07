/*
 * BaseService.h
 *
 *  Created on: May 05, 2017
 *      Author: trungnd
 */


#ifndef BASESERVICE_H
#define BASESERVICE_H

#include <QObject>

class BaseService : public QObject
{
public:
    BaseService();
    virtual ~BaseService();
};

#endif // BASESERVICE_H
