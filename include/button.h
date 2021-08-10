#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
private:
    uint8_t buttonIndex;
    bool state, stateOld, _hasRisen, _hasFallen;
    

public:
    Button();
    void setState(bool _state);
    bool hasRisen();
    bool hasFallen();
    bool getState();
};

#endif