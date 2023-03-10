#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

void Alarm::init_player() {

  /* MP3プレーヤー DFPLayer */
  SoftwareSerial mySoftwareSerial("", ""); // RX, TX   後で記述
  DFRobotDFPlayerMini myDFPlayer;


  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  pinMode("", INPUT);                          //後で記述

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    　　　　//Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(15);          //ボリューム設定
  myDFPlayer.loop(1);             //ループ再生

}

void Alarm::init(int buzzer_pin) {
  Buzzer_Pin = buzzer_pin;
  pinMode(Buzzer_Pin, INPUT);
  init_player();
}

void buzzer_start() {             //音楽を再生

  if (digitalRead(6) == HIGH) {
    myDFPlayer.playFolder("", "");//後で記述    1つ目の引数がフォルダ番号、2つ目の引数がフォルダの中のmp3の番号
  }

}

void buzzerOff(bool alarm_on) {   //音楽が再生されていたら止まる

  alarm_on = false;
  if (alarm_on == !false) {
    buzzer.stop();
    digitalWrite(Buzzer_Pin, "");         //後で記述

    digitalWrite(Buzzer_Pin, LOW);
  }
}
