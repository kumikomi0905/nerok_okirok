#pragma once

/* pin管理 */
#define BTN_PIN1 34   /* 時間設定ボタン　通常 */
#define BTN_PIN2 35   /* 分設定ボタン　通常 */
#define BTN_PIN3 33   /* 決定ボタン　割り込み */
#define BTN_PIN4 32   /* モードボタン　割り込み */
#define BTN_PIN5 25   /* 緊急解除ボタン　割り込み */

typedef enum{
  INTI,         //初期状態
  WAIT,         //待機状態
}MODE;

typedef enum{
  ENTRY,        //エントリー
  DO,           //ドゥー 
  EXIT,         //イグジット
}ACTION_STATE;



#endif
