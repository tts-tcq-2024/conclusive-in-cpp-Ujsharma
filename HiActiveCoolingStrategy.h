#ifndef HIACTIVECOOLINGSTRATEGY_H
#define HIACTIVECOOLINGSTRATEGY_H

#include "CoolingStrategy.h"

class HiActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        if (temperatureInC < 0) {
            return TOO_LOW;
        } else if (temperatureInC > 35) {
            return TOO_HIGH;
        }
        return NORMAL;
        return inferBreach(temperatureInC, 0, 45);
    }
};

#endif // HIACTIVECOOLINGSTRATEGY_H
