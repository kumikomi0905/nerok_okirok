#include "servo.h"

class servo {

  private:

    Servo servo;    
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
