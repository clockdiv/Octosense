
#ifdef ARDUINO_TEENSY31
#include "pinsTeensy.h"
#else
#include "pinsArduino.h"
#endif

#ifndef VOLTMETER_H
#define VOLTMETER_H

#include <Arduino.h>
#include "ShiftRegister74HC595.h"


class Voltmeter
{
private:
    static ShiftRegister74HC595<SHIFT_REGISTER_CNT> *sr;
    uint8_t value;

public:
    Voltmeter(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr);
    void update();
    void setValue(uint8_t _value);
};

#endif