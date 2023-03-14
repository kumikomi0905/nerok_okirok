/* インクルードガード */
#pragma once

#define LCD_ADRS 0x3E

class Display     // classの定義
{
  private :               // privateはクラス内からしかアクセスできない
    void init_LCD();
    int minCount;
    int hourCount;
    
  public :                // publicはどこからでもアクセス可能
    void init();                          //初期化処理
    void writeData(byte t_data);          //文字データ送信処理
    void writeCommand(byte t_command);    //コマンド送信処理（画面クリアやカーソル表示）
    int wakeUp_setTime();                 //起床時間のセット
    int bed_setTime();                    //就寝時間のセット
    void wakeUp_screen();//仮
    void bed_screen();   //仮 
};
