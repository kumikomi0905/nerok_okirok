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
    void cursorMove(int place);
    void printString(String str);
    
    int wakeUp_setTime();                 //起床時間の設定
    int bed_setTime();                    //就寝時間の設定
    
    void wakeUp_screen();                 //起床時間の画面表示
    void bed_screen();                    //就寝時間の画面表示

};
