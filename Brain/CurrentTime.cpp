#include<Arduino.h>
#include"Brain.h"
#include"CurrentTime_h"
#include <RTClib.h>

  int time_Check(int wifi_hour,int wifi_minute,int setting_hour,int setting_minute){

  //判定に使う変数
  int judgement = 0;
  
    if((wifi_hour == setting_hour)&&(wifi_minute == setting_minute)){

    //現在時刻と設定時間が一致したら1を返す
      judgement = 1;

   }

    return judgement;
  
}

void CurrentTime::setrealTime(int Rtc_year,int Rtc_mon,int Rtc_day,int Rtc_hour,int Rtc_min,int Rtc_sec){
RTC_DS1307 RTC;
    RTC.begin();
    RTC.adjust(DateTime(Rtc_year,Rtc_mon,Rtc_day,Rtc_hour,Rtc_min,Rtc_sec));
  
}

int CurrentTime::send_CurrentTime(){

  
}
