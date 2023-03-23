#pragma once

class Alarm{
  private:
    bool alarm_on;
    int Buzzer_Pin;
    void init_player();          //playerの初期化処理
    

  public:
    void init(int buzzer_pin);               //ブザーの初期化処理
    void buzzer_start();       //アラームスタート
    void buzzerOff();   //アラームストップ

}


#endif
