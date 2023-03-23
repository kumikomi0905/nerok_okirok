<<<<<<< HEAD
#include <Arduino.h>
#include"CurrentTime.h"

//時間比較
CurrentTime::Time_Check(){
  //現在時刻と各設定時間を比較
  
};
//値の格納
CurrentTime::setrealTime();
//値の送信
CurrentTime::send_CurrentTime();
=======
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
>>>>>>> 086bc87723080ca1f7999e8f8869c7d3a931b8dc

//シナリオの現在時刻を確認
//現在時刻の変数決まり次第Time_Check()で比較
//
