#include "Arduino.h"
#include "secrets.h"
#include <WiFi.h>

#ifndef SECRET_WIFI_SSID
#error You have to define SECRET_WIFI_SSID in secrets.h
#endif

#ifndef SECRET_WIFI_PASSWORD
#error You have to define SECRET_WIFI_PASSWORD in secrets.h
#endif

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Hello world");
  Serial.printf("ssid=%s/n", SECRET_WIFI_SSID);
}
