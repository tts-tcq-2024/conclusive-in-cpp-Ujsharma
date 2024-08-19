#ifndef COOLINGSTRATEGY_H
#define COOLINGSTRATEGY_H

#pragma once

#include "typewise-alert.h"

class CoolingStrategy {
public:
    virtual BreachType classifyTemperature(double temperatureInC) const = 0;
    virtual ~CoolingStrategy() {}
};
#endif // COOLINGSTRATEGY_H
