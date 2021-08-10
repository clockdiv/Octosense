#ifndef OCTOCHANNEL_H
#define OCTOCHANNEL_H

#include <Arduino.h>

#ifdef ARDUINO_TEENSY31
#include "pinsTeensy.h"
#else
#include "pinsArduino.h"
#endif

#include "ShiftRegister74HC595.h"
#include "voltmeter.h"


class OctoChannel
{
    private:
    static ShiftRegister74HC595<SHIFT_REGISTER_CNT> *sr;
    static Voltmeter *voltmeter;
    static uint8_t activatedChannelID;
    static bool channelSwitched;

    uint8_t channelId, led, pinInput;

    public:
    OctoChannel();
    static void init(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr, Voltmeter *_voltmeter);
    void init(uint8_t _channelId, uint8_t _led, uint8_t _pinInput);
    void update();
    static void setChannel(uint8_t _channelID);
};

#endif