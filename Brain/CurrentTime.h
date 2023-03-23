#pragma once

class CurrentTime
{
  private:
<<<<<<< HEAD
   int espNumber;
   int realTime;
   
   public:
   int Time_Check();
   void setrealTime();
   int send_CurrentTime();
   
};   
=======
    int espNumber;            //espのピン番号
    int realTime;             //RTCのピン番号


  public:
    int Time_Check(int wifi_time,int setting_time);
    void setrealTime(int Rtc_year,int Rtc_mon,int Rtc_day,int Rtc_hour,int Rtc_min,int Rtc_sec);
    int send_CurrentTime();

}



#endif
>>>>>>> 086bc87723080ca1f7999e8f8869c7d3a931b8dc
