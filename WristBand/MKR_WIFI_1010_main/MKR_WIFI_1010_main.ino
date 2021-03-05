#include "MKR_HeaderFile.h"

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
