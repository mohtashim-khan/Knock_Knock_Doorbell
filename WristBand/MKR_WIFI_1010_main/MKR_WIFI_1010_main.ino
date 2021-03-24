#include "MKR_HeaderFile.h"

//WRISTBAND

void setup() {
  connectWifi();
  Serial.begin(9600);
}


void loop() 
{
  Blynk.run(); //BLYNK connection
  Serial.print(analogRead(ADC_BATTERY)* (4.3 / 1023.0)+" V");
}


//Process notificatoin from other board

BLYNK_WRITE(V5){
  int vibrationStrength = param.asInt();
  
  
  
}

BLYNK_CONNECTED() {
    Blynk.syncAll();
}
