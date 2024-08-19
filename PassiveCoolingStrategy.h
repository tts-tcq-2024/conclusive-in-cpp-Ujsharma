#ifndef PASSIVECOOLINGSTRATEGY_H
#define PASSIVECOOLINGSTRATEGY_H

#include "CoolingStrategy.h"

class PassiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        if (temperatureInC < 0) {
            return TOO_LOW;
        } else if (temperatureInC > 35) {
            return TOO_HIGH;
        }
        return NORMAL;
    }
        return inferBreach(temperatureInC, 0, 35);
    }
};
#endif //PASSIVECOOLINGSTRATEGY_H
