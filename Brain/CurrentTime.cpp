#include<Arduino.h>
#include"Brain.h"
#include"CurrentTime_h"
#include <RTClib.h>

int CurrentTime::time_Check(){
if(){

}
  
}

void CurrentTime::setrealTime(int Rtc_year,int Rtc_mon,int Rtc_day,int Rtc_hour,int Rtc_min,int Rtc_sec){
RTC_DS1307 RTC;
    RTC.begin();
    RTC.adjust(DateTime(Rtc_year,Rtc_mon,Rtc_day,Rtc_hour,Rtc_min,Rtc_sec));
  
}

int CurrentTime::send_CurrentTime(){

  
}
