#include "MKR_HeaderFile.h"
void setup() {
  //connectBluetooth();
  Blynk.syncAll();
  connectWifi();
  initPins();
  setPins();
  

}

void loop() {
  Blynk.run(); //BLYNK connection
  
  if(doorbellButtonPressed())
  {
	  //sendWristBandNotif();
    sendPhoneNotif();
  }
	  
  
  

}

void sendPhoneNotif()
{
  Blynk.notify("Someone is at the door!");
}

boolean doorbellButtonPressed()
{
  if(digitalRead(DOORBELL_PIN))
  {
   return true;
  }
  else
  return false;
}

void setPins()
{
  pinMode(DOORBELL_PIN, INPUT);
}

void initPins() //Sets all Pins to 0
{
  digitalWrite(DOORBELL_PIN,LOW);
  
}

//void send WristBandNotif()
//{
  
//}
