#pragma once

class ServoMotorDoor
{
  private:

   int servoOpen = 90;
   int servoClose = 0;
   void emergency();
   
  Servo myservo;  //スケッチ内で使用するサーボの名前を宣言
                  //has aの関係　ServoMotorDoor　has a Servo

   public:
   void open();
   void close();
   
};   

   
//myservo.attach(7, 500, 2400); //スケッチ内で使用するサーボの名前を宣言

//myservo.attach(7);  //サーボが使用するピンを指定する
