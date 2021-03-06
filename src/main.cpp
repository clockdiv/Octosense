#include <Arduino.h>
#include <ShiftRegister74HC595.h>
#include <ADC.h>

#include "pinDefinitions.h"

#include "buttonsManager.h"
#include "octoChannel.h"
#include "voltmeter.h"

#define CHANNEL_COUNT 5

ShiftRegister74HC595<SHIFT_REGISTER_CNT> sr(PIN_SERIALDATA, PIN_CLOCK, PIN_LATCH);
ADC adc;

ButtonsManager buttonsmanager(&sr);
OctoChannel channels[CHANNEL_COUNT];
Voltmeter voltmeter(&sr);

// function declarations
void startupLEDSequence();
void mapButtonsToLEDs(); // test function
void buttonsTest();      // test function
void updateButtons();
void updateChannels();

/* ------------------------------------------ */
void setup()
{
  // init channels and their led-ids
  OctoChannel::init(&sr, &voltmeter);
  /*   for (int i = 0; i < CHANNEL_COUNT; i++)
  {
    channels[i].init(i);
  }
 */
  channels[0].init(0, ledsButtons[0], PIN_INPUT_A);
  channels[1].init(1, ledsButtons[1], PIN_INPUT_B);
  channels[2].init(2, ledsButtons[2], PIN_INPUT_C);
  channels[3].init(3, ledsButtons[3], PIN_INPUT_D);
  channels[4].init(4, ledsButtons[4], PIN_INPUT_E);

 
  adc.adc0->setAveraging(0); // set number of averages
  adc.adc0->setResolution(10); // set bits of resolution
  adc.adc0->setConversionSpeed(ADC_settings::ADC_CONVERSION_SPEED::HIGH_SPEED); // change the conversion speed
  adc.adc0->setSamplingSpeed(ADC_settings::ADC_SAMPLING_SPEED::VERY_HIGH_SPEED); // change the sampling speed

  adc.adc0->startContinuous(16);

 
  startupLEDSequence();

  // switch to channel 0 at startup
  OctoChannel::setChannel(1);
  updateChannels();
}

/* ------------------------------------------ */
void loop()
{

  updateButtons();
  return;
  updateChannels();

  // mapButtonsToLEDs();
  // buttonsTest();
}


/* ------------------------------------------ */
void updateButtons()
{
  buttonsmanager.update();

  // get touch buttons
  //uint16_t t = buttonsmanager.touchbuttons[0].getValue();
  //t = constrain(t, 2000, 4000);
  //t = map(t, 2000, 4000, 0, 1023);
  uint16_t t = adc.adc0->analogReadContinuous();
  Serial.println(t);
  voltmeter.setValue(t);
  return;


  // check if channel is changed
  if (buttonsmanager.buttons[BTN_A].hasRisen())
  {
    OctoChannel::setChannel(0);
  }
  else if (buttonsmanager.buttons[BTN_B].hasRisen())
  {
    OctoChannel::setChannel(1);
  }
  else if (buttonsmanager.buttons[BTN_C].hasRisen())
  {
    OctoChannel::setChannel(2);
  }
  else if (buttonsmanager.buttons[BTN_D].hasRisen())
  {
    OctoChannel::setChannel(3);
  }
  else if (buttonsmanager.buttons[BTN_E].hasRisen())
  {
    OctoChannel::setChannel(4);
  }
  else if (buttonsmanager.buttons[BTN_F].hasRisen())
  {
    OctoChannel::setChannel(5);
  }

}

/* ------------------------------------------ */
void updateChannels()
{
  for (int i = 0; i < CHANNEL_COUNT; i++)
  {
    channels[i].update();
  }
}

/* ------------------------------------------ */
void buttonsTest()
{
  for (int i = 0; i < 16; i++)
  {
    if (buttonsmanager.buttons[i].hasRisen())
    {
      Serial.print(i);
      Serial.println(" has risen");
    }
    else if (buttonsmanager.buttons[i].hasFallen())
    {
      Serial.print(i);
      Serial.println(" has fallen");
    }
  }
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
    // check buttons
    if (i <= ledsButtonsCnt)
      sr.set(ledsButtons[i], buttonsmanager.buttons[i].getState());

    // check buttons
    if (i <= ledsMeterCnt)
      sr.set(ledsMeters[i], buttonsmanager.buttons[i + 8].getState());
  }
}