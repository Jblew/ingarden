#include "Arduino.h"

#define PIN_INDICATOR_LED PC13
#define PIN_RACK_LAMP PA8

void setup() {
  pinMode(PIN_INDICATOR_LED, OUTPUT);
  pinMode(PIN_RACK_LAMP, OUTPUT);
}


void loop() {
  digitalWrite(PIN_INDICATOR_LED, HIGH);
  for(uint32_t v = 0;v < 255; v++) {
    analogWrite(PIN_RACK_LAMP, v);
    delay(8);
  }
  digitalWrite(PIN_INDICATOR_LED, LOW);
  for(uint32_t v = 255;v > 0; v--) {
    analogWrite(PIN_RACK_LAMP, v);
    delay(8);
  }
}
