#include "Arduino.h"
#include "secrets.h"
#include "WifiNtpClock/WifiNtpClock.h"
#include <time.h>

#ifndef SECRET_WIFI_SSID
#error You have to define SECRET_WIFI_SSID in secrets.h
#endif

#ifndef SECRET_WIFI_PASSWORD
#error You have to define SECRET_WIFI_PASSWORD in secrets.h
#endif

WifiNtpClock ntpClock;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  ntpClock.wifi_ssid = strdup(SECRET_WIFI_SSID);
  ntpClock.wifi_password = strdup(SECRET_WIFI_PASSWORD);
  ntpClock.ntp_primary_server_domain = strdup("pool.ntp.org");
  ntpClock.ntp_secondary_server_domain = strdup("time.nist.gov");
  ntpClock.restartESP32OnMaxAttemptsExceeded = true;
  ntpClock.wifiMaxConnectionAttempts = 15;
  delay(4000);
  ntpClock.syncTime();
  time_t now;
  time(&now);
  struct tm * timeinfo = localtime(&now);
  Serial.printf("Time synced, it is %d:%d", timeinfo->tm_hour, timeinfo->tm_min);
}

void loop()
{
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}
