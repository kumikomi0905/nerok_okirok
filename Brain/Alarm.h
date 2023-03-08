#pragma once

class Alarm{
  private:
    bool alarm_on;
    int Buzzer_Pin

  public:
    void buzzer_start();       //アラームスタート
    void buzzerOff(bool alarm_on);   //アラームストップ
    void BuzzerOn();           //ブザーON
    void BuzzerOff();          //ブザーOFF
}


#endif
