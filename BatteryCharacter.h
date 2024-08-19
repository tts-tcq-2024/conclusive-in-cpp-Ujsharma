#ifndef BATTERY_CHARACTER_H
#define BATTERY_CHARACTER_H

#include "CoolingStrategy.h"  // Include the necessary header for CoolingStrategy

struct BatteryCharacter {
    CoolingStrategy* coolingStrategy;  // Pointer to a CoolingStrategy
    char brand[48];
};

#endif // BATTERY_CHARACTER_H
