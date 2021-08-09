#ifndef BUTTONS_H
#define BUTTONS_H

#include <ShiftRegister74HC595.h>
#include "pinsTeensy.h"

class Buttons
{
private:
    static ShiftRegister74HC595<SHIFT_REGISTER_CNT> *sr;

    elapsedMillis lastCheck;

    void setButtonsHigh();

public:
    Buttons(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr);
    uint8_t update(uint8_t *_buttonsPressed);
};

#endif
