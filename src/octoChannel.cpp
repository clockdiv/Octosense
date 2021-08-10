#include "octoChannel.h"

uint8_t OctoChannel::activatedChannelID = 255;
bool OctoChannel::channelSwitched = true;
ShiftRegister74HC595<SHIFT_REGISTER_CNT> *OctoChannel::sr;
Voltmeter *OctoChannel::voltmeter;

OctoChannel::OctoChannel()
{
}

void OctoChannel::init(ShiftRegister74HC595<SHIFT_REGISTER_CNT> *_sr, Voltmeter *_voltmeter)
{
    sr = _sr;
    voltmeter = _voltmeter;
}

void OctoChannel::init(uint8_t _channelId, uint8_t _led, uint8_t _pinInput)
{
    led = _led;
    channelId = _channelId;
    pinInput = _pinInput;
}

void OctoChannel::update()
{
    if (activatedChannelID != channelId)
        return;

    if (channelSwitched == true) // if channel is switched...
    {
        // turn off LEDs from other channels
        for (uint8_t i = 0; i < 5; i++)
        {
            sr->set(ledsButtons[i], LOW);
        }

        sr->set(led, HIGH);
        channelSwitched = false;
    }

    uint16_t inputValue = analogRead(pinInput);

    voltmeter->setValue(inputValue);
}

void OctoChannel::setChannel(uint8_t _channelID)
{
    if (activatedChannelID == _channelID)
        return;

    activatedChannelID = _channelID;
    channelSwitched = true;
}