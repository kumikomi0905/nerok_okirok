#pragma once

class CurrentTime{
  private:
    int espNumber;            //espのピン番号
    int realTime;             //RTCのピン番号


  public:
    int time_Check();                         //時間の比例
    void setrealTime();                       //RTCのセット
    int send_CurrentTime();                   //RTCの設定を送る
}

#endif
