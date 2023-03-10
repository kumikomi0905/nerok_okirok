#include<Arduino.h>

//#define Servo_PIN 〇 //あとで記述　サーボピン番号



//設定角度を取得
 Servo::getPreferenceAngle(){
  return preferenceAngle;
}

//設定角度を設定
 Servo::setPreferenceAngle(int angle){
  preferenceAngle = angle;
}

//初期値設定
 Servo::init(){
  Servo.write();
  Servo.read();
}

//'Servo' does not name a type; did you mean 'Serial'?
//エラー確認
