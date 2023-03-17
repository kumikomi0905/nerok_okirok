#include<Arduino.h>
#include"Brain.h"
#include"AnotherTerminal.h"
#include "BluetoothSerial.h"


BluetoothSerial SerialBT;

bool judgment = true;

void AnotherTerminal::Bluetooth_setup() {

  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
 // pinMode( 2, OUTPUT);
 // pinMode(14, OUTPUT);

  // Sign for the end of bluetooth setup.
  for (int i = 0; i < 3; i++) {
    digitalWrite(2, HIGH);
    delay(50);
    digitalWrite(2, LOW);
    delay(50);
  }
}

int AnotherTerminal::Signal_acquisition() {
  if (SerialBT.available()) {
    if (SerialBT.read() == 'T') {
     //digitalWrite(14, HIGH);
     return judgment;
    }
  }
  delay(20);
  //digitalWrite(14, LOW);
}


}
