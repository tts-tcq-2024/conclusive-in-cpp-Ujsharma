#ifndef COOLING_STRATEGY_H
#define COOLING_STRATEGY_H

#include "typewise-alert.h"

class CoolingStrategy {
public:
    virtual ~CoolingStrategy() = default;
    virtual BreachType classifyTemperature(double temperatureInC) const = 0;
};

#endif // COOLING_STRATEGY_H
