// CoolingStrategy.h
#pragma once

#include "typewise-alert.h"

class CoolingStrategy {
public:
    virtual BreachType classifyTemperature(double temperatureInC) const = 0;
    virtual ~CoolingStrategy() {}
};
