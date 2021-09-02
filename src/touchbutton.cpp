#include "touchbutton.h"

Touchbutton::Touchbutton()
{
}

void Touchbutton::init(uint8_t _pin)
{
    pin = _pin;
    pinMode(pin, INPUT);
}

void Touchbutton::update()
{
    value = touchRead(pin);
}

int Touchbutton::getValue()
{
    return value;
}