#include "voltmeter.h"

ShiftRegister74HC595<SHIFT_REGISTER_CNT> *Voltmeter::sr;

Voltmeter::Voltmeter(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr)
{
    sr = _sr;
}

void Voltmeter::update()
{
}

void Voltmeter::setValue(uint8_t _value)
{
    uint8_t v = _value / 40;
    for (int i = 0; i < ledsMeterCnt; i++)
    {
        if (i < v)
        {
            sr->set(ledsMeters[i], HIGH);
        }
        else
        {
            sr->set(ledsMeters[i], LOW);
        }
    }
}