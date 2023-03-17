/* インクルードガード */
#pragma once

#define LCD_ADRS 0x3E

class Display     // classの定義
{
  private :               // privateはクラス内からしかアクセスできない
    void init_LCD();

  public :                // publicはどこからでもアクセス可能
    void init();                          //初期化処理
    void writeData(byte t_data);          //文字データ送信処理
    void writeCommand(byte t_command);    //コマンド送信処理（画面クリアやカーソル表示）
    void cursorMove(int place);
    void printString(String str);

    void timeMode_screen(int modeNum);      //1行目に起床・就寝の文字列を表示
    
    void timeHour_screen(int timeHour_sc);       //時の数字を表示
    void timeMinutes_screen(int timeMinutes_sc); //分の数字を表示
};
