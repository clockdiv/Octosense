#ifndef OCTOCHANNEL_H
#define OCTOCHANNEL_H

#include <Arduino.h>
#include "ShiftRegister74HC595.h"
#include "pinsTeensy.h"

class OctoChannel
{
    private:
    static ShiftRegister74HC595<SHIFT_REGISTER_CNT> *sr;
    static uint8_t activatedChannelID;
    //static OctoChannel *channels;
    uint8_t channelId, ledId;
    static bool channelSwitched;

    public:
    OctoChannel();
    static void initShiftRegister(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr);
    void init(uint8_t _ledId);
    void update();
    static void setChannel(uint8_t _channelID);
};

#endif