#include <Arduino.h>
#include <ShiftRegister74HC595.h>

#ifdef ARDUINO_TEENSY31
#include "pinsTeensy.h"
#else
#include "pinsArduino.h"
#endif

#include "buttons.h"

ShiftRegister74HC595<SHIFT_REGISTER_CNT> sr(PIN_SERIALDATA, PIN_CLOCK, PIN_LATCH);

Buttons buttons(&sr);

uint8_t buttonsPressed[16];

// function declarations
void startupLEDSequence();
void mapButtonsToLEDs();

/* ------------------------------------------ */
void setup()
{
  for (int i = 0; i < 16; i++)
  {
    buttonsPressed[i] = 0;
  }
  //startupLEDSequence();
}

/* ------------------------------------------ */
void loop()
{
  buttons.update(buttonsPressed);
  mapButtonsToLEDs();
}

/* ------------------------------------------ */
void startupLEDSequence()
{
  uint16_t s = 25;
  for (int i = 0; i < ledsMeterCnt; i++)
  {
    sr.set(ledsMeters[i], HIGH);
    delay(s);
    sr.set(ledsMeters[i], LOW);
    delay(s);
  }

  for (int i = 0; i < ledsGateCnt; i++)
  {
    sr.set(ledsGate[i], HIGH);
    delay(s);
    sr.set(ledsGate[i], LOW);
    delay(s);
  }

  for (int i = 0; i < ledsButtonsCnt; i++)
  {
    sr.set(ledsButtons[i], HIGH);
    delay(s);
    sr.set(ledsButtons[i], LOW);
    delay(s);
  }
}

/* ------------------------------------------ */
void mapButtonsToLEDs()
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // check buttons 0-7 (A, B, C, D, E, F, CAL, INVERT)
    sr.set(ledsButtons[i], buttonsPressed[i]);
    
    // check buttons 8-14 (, 15 is not in use)
    sr.set(ledsMeters[i], buttonsPressed[i + 8]);
  }
}