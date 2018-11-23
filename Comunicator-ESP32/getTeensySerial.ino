void getTeensySerial() {
  while (uartTeensy.available()) {
    response += char(uartTeensy.read());
    Serial.print(response);
  }
}
