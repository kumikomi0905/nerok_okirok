#include <I2CLiquidCrystal.h>
#include <mglcd.h>

#include <Arduino.h>
#include "Display.h"
#include <Wire.h>

// 初期化処理
void Display::init() {
  Wire.begin();
  init_LCD();
}

// 文字データ送信処理
void Display::writeData(byte t_data)
{
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x40);
  Wire.write(t_data);
  Wire.endTransmission();
  delay(1);
}

// コマンド送信処理
void Display::writeCommand(byte t_command)
{
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x00);
  Wire.write(t_command);
  Wire.endTransmission();
  delay(10);
}

// LCDの初期化処理
void Display::init_LCD() {
  delay(100);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x39);
  delay(20);
  writeCommand(0x14);
  delay(20);
  writeCommand(0x73);
  delay(20);
  writeCommand(0x52);
  delay(20);
  writeCommand(0x6C);
  delay(20);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x01);
  delay(20);
  writeCommand(0x0C);
  delay(20);
}

void Display::cursorMove(int place) {    //返却値なし 引数 整数型(カーソルを移動させたいアドレス)
  writeCommand(place + 0x80);   //インストラクションコード 0x80 カーソル移動
  //それに移動させたいアドレスを足し合わせることで そのアドレスにカーソルを移動させる
  // writeCommand(place + 0x80); が  プログラム中に出てきてもインストラクションコードを分からないと読めない
  // cursorMoveなら名前から意味が想像しやすく 可読性 を上げることができる
}

void Display::printString(String str) {
  int i  = 0;
  int len = str.length();

  for (i = 0; i < len; i++) {
    writeData(str.charAt(i)); //CharAt()...引数で指定した位置の文字を返す
    delay(1);
  }
}

char moji_wakeUp[] = "WakeUpSetting";
char moji_bed[] = "BedSetting";
char koron[] = ":";


void Display::timeMode_screen(int modeNum) {

  switch (modeNum) {
    case 1:
      cursorMove(0x00);        //1行目
      for (int i = 0; i < sizeof(moji_wakeUp); i++) {
        writeData(moji_wakeUp[i]);
      }
      break;
    case 2:
      cursorMove(0x00);        //1行目
      for (int i = 0; i < sizeof(moji_wakeUp); i++) {
        writeData(moji_bed[i]);
      }
      break;
  }
  cursorMove(0x47);
  writeData(koron[0]);
}

/* 起床時間の画面表示（仮） */
void Display::timeHour_screen(int timeHour_sc) {
  printString((String)timeHour_sc);
}

/* 就寝時間の画面表示（仮） */
void Display::timeMinutes_screen(int timeMinutes_sc) {
  printString((String)timeMinutes_sc);
}

/* 秒の時間表示 */
void Display::timeSeconds_screen(int timeSeconds_sc){
  printString((String)timeSeconds_sc);
}

/* 現在時間の画面表示 */
void Display::currentTime_screen(int currentYear, int currentMonth, int currentDay, int currentHour ,int currentMinutes, int currentSeconds){
  cursorMove(0x01);
  //1行目にYear/Month/Dayを表示
  printString((String)currentYear);
  printString(slash);
  printString((String)currentMonth);
  printString(slash);
  printString((String)currentDay);

  cursorMove(0x44);
  timeHour_screen(currentHour);
  printString(koron);
  timeMinutes_screen(currentMinutes);
  printString(koron);
  timeSeconds_screen(currentSeconds);
}
