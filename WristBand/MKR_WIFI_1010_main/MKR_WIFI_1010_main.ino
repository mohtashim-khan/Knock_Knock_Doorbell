#include "MKR_HeaderFile.h"

//WRISTBAND
BlynkTimer batterytimer; // Timer
//Vibration test
int vibrationStrength;
//

void setup() {
  connectWifi();
  batterytimer.setInterval(5000L, checkBatteryVoltage);
}


void loop() 
{
  Blynk.run(); //BLYNK connection
  batterytimer.run();
}

//BATTERY STATUS
void checkBatteryVoltage()
{
  int sensorValue = analogRead(ADC_BATTERY);
  float voltage = sensorValue * (4.3 / 1023.0);
  Blynk.virtualWrite(V1,voltage);
  if(voltage<=3.5)
  {
    Blynk.notify("Recharge WristBand battery!!");
  }

  if(voltage>=4.25)
  {
    Blynk.notify("Fully Charged Armband!");
  }
  
}

//Process notificatoin from other board


BLYNK_WRITE(V5){
  int vibrationStrength = param.asInt();
  
  
  
}

BLYNK_CONNECTED() {
    Blynk.syncAll();
}
