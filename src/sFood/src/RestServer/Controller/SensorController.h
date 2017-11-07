/*
 * SensorController.h
 *
 *  Created on: May 05, 2017
 *      Author: trungnd
 */

#ifndef SENSORCONTROLLER_H
#define SENSORCONTROLLER_H

#include "BaseController.h"

class SensorController : public BaseController
{
    Q_OBJECT

public:
    SensorController();
    SensorController(const SensorController& other);
    virtual ~SensorController();
};

#endif // SENSORCONTROLLER_H
