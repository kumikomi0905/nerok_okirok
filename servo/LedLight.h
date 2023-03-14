#pragma once

//2021.4月A班のソースコード参考

/*
 * 白を含めた7色の光が点灯する
 * デバッグ用
 */
#define GREENPIN 9
#define REDPIN 10
#define BLUEPIN 11
#define DELAY_TIME 3000

typedef enum{
 RED,
 GREEN,
 BLUE,
 YELLOW,
 SKYBLUE,
 PURPLE,
 WHITE
}LED_COLOR;


class LedLight {

  private:
    int Redpwm;
    int Greenpwm;
    int Bluepwm;
    int Get_up;
    int Every_Bed = 120;   //2分おきに
    int Before_Bed = 600;  //10分前
    int Blink_Bed = 10;    //10秒前
    int ledColor;
    int max_bright = 255;       //1番明るい
    int bright = 191;           //明るい
    int middle_bright = 127;    //真ん中の明るさ
    int dark = 87;             //暗い
    int max_dark = 47;         //1番暗い



  public:
    void ledSleepy();
    void ledGetup();
    void ledOff();
    LedLight(); //コンストラクタ
};
