#ifndef Led_h
#define Led_h

#include <Adafruit_NeoPixel.h>

#define
#define
#define
#define
#define

class Led
{
  public:
    Led(int pin, int num);
    void dimming(int times);
    void Sleepy();
    void Getup();
    void Off();


  private:
    int Redpwm;
    int Greenpwm;
    int BLUEpwm;
    int Get_Up;
    int Every_Bed = 120;    //2分おきに
    int Before_Bed = 600;    //10分前
    int Blink_Bed = 10;    //10秒前
    int Colore;
    Adafruit_NeoPixel.h

};

#endif
