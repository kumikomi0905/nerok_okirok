#pragma once

class LedLight {

  private:
    int Redpwm;
    int Greenpwm;
    int Bluepwm;
    int Get_up;
    int Every_Bed = 120   //2分おきに
    int Before_Bed = 600  //10分前
    int Blink_Bed = 10    //10秒前
    int ledColor;


  public:
    void ledSleepy();
    void ledGetup();
    void ledOff();
}
