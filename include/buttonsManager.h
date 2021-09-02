#ifndef BUTTONSMANAGER_H
#define BUTTONSMANAGER_H

#include <ShiftRegister74HC595.h>
#include "pinDefinitions.h"
#include "button.h"
#include "touchbutton.h"

class ButtonsManager
{
private:
    static ShiftRegister74HC595<SHIFT_REGISTER_CNT> *sr;
    void setButtonsHigh();

public:
    Button buttons[16];
    Touchbutton touchbuttons[2];

    ButtonsManager(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr);
    void update();
};

#endif
