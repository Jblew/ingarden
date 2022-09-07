#include "WifiNtpClock.h"
#include <Arduino.h>
#include <WiFi.h>

WifiNtpClock::WifiNtpClock() {

}

void WifiNtpClock::syncTime() {
  bool connected = this->connectWifi(this->wifiMaxConnectionAttempts);
  if(!connected && this->restartESP32OnMaxAttemptsExceeded) {
    Serial.println("Wifi connection failed. Restarting the chip.");
    ESP.restart();
    return;
  }
  this->doSyncTime();
  this->disconnectWifi();
}

bool WifiNtpClock::connectWifi(int maxAttempts) {
  Serial.printf("Connecting to WiFi %s...\n", this->wifi_ssid);
  WiFi.mode(WIFI_STA);
  int attempt = 0;
   for(;;) {
        attempt++;

        WiFi.begin(this->wifi_ssid, this->wifi_password);

        uint8_t status = WiFi.waitForConnectResult();

        if (status == WL_CONNECTED) {
            Serial.println("Connected");
            return true;
        }
        Serial.printf("Failed attempt %d of %d\n", attempt, maxAttempts);
        if(attempt > maxAttempts) {
          return false;
        }
   }
   return true;
}

void WifiNtpClock::doSyncTime() {
  configTime(0, 0, this->ntp_primary_server_domain, this->ntp_secondary_server_domain);
  Serial.println("Waiting on time sync...");
  while (time(nullptr) < 1510644967)
  {
      delay(10);
  }
  Serial.println("Time synced");
}

void WifiNtpClock::disconnectWifi() {
  WiFi.disconnect();
}