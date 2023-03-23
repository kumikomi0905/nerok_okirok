#include "WifiConnect.h"
#include<WiFi.h>
#include <time.h>
#include <stdio.h>
#define JST     3600* 9

const char* ssid = "Tina";
const char* password = "Tina0107";

void WifiConnect::WiFi_setUp() {
  //Serial.begin(115200);
  delay(100);
  Serial.print("\n\nStart\n");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println();
  Serial.printf("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  configTime( JST, 0, "ntp.nict.jp", "ntp.jst.mfeed.ad.jp");
}


tm* WifiConnect::data_send() {
  time_t t;
  struct tm *tm;
  //static const char *wd[7] = {"Sun", "Mon", "Tue", "Wed", "Thr", "Fri", "Sat"};

  t = time(NULL);
  tm = localtime(&t);
  //  Serial.printf(" %04d/%02d/%02d(%s) %02d:%02d:%02d\n",
  //        tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
  //        wd[tm->tm_wday],
  //        tm->tm_hour, tm->tm_min, tm->tm_sec);
  delay(1000);
  return localtime(&t);
  //return (*tm).tm_hour;
}
