#include <Arduino.h>
#include "buttonsManager.h"

ShiftRegister74HC595<SHIFT_REGISTER_CNT> *ButtonsManager::sr;

/* ------------------------------------------ */
ButtonsManager::ButtonsManager(ShiftRegister74HC595<4> *_sr)
{
    sr = _sr;
    pinMode(PIN_BUTTON_1, INPUT_PULLUP);
    pinMode(PIN_BUTTON_2, INPUT_PULLUP);
}

/* ------------------------------------------ */
uint8_t ButtonsManager::update()
{
    for (int i = 0; i < btnsCnt; i++)
    {
        setButtonsHigh();
        sr->set(btns[i], LOW);
        delay(10);

        uint8_t b1 = digitalRead(PIN_BUTTON_1);
        uint8_t b2 = digitalRead(PIN_BUTTON_2);
        if (b1 == LOW)
        {
            buttons[i].setState(HIGH);
        }
        else
        {
            buttons[i].setState(LOW);
        }
        if (b2 == LOW)
        {
            buttons[i + 8].setState(HIGH);
        }
        else
        {
            buttons[i + 8].setState(LOW);
        }
    }
}

/* ------------------------------------------ */
void ButtonsManager::setButtonsHigh()
{
    for (int i = 0; i < btnsCnt; i++)
    {
        sr->set(btns[i], HIGH);
    }
}