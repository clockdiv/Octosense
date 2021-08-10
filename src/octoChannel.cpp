#include "octoChannel.h"

uint8_t OctoChannel::activatedChannelID = 0;
bool OctoChannel::channelSwitched = false;
ShiftRegister74HC595<SHIFT_REGISTER_CNT> *OctoChannel::sr;

OctoChannel::OctoChannel()
{
}

void OctoChannel::initShiftRegister(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr)
{
    sr = _sr;
}

void OctoChannel::init(uint8_t _ledId)
{
    ledId = _ledId;
    channelId = ledId; // right now that's the same, "let's do it more elegant later..."
}

void OctoChannel::update()
{
    if (activatedChannelID == channelId && channelSwitched == true)
    {
        // turn off LEDs from other channels
        for (uint8_t i = 0; i < 6; i++)
        {
            sr->set(ledsButtons[i], LOW);
        }

        sr->set(ledsButtons[ledId], HIGH);
        channelSwitched = false;
    }
}

void OctoChannel::setChannel(uint8_t _channelID)
{
    if (activatedChannelID == _channelID)
        return;

    activatedChannelID = _channelID;
    channelSwitched = true;
}