#include "Brain.h"
#include "DicisionButton.h"
#include "CurrentTime.h"

DicisionButton btn_1 = DicisionButton(int BTN_PIN1, BTN_MODE D_READ); /* 時間 */
DicisionButton btn_2 = DicisionButton(int BTN_PIN2, BTN_MODE D_READ); /* 分*/
DicisionButton btn_3 = DicisionButton(int BTN_PIN3, BTN_MODE D_READ); /* 決定 */
DicisionButton btn_4 = DicisionButton(int BTN_PIN4, BTN_MODE INTERRPUT, void* modeChangePush); /* モード変更 */
DicisionButton btn_5 = DicisionButton(int BTN_PIN5, BTN_MODE INTERRPUT, void* ); /* 緊急解除*/

void setup() {
  // put your setup code here, to run once:

}

int mode = 1;
int hour = 0;
int minute = 0;


void loop() {
  // put your main code here, to run repeatedly:

  /* モードチェンジ設定する */

  switch (mode) {
    case 1:

      break;
    case 2:
      WakeUp_setTime
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
