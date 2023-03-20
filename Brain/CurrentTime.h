#pragma once

class CurrentTime {

  private:
    int espNumber;            //espのピン番号
    int realTime;             //RTCのピン番号


  public:
    int Time_Check(int wifi_time,int setting_time);
    void setrealTime(int Rtc_year,int Rtc_mon,int Rtc_day,int Rtc_hour,int Rtc_min,int Rtc_sec);
    int send_CurrentTime();

}



#endif
