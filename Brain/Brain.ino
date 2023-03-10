#include "Brain.h"
#include "DicisionButton.h"


void setup() {
  // put your setup code here, to run once:

}

int mode;

void loop() {
  // put your main code here, to run repeatedly:
  
/* ボタンモード変更関数　割り込み */
  if(/* ピン番号 */){
 Button(int /* ピン番号 */, BTN_MODE INTERRPUT, void*modeChangePush);
}

}


void modeChangePush(int mode){
//デジタルピン？番のスイッチが押された場合にはモード設定に入る
            mode++;
            if(3<mode) mode=0;
        
//モードチェンジ設定する

            switch (mode){
                case 1:
                 
                  break;
                case 2:
                 
                  break;
                case 3:
                  
                  break;
            }
        
}
