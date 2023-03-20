#pragma once

class WifiConnect {

  private:
  const char* ssid = "Tina";
  const char* password = "Tina0107";


  public:
  void WiFi_setUp();
  //WiFi.begin(ssid, password);
  tm* data_send();
};
