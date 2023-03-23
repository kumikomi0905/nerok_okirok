#pragma once

class CurrentTime {

  private:
    int espNumber;            //espのピン番号
    int realTime;             //RTCのピン番号


  public:
    int Time_Check(int wifi_hour,int wifi_minute,int setting_hour,int setting_minute);
    void setrealTime(int Rtc_year,int Rtc_mon,int Rtc_day,int Rtc_hour,int Rtc_min,int Rtc_sec);
    int send_CurrentTime();

}



#endif
