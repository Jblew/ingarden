#ifndef WIFINTPCLOCK_H
#define WIFINTPCLOCK_H

class WifiNtpClock
{
public:
  WifiNtpClock();
  char *wifi_ssid;
  char *wifi_password;
  char *ntp_primary_server_domain;
  char *ntp_secondary_server_domain;
  int wifiMaxConnectionAttempts;
  bool restartESP32OnMaxAttemptsExceeded;
  void syncTime();

private:
  bool connectWifi(int maxAttempts);
  void doSyncTime();
  void disconnectWifi();
};

#endif // WIFINTPCLOCK_H