#ifndef VOLTMETER_H
#define VOLTMETER_H

#include <Arduino.h>
#include "ShiftRegister74HC595.h"

#include "pinDefinitions.h"

class Voltmeter
{
private:
    static ShiftRegister74HC595<SHIFT_REGISTER_CNT> *sr;
    uint8_t value;

public:
    Voltmeter(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr);
    void update();
    void setValue(uint16_t _value);
};

#endif