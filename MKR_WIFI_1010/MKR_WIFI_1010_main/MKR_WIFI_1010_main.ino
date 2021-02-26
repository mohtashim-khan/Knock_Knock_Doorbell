#include "MKR_HeaderFile.h"
void setup() {
  //connectBluetooth();
  connectWifi();
  

}

void loop() {
  Blynk.run(); //BLYNK connection
  
  if(doorbellButtonPressed())
  {
	  sendWristBandNotif();
    sendPhoneNotif();
  }
	  
  
  

}

void sendPhoneNotif()
{
  Blynk.notify("Someone is at the door!");
}

void send WristBandNotif()
{
  
}
