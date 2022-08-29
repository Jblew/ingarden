#include "Arduino.h"

#define PIN_INDICATOR_LED PC13

void setup() {
  pinMode(PIN_INDICATOR_LED, OUTPUT);
}

void loop() {
  delay(200);
  digitalWrite(PIN_INDICATOR_LED, HIGH);
  delay(200);
  digitalWrite(PIN_INDICATOR_LED, LOW);

}
