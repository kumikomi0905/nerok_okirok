#include <Arduino.h>
#include"LedLight.h"


/*【ToDo】光量調節はタイマー関数を使う
 * (理由)ディレイの間は割り込みボタン以外なにも作動しない
 *＋割り込みでモードが変わった場合、戻ってきたときに
 *次の光量に移るから時間間隔が10分じゃなくなる
 */

//コンストラクタ
LedLight::LedLight(){
  pinMode(GREENPIN, OUTPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
//いきなり光るということが無い様、念のためlowに初期化しておく
 digitalWrite(REDPIN, LOW);
 digitalWrite(BLUEPIN, LOW);
 digitalWrite(GREENPIN, LOW);
}

//起床ライト機能(起床ライトは朝日のイメージで白色点灯)
//Brainが起床時刻になったと感知したら日の出ライトを呼び出し

void LedLight::ledGetup(){
  //ライト点灯(3色点灯で白色の予定)
  digitalWrite(GREENPIN,HIGH);
  digitalWrite(REDPIN,HIGH);
  digitalWrite(BLUEPIN,HIGH);
 
}

//Brainがサブボタンで起床を確認したら日の出ライト消灯を呼び出し

void LedLight::ledOff(){
  //ライト消灯
  digitalWrite(GREENPIN,LOW);
  digitalWrite(REDPIN,LOW);
  digitalWrite(BLUEPIN,LOW);
}


//就寝ライト機能(就寝ライトは温かみのある落ち着いた暖色系の予定)
//Brainが現在時刻取得より就寝10分前になったらライト10秒間点滅
//その後点灯

void LedLight::ledSleepy(){
  //Led10秒点滅
   for (int i=0; i <= 10; i++){
      digitalWrite(GREENPIN,HIGH);
      digitalWrite(REDPIN,HIGH);
      delay(500);
      digitalWrite(GREENPIN,LOW);
      digitalWrite(REDPIN,LOW);
      delay(500);
      }
  //その後Ledライトが10分の間に5段階で2分ごとに明るさレベルを落としていく関数呼び出す
  //そして完全消灯になる

  //明るさ：1番明るい
      analogWrite( GREENPIN, max_bright );
      analogWrite( REDPIN, max_bright );
      delay(120000);  //2分待つ
  
  //明るさ：明るい
      analogWrite( GREENPIN, bright );
      analogWrite( REDPIN, bright );
      delay(120000);  //2分待つ

  //明るさ：真ん中の明るさ
      analogWrite( GREENPIN, middle_bright );
      analogWrite( REDPIN, middle_bright );
      delay(120000);  //2分待つ

  //明るさ：暗い
      analogWrite( GREENPIN, dark );
      analogWrite( REDPIN, dark );
      delay(120000);  //2分待つ

  //明るさ：1番暗い
      analogWrite( GREENPIN, max_dark );
      analogWrite( REDPIN, max_dark );
      delay(120000);  //2分待つ

  //消灯
      digitalWrite(GREENPIN,LOW);
      digitalWrite(REDPIN,LOW);
  
}
