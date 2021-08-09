#include <Arduino.h>
#include "buttons.h"

ShiftRegister74HC595<SHIFT_REGISTER_CNT> *Buttons::sr;

/* ------------------------------------------ */
Buttons::Buttons(ShiftRegister74HC595<4> *_sr)
{
    sr = _sr;
    pinMode(PIN_BUTTON_1, INPUT_PULLUP);
    pinMode(PIN_BUTTON_2, INPUT_PULLUP);
}

/* ------------------------------------------ */
uint8_t Buttons::update(uint8_t* _buttonsPressed)
{
    for (int i = 0; i < btnsCnt; i++)
    {
        setButtonsHigh();
        sr->set(btns[i], LOW);
        delay(10);
        
         _buttonsPressed[i] = 0;
         _buttonsPressed[i+8] = 0;

        uint8_t b1 = digitalRead(PIN_BUTTON_1);
        uint8_t b2 = digitalRead(PIN_BUTTON_2);
        if (b1 == LOW)
        {
            Serial.println("b1");
            _buttonsPressed[i] = 1;
        }
        if (b2 == LOW) {
            Serial.println("b2");
            _buttonsPressed[i+8] = 1;
        }

    }
}

/* ------------------------------------------ */
void Buttons::setButtonsHigh()
{
    for (int i = 0; i < btnsCnt; i++)
    {
        sr->set(btns[i], HIGH);
    }
}