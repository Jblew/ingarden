#include "Arduino.h"
#include "DCF77.h"
#include "TimeLib.h"

#define PIN_INDICATOR_LED PC13
#define PIN_DCF77_TIME_IN PB9

time_t time;
DCF77 DCF = DCF77(
    PIN_DCF77_TIME_IN,
    digitalPinToInterrupt(PIN_DCF77_TIME_IN));

void setup()
{
  pinMode(PIN_INDICATOR_LED, OUTPUT);
  pinMode(PIN_DCF77_TIME_IN, INPUT);
  Serial.begin(9600);
  DCF.Start();
}

void loop()
{
  delay(1000);
  time_t DCFtime = DCF.getTime();
  if (DCFtime != 0)
  {
    Serial.println("Time is updated");
    setTime(DCFtime);

    // For ST-LINK + SWD debug
    volatile int t_hour = 0;
    volatile int t_minute = 0;
    volatile int t_second = 0;
    t_hour = hour();
    Serial.println(t_hour);
    t_minute = minute();
    Serial.println(t_minute);
    t_second = second();
    Serial.println(t_second);
  }
}
