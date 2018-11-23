//Transmitter data

#define uartESP32 Serial2
#include <ArduinoJson.h>

void setup() {
  uartESP32.begin(9600);
}

void loop() {
  String temp = (String)random(10, 40);
  String rh = (String)random(50, 80);
  String gps[2];
  double longitude = random(-7.000001, 110.002933019);
  double latitude = random(-7.000001, 110.002933019);
  gps[0] = String(longitude, 6);
  gps[1] = String(latitude, 6);

  DynamicJsonBuffer  jsonBuffer(200);
  JsonObject& root = jsonBuffer.createObject();
  root["temp"] = String(temp);
  root["rh"] = String(rh);
  
  JsonArray& gpsneo8m = root.createNestedArray("gpsneo8m");
  gpsneo8m.add(gps[0]);
  gpsneo8m.add(gps[1]);
  root.printTo(uartESP32);
  delay(200);
}
