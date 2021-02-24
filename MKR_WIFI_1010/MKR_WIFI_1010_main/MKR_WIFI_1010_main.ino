#include "MKR_HeaderFile.h"
void setup() {
  // put your setup code here, to run once:
  initBluetooth();
  connectBluetooth();
  connectWifi();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(doorbellButtonPressed())
  {
	  sendPhoneNotif();
	  sendWristBandNotif();
  }
	  
  
  

}
