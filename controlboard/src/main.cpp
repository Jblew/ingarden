#include "Arduino.h"

#define PIN_INDICATOR_LED PC13
#define PIN_DCF77_TIME_IN PB9

void setup() {
  pinMode(PIN_INDICATOR_LED, OUTPUT);
  pinMode(PIN_DCF77_TIME_IN, INPUT);
}

int dcf77Lvl;
void loop() {
  dcf77Lvl = digitalRead(PIN_DCF77_TIME_IN);
  digitalWrite(PIN_INDICATOR_LED, dcf77Lvl);
  delay(5);
}
