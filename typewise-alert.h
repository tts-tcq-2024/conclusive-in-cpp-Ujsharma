#ifndef TYPEWISE-ALERT_H
#define TYPEWISE-ALERT_H
#pragma once

#include <string.h>

typedef enum {
    PASSIVE_COOLING,
    HI_ACTIVE_COOLING,
    MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
    NORMAL,
    TOO_LOW,
    TOO_HIGH
} BreachType;

typedef enum {
    TO_CONTROLLER,
    TO_EMAIL
} AlertTarget;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);

class CoolingStrategy;

typedef struct {
    CoolingStrategy* coolingStrategy;
    char brand[48];
} BatteryCharacter;

BreachType classifyTemperatureBreach(const BatteryCharacter& batteryChar, double temperatureInC);
void checkAndAlert(AlertTarget alertTarget, const BatteryCharacter& batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

#endif //TYPEWISE-ALERT_H
