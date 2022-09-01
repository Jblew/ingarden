#include "Arduino.h"

#define PIN_INDICATOR_LED PC13
#define PIN_DCF77_TIME_IN PB9

void setup()
{
  pinMode(PIN_INDICATOR_LED, OUTPUT);
  pinMode(PIN_DCF77_TIME_IN, INPUT);
  Serial.begin(9600);
}

#define BUF_LEN 120
volatile int buf[BUF_LEN];
volatile int bufPos = 0;

void waitFor(int level) {
  while(digitalRead(PIN_DCF77_TIME_IN) == level) {
    delayMicroseconds(50);
  }
}

void loop()
{
  waitFor(HIGH);
  uint32_t stime = millis();
  waitFor(LOW);
  int highTime = millis() - stime;
  buf[bufPos] = highTime;
  bufPos++;
  if(bufPos >= BUF_LEN) {
    bufPos = 0;
  }
}
