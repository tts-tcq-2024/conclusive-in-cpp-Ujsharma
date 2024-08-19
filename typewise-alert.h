#ifndef TYPEWISEALERT_H
#define TYPEWISEALERT_H

#include <unordered_map>
#include "BatteryCharacter.h"

typedef enum {
    PASSIVE_COOLING,
    HI_ACTIVE_COOLING,
    MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
    TO_CONTROLLER,
    TO_EMAIL
} AlertTarget;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(const BatteryCharacter& batteryChar, double temperatureInC);

void checkAndAlert(AlertTarget alertTarget, const BatteryCharacter& batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

typedef void (*AlertFunction)(BreachType);  // Function pointer type for alert functions

#endif //TYPEWISE-ALERT_H
