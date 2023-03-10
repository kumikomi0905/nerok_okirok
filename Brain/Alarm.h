#pragma once

class Alarm{
  private:
    bool alarm_on;
    int Buzzer_Pin

  public:
    void init(int buzzer_pin);               //ブザーの初期化処理
    void init_player;          //playerの初期化処理
    void buzzer_start();       //アラームスタート
    void buzzerOff(bool alarm_on);   //アラームストップ

}


#endif
