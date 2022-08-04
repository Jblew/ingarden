#include "Arduino.h"
#include "TinyGPS++.h"

HardwareSerial Serial3(PB11, PB10);
TinyGPSPlus gps;

#define PIN_INDICATOR_LED PC13
#define PIN_RACK_LAMP PA8

void setup() {
  pinMode(PIN_INDICATOR_LED, OUTPUT);
  pinMode(PIN_RACK_LAMP, OUTPUT);
  Serial3.begin(9600);
}

void loop() {
  while (Serial3.available() > 0) {
    char c = Serial3.read();
    gps.encode(c);
  }

  int hour = gps.time.hour();
  int minute = gps.time.minute();
  int second = gps.time.second();

  if(second % 2 == 0) {
    digitalWrite(PIN_INDICATOR_LED, HIGH);
  } else {
    digitalWrite(PIN_INDICATOR_LED, LOW);
  }
  analogWrite(PIN_RACK_LAMP, second * 2);
}
