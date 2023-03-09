include<Arduino.h>
include"servo.h"

//あとで記述　サーボピン番号
//#define Servo_PIN 〇

Servo::Servo(int Servo){
  m_Servo_pin = Servo_pin;
}

//設定角度を取得
int Servo::getPreferenceAngle(){
  return preferenceAngle;
}

//設定角度を設定
void Servo::setPreferenceAngle(int Angle){
  preferenceAngle = angle;
}

//初期値設定
void Servo::init(){
  Servo.write();
}

//途中経過ここまで
