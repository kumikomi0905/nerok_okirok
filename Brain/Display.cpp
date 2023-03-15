#include <I2CLiquidCrystal.h>
#include <mglcd.h>

#include <Arduino.h>
#include "Display.h"
#include <Wire.h>

int WakeUp_Hour = 0;
int WakeUp_Minutes = 0;
int Bed_Hour = 0;
int Bed_Minutes = 0;
int timemode = 0;

int decision;
int timeHous;
int timeMinute;

//decision = digitalRead( btn_3 );
//timeHous = digitalRead( btn_1 );
//timeMinute = digitalRead( btn_2 );

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

void Display::cursorMove(int place){     //返却値なし　引数　整数型(カーソルを移動させたいアドレス)
  writeCommand(place + 0x80);   //インストラクションコード 0x80 カーソル移動
                                //それに移動させたいアドレスを足し合わせることで　そのアドレスにカーソルを移動させる
                                // writeCommand(place + 0x80);　が  プログラム中に出てきてもインストラクションコードを分からないと読めない
                                // cursorMoveなら名前から意味が想像しやすく　可読性　を上げることができる
}

void Display::printString(String str){
  int i  = 0;
  int len = str.length();

  for(i = 0; i < len; i++){
    writeData(str.charAt(i)); //CharAt()...引数で指定した位置の文字を返す
    delay(1);
  }
}

char moji_wakeUp[] = "WakeUpSetting";
char moji_bed[] = "BedSetting";
char koron[] = ":";

/* 起床時間の画面表示（仮） */
void Display::wakeUp_screen() {

  writeCommand(0x01); //画面クリア
  
  cursorMove(0x00);        //1行目
  for (int i = 0; i < sizeof(moji_wakeUp); i++) {
    writeData(moji_wakeUp[i]);
  }
  
  cursorMove(0x44); // 2LINE TOP 2行目
  
  printString((String)WakeUp_Hour);
  
  cursorMove(0x47);
  writeData(koron[0]);
  
  cursorMove(0x49);
  printString((String)WakeUp_Minutes);
}

/* 就寝時間の画面表示（仮） */
void Display::bed_screen() {
  
  writeCommand(0x01); //画面クリア
  
  cursorMove(0x00);        //1行目
  for (int i = 0; i < sizeof(moji_bed); i++) {
    writeData(moji_bed[i]);
  }
  
  cursorMove(0x44); // 2LINE TOP 2行目
  
  printString((String)Bed_Hour);
  
  cursorMove(0x47);
  writeData(koron[0]);
  
  cursorMove(0x49);
  printString((String)Bed_Minutes);
}

/* 起床時間の時間設定ボタン */
int Display::wakeUp_setTime() {
  //決定ボタンおされたら時間、分の移動
  if (decision == HIGH) {
    timemode++;
    if (2 < timemode) {
      timemode = 0;
    }
  }

  switch (timemode) {
    case 1:
      if (timeHous == HIGH) {
        WakeUp_Hour++;
        if (WakeUp_Hour > 23) {
          WakeUp_Hour = 0;
        }
      }
      break;
    case 2:
      if (timeMinute == HIGH) {
        WakeUp_Minutes++;
        if (WakeUp_Minutes > 59) {
          WakeUp_Minutes = 0;
        }
      }
    default:
      break;
  }
  wakeUp_screen();

  return WakeUp_Hour, WakeUp_Minutes;

}

/* 就寝時間の時間設定ボタンボタン */
int Display::bed_setTime() {
  //決定ボタンおされたら時間、分の移動

  if (decision == HIGH) {
    timemode++;
    if (2 < timemode) {
      timemode = 0;
    }
  }

  switch (timemode) {
    case 1:
      if (timeHous == HIGH) {
        Bed_Hour++;
        if (Bed_Hour > 23) {
          Bed_Hour = 0;
        }
      }
      break;
    case 2:
      if (timeMinute == HIGH) {
        Bed_Minutes++;
        if (Bed_Minutes > 59) {
          Bed_Minutes = 0;
        }
      }
    default:
      break;
  }
  bed_setTime();

  return Bed_Hour, Bed_Minutes;

}
