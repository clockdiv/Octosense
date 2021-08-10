#ifndef BUTTONSMANAGER_H
#define BUTTONSMANAGER_H

#include <ShiftRegister74HC595.h>
#ifdef ARDUINO_TEENSY31
#include "pinsTeensy.h"
#else
#include "pinsArduino.h"
#endif
#include "button.h"

class ButtonsManager
{
private:
    static ShiftRegister74HC595<SHIFT_REGISTER_CNT> *sr;
    void setButtonsHigh();

public:
    Button buttons[16];
    ButtonsManager(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr);
    uint8_t update();
};

#endif
