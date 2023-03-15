#include "Brain.h"
#include "DicisionButton.h"
#include "CurrentTime.h"
#include "Display.h"

/* 後で記述 */
DicisionButton btn_1 = DicisionButton(BTN_PIN1, D_READ, NULL); /* 時間 */
DicisionButton btn_2 = DicisionButton(BTN_PIN2, D_READ, NULL); /* 分*/
DicisionButton btn_3 = DicisionButton(BTN_PIN3, D_READ, NULL); /* 決定 */
DicisionButton btn_4 = DicisionButton(BTN_PIN4, INTERRPUT, NULL); /* モード変更 */
DicisionButton btn_5 = DicisionButton(BTN_PIN5, INTERRPUT, NULL); /* 緊急解除*/

void setup() {
  

}

int mode = 1;
int hour = 0;
int minute = 0;


void loop() {

  /* モードチェンジ設定する */

  switch (mode) {
    case 1:

      break;
    case 2:
      WakeUp_setTime();
      break;
    case 3:
      Bed_setTime();
      break;
  }


}


void modeChangePush() {
  //デジタルピン？番のスイッチが押された場合にはモード設定に入る
  mode++;
  if (3 < mode) {
    mode = 1;
  }

}
