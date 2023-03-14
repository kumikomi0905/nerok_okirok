#include <Arduino.h>
#include"ServoMotorDoor.h"
include "servo.h"

//サイト参考 https://burariweb.info/electronic-work/arduino-learning/aruduino-servomotor-control.html#i-3

//Brainがタイムチェック関数で時刻確認して起床時刻になったとき

void ServoMotorDoor::open(){
  myservo.write(servoOpen); //サーボを動かす角度を指定する
}

//Brainがタイムチェック関数で時刻確認して就寝時刻になったとき

void ServoMotorDoor::close(){
    myservo.write(servoClose); //サーボを動かす角度を指定する
}

//Brainが緊急ボタンを感知したとき

void ServoMotorDoor::emergency() {
  myservo.write(servoOpen); //サーボを動かす角度を指定する
}
