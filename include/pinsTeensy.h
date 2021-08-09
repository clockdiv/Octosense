#ifndef PINS_H
#define PINS_H

#include <Arduino.h>


// Button Pins
#define PIN_BUTTON_1        5
#define PIN_BUTTON_2        4

const uint8_t btns[] = {24, 25, 26, 27, 28, 29, 30, 31};
const uint8_t btnsCnt = 8;

// Shift register Pins
#define SHIFT_REGISTER_CNT  4   // number of shift registers attached in series
#define PIN_SERIALDATA      8   // DS
#define PIN_CLOCK           7   // SHCP
#define PIN_LATCH           6   // STCP

// Led indices in Shift Registers
const uint8_t ledsMeters[] = {8, 9, 10, 11, 12, 13, 14};
const uint8_t ledsMeterCnt = 7;

const uint8_t ledsGate[] = {0, 15};
const uint8_t ledsGateCnt = 2;

const uint8_t ledsButtons[] = {16, 17, 18, 19, 20, 21, 22, 23};
const uint8_t ledsButtonsCnt = 8;

#endif