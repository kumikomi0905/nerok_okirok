#include "WifiConnect.h"
#include<WiFi.h>
#include <time.h>
#include <stdio.h>
const IPAddress ip(192, 168, 203, 69);
//サーバーのIPアドレス
const IPAddress subnet(255, 255, 255, 0);
//サブネットマスク
Wifi::wifibegin(char ssid, char password) {
  WiFi.softAP(ssid, pass);
  //SSIDとパスの設定

  WiFi.begin(ssid, pass);
  delay(100);

  //接続失敗防止
  WiFi.softAPConfig(ip, ip, subnet);
  //IPアドレス、ゲートウェイ、サブネットマスクの設定
  IPAddress myIP = WiFi.softAPIP();

  //WiFi.softAPIP()でWiFi起動
  server.begin(); //サーバーを起動(htmlを表示させるため)
  Serial.println();   /*各種情報を表示*/
  Serial.println("WiFi connected");
  Serial.print("SSID：");
  Serial.println(ssid);
  Serial.print("AP IP address：");
  Serial.println(myIP);
  Serial.println("Server start!");
}


int Wifi::data_send() {
  time_t t;
  struct tm *tm;
  static const char *wd[7] = {"Sun", "Mon", "Tue", "Wed", "Thr", "Fri", "Sat"};
  t = time(NULL);
  tm = localtime(&t);
  Serial.printf(" %04d/%02d/%02d(%s) %02d:%02d:%02d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, wd[tm->tm_wday], tm->tm_hour, tm->tm_min, tm->tm_sec);
  delay(1000);

return tm.tm_hour;
}
