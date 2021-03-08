#include "MKR_HeaderFile.h"

//WRISTBAND

void setup() {
  connectWifi();
}


void loop() 
{
  Blynk.run(); //BLYNK connection
}
  

BLYNK_CONNECTED() {
    Blynk.syncAll();
}
