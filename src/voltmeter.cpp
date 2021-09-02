#include "voltmeter.h"

ShiftRegister74HC595<SHIFT_REGISTER_CNT> *Voltmeter::sr;

Voltmeter::Voltmeter(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr)
{
    sr = _sr;
}

void Voltmeter::update()
{
}

void Voltmeter::setValue(uint16_t _value)
{
    uint16_t v = _value / 150;
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