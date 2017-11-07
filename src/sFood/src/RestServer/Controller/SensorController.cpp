/*
 * SensorController.cpp
 *
 *  Created on: May 05, 2017
 *      Author: trungnd
 */

#include <QDebug>
#include <QList>
#include <QMap>
#include "SensorController.h"
#include "../Data/WriterIn.h"
#include "../ErrorCode.h"

const QString k_serviceUrl = "/api/service";

SensorController::SensorController()
{

}

SensorController::SensorController(const SensorController& other)
{
    Q_UNUSED(other);
}

SensorController::~SensorController()
{

}
