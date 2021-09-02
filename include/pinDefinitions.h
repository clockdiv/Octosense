#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

#ifdef ARDUINO_TEENSY31

// Pins for Teensy 3.2
// Button Pins
#define PIN_BUTTON_1        5
#define PIN_BUTTON_2        4
// Analog Input Pins
#define PIN_INPUT_A 23
#define PIN_INPUT_B 22
#define PIN_INPUT_C 21
#define PIN_INPUT_D 20
#define PIN_INPUT_E 17
// Shift register Pins
#define SHIFT_REGISTER_CNT  4   // number of shift registers attached in series
#define PIN_SERIALDATA      8   // DS
#define PIN_CLOCK           7   // SHCP
#define PIN_LATCH           6   // STCP
// Touch-Pins
#define PIN_TOUCH_G 16
#define PIN_TOUCH_H 15
#else
// Pins for Arduino Micro

// Button Pins
#define PIN_BUTTON_1        7
#define PIN_BUTTON_2        11
// Shift register Pins
#define SHIFT_REGISTER_CNT  4   // number of shift registers attached in series
#define PIN_SERIALDATA      4   // DS
#define PIN_CLOCK           5   // SHCP
#define PIN_LATCH           6   // STCP
// Analog Input Pins
#define PIN_INPUT_A A0
#define PIN_INPUT_B A1
#define PIN_INPUT_C A2
#define PIN_INPUT_D A3
#define PIN_INPUT_E A4
// Touch-Pins
#define PIN_TOUCH_G 12
#define PIN_TOUCH_H 8
#endif



// Led indices in Shift Registers
const uint8_t ledsMeters[] = {8, 9, 10, 11, 12, 13, 14};
const uint8_t ledsMeterCnt = 7;

const uint8_t ledsGate[] = {0, 15};
const uint8_t ledsGateCnt = 2;

const uint8_t ledsButtons[] = {16, 17, 18, 19, 20, 21, 22, 23};
const uint8_t ledsButtonsCnt = 8;

const uint8_t ledsTouch[] = {22, 23};
const uint8_t ledsTouchCnt = 2;

// Button indices in Shift Registers
const uint8_t btns[] = {24, 25, 26, 27, 28, 29, 30, 31};
const uint8_t btnsCnt = 8;


// Buttons as assigned in "buttonsPressed"-Array:
#define BTN_A       0
#define BTN_B       1
#define BTN_C       2   
#define BTN_D       3
#define BTN_E       4
#define BTN_F       5
#define BTN_CAL     6
#define BTN_INVERT  7
#define BTN_DATA    8
#define BTN_SYNTH   9
#define BTN_ASSIGN  10
#define BTN_MUTE    11
#define BTN_TOUCH   12
#define BTN_SHIFT   13
#define BTN_MIDI    14



#endif
