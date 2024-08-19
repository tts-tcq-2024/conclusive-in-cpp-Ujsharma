#ifndef PASSIVECOOLINGSTRATEGY_H
#define PASSIVECOOLINGSTRATEGY_H

#include "CoolingStrategy.h"

class PassiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 35);
    }
};
#endif //PASSIVECOOLINGSTRATEGY_H
