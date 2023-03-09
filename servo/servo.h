pragma once
include<ESP32Servo.h>

class servo {

  private:

    Servo servo;    //Servoクラスからインスタンスを生成
    int servo_pin;

    int preferenceAngle = 90;    //初期設定角度　　

  public:

    Servo(servo_pin);
    void openServo();
    void closeServo();
    void init();
    int getpreferenceAngle();
    int setpreferenceAngle();
};
