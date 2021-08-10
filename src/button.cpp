#include "button.h"

Button::Button()
{
    state = LOW;
    stateOld = LOW;
    _hasRisen = false;
    _hasFallen = false;
}

void Button::setState(bool _state)
{
    state = _state;
    if(stateOld == LOW && state == HIGH) _hasRisen = true;
    else if (stateOld == HIGH && state == LOW) _hasFallen = true;
    stateOld = state;
}

bool Button::getState()
{
    // stateOld = state;
    return state;
}

bool Button::hasRisen()
{
    if(_hasRisen) {
        _hasRisen = false;
        return true;
    } else {
        return false;
    }
}

bool Button::hasFallen()
{
    if(_hasFallen) {
        _hasFallen = false;
        return true;
    } else {
        return false;
    }
}
