#include <I2CLiquidCrystal.h>
#include <mglcd.h>

#include <Arduino.h>
#include "Display.h"
#include <Wire.h>

int WakeUp_Hour = 0;
int WakeUp_Minute = 0;
int Bed_Hour = 0;
int Bed_Minut = 0;
int timemode = 0;

int decision;
int timeHous;
int timeMinute;

decision = digitalRead( btn_3 );
timeHous = digitalRead( btn_1 );
timeMinute = digitalRead( btn_2 );

// 初期化処理
void Lcd::init() {
  Wire.begin();
  init_LCD();
}

// 文字データ送信処理
void Lcd::writeData(byte t_data)
{
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x40);
  Wire.write(t_data);
  Wire.endTransmission();
  delay(1);
}

// コマンド送信処理
void Lcd::writeCommand(byte t_command)
{
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x00);
  Wire.write(t_command);
  Wire.endTransmission();
  delay(10);
}

// LCDの初期化処理
void Lcd::init_LCD() {
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

/* 起床時間の時間設定ボタン */
int wakeUp_setTime() {
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
        WakeUp_Minute++;
        if (WakeUp_Minute > 59) {
          WakeUp_Minute = 0;
        }
      }
    default:
      break;
  }

  return WakeUp_Hour, WakeUp_Minute;

}
/* 就寝時間の時間設定ボタンボタン */
int bed_setTime() {
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
        Bed_Minut++;
        if (Bed_Minut > 59) {
          Bed_Minut = 0;
        }
      }
    default:
      break;
  }

  return Bed_Hour, Bed_Minut;

}
