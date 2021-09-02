#ifndef TOUCHBUTTON_H
#define TOUCHBUTTON_H
#include <Arduino.h>
#include "CapacitiveSensor.h"

class Touchbutton
{
private:
    uint8_t pin;
    int value;

public:
    Touchbutton();
    void init(uint8_t _pin);
    void update();
    int getValue();
};

#endif