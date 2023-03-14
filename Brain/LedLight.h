#pragma once

/*2021.4月A班のソースコード参考
LED点灯　サイト〇https://fabkura.gitbooks.io/arduino-docs/content/chapter5.html
〇https://www.fabshop.jp/%E3%80%90%E5%88%9D%E7%B4%9A%E7%B7%A8%E3%80%91ledx2%E
5%80%8B%E3%82%92%E5%90%8C%E6%99%82%E7%82%B9%E6%BB%85%E3%83%BB%E4%BA%A4%E4%B
A%92%E7%82%B9%E6%BB%85%E3%81%95%E3%81%9B%E3%81%A6%E3%81%BF%E3%82%88/
LED明るさ調節　〇https://deviceplus.jp/arduino/arduino_f04/*/

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
