#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include "MKR_HeaderFile.h"
void setup() {
  // put your setup code here, to run once:
  initBluetooth();
  initWifi();
  connectBluetooth();
  connectWifi();
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
