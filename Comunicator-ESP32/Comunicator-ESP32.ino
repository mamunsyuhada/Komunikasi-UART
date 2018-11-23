//Nerima data dari si Teensy

HardwareSerial uartTeensy(2);
String response;

#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600);
  uartTeensy.begin(9600);
}

void loop() {
  getTeensySerial();
}
