#include<Arduino.h>
#include"Brain.h"
#include"DicisionButton.h"

DicisionButton::Button(int button_pin, BTN_MODE mode,void*function){
  if(mode == D_READ){
    PinNumber = button_pin;
    pinMode(PinNumber, INPUT);
  }else{
    attachInterrupt(button_pin,function, RISING);
  }
}

int Button::Read(){
  return digitalRead(PinNumber);
}
