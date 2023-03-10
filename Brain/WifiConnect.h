#pragma once

class WifiConnect {

  private:
  const char* ssid = "";
  const char* password = "";


  public:
  WiFi.begin(ssid, password);
  int data_send();

};
