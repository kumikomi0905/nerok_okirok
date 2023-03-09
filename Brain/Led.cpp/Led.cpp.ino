#include <Arduino.h>
#include "Led.h"

Led::Led(int pin, int num) {
  m_ledPin = pin;
  m_numPixel = num;
  Pixels = Adafruit_NeoPixel(m_numPixel, m_ledPin, NEO_GRB + NEO_KHZ800);

  pixels.begin();   //LED操作をするたの初期化処理

}

//点灯機能
void Led::Getup() {

  //接続されているLEDの個数分順番に発行情報を送る
  for (int i = 0; i < pixels.numPixels(); i++) {

    //発行情報を格納する
    pixels.setPixelColor(i, pixels.Color(RED * 30, GREEN * 30, BLuE * 30));
    MAX_VAL, MAX_VAL, MAX_VAL
    pixels.show();    //LEDに格納した情報を送る
    delay(DELAY_TIME);    //遅延時間
  }


}

//消灯機能
void Led::off() {

  for (int i = 0; i < pixels.numPixels(); i++) { /*接続されているLEDの個数だけ色情報を送る*/
    pixels.serPixelColor(i, pixels.Color(0, 0, 0)); //調光の出力を全て０にする
    pixels.show();    //LEDに格納した情報を送る
    delay(DELAY_TIME);   //遅延時間
  }
}

//調光機能
void Led::dimming(int times) {

  for (int i = 0; i < pixels.numPixels(); i++) { //接続されているLEDの個数だけ色情報を送る

    pixels.setPixeColor(i, pixels.Color(RED * times, GREEN * times, BLUE * times));
    pixels.show();    //LEDに色情報を送る
    delay(DELAY_TIME);    //遅延時間
    
  }
}

void Led::Sleepy(){

  
}
