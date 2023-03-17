#include "Brain.h"
#include "DicisionButton.h"
#include "CurrentTime.h"
#include "Display.h"
#include "AnotherTerminal.h"

//DicisionButtonクラスのインスタンス
DicisionButton btn_1 = DicisionButton(BTN_PIN1, D_READ, NULL); /* 時間 */
DicisionButton btn_2 = DicisionButton(BTN_PIN2, D_READ, NULL); /* 分*/
DicisionButton btn_3 = DicisionButton(BTN_PIN3, D_READ, NULL); /* 決定 */
DicisionButton btn_4 = DicisionButton(BTN_PIN4, INTERRPUT, NULL); /* モード変更 */
DicisionButton btn_5 = DicisionButton(BTN_PIN5, INTERRPUT, NULL); /* 緊急解除*/

//Displayクラスのインスタンス
Display disp;

void setup() {
  // put your setup code here, to run once:
  disp.init();
}

int mode = 1;
int hour = 0;
int minute = 0;

int WakeUp_Timehour = 0;
int WakeUp_Timeminutes = 0;
int Bed_Timehour = 0;
int Bed_Timeminutes = 0;


void loop() {
  
  /* モードチェンジ設定する */
  switch (mode) {
    case 1:

      break;
    case 2:
      wakeUp_SetButton();
      break;
    case 3:
      bed_SetButton();
      break;
  }
}

/* 起床時間の設定 */
void wakeUp_SetButton(){
  disp.timeMode_screen(1);      //「WakeUpSetting」を画面に表示
  
  disp.cursorMove(0x44);   //時のカーソルに移動

  //決定ボタンが押されるまでループする
  while(!btn_3.Read() == true){
    if (btn_1.Read() == true) {   //時のボタンが押されるたびに数字をカウント
        WakeUp_Timehour++;
        if (WakeUp_Timehour > 23) {
          WakeUp_Timehour = 0;
        }
        disp.timeHour_screen(WakeUp_Timehour);  //時の数字を画面表示
      }
  }

  disp.cursorMove(0x49);   //分のカーソルに移動

  //決定ボタンが押されるまでループする
  while(!btn_3.Read() == true){
    if (btn_2.Read() == true) {   //分のボタンが押されるたびに数字をカウント
        WakeUp_Timeminutes++;
        if (WakeUp_Timeminutes > 59) {
          WakeUp_Timeminutes = 0;
        }
        disp.timeMinutes_screen(WakeUp_Timeminutes);//画面表示
      }
  }

}

/* 就寝時間の設定 */
void bed_SetButton(){

  disp.timeMode_screen(2);        //「BedSetting」を画面に表示
  
  disp.cursorMove(0x44);   //時のカーソルに移動

  //決定ボタンが押されるまでループする
  while(!btn_3.Read() == true){
    if (btn_1.Read() == true) {   //時のボタンが押されるたびに数字をカウント
        Bed_Timehour++;
        if (Bed_Timehour > 23) {
          Bed_Timehour = 0;
        }
        disp.timeHour_screen(Bed_Timehour);   //時の数字を画面表示
      }
  }

  disp.cursorMove(0x49);   //分のカーソルに移動

  //決定ボタンが押されるまでループする
  while(!btn_3.Read() == true){
    if (btn_2.Read() == true) {   //分のボタンが押されるたびに数字をカウント
        Bed_Timeminutes++;
        if (Bed_Timeminutes > 59) {
          Bed_Timeminutes = 0;
        }
        disp.timeMinutes_screen(Bed_Timeminutes);   //分の数字を画面表示
      }
  }
}

void modeChangePush() {
  //デジタルピン？番のスイッチが押された場合にはモード設定に入る
  mode++;
  if (3 < mode) {
    mode = 1;
  }
}
