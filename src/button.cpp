#include "button.h"

Button::Button()
{
    state = LOW;
    stateOld = LOW;
}

void Button::setState(bool _state)
{
    state = _state;
}

bool Button::getState()
{
    stateOld = state;
    return state;
}

bool Button::hasRisen()
{
    if (stateOld == LOW && state == HIGH)
    {
        stateOld = state;
        return true;
    }
    return false;
}

bool Button::hasFallen()
{
    if (stateOld == HIGH && state == LOW)
    {
        stateOld = state;
        return true;
    }
    return false;
}
