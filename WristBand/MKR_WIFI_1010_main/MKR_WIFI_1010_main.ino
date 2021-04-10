#include "MKR_HeaderFile.h"

//WRISTBAND
BlynkTimer batterytimer; // Timer
BlynkTimer vibrationTimer;  //Vibration Timer
//Vibration test
int vibrationStrength;
int sendVibration;
int threeSecondsElapsed;
int endTime;
int startTime;
//

void setup() {
  connectWifi();
  //batterytimer.setInterval(5000L, checkBatteryVoltage);
  Serial.begin(9600);
}


void loop() 
{
  Blynk.run(); //BLYNK connection
  batterytimer.run();
  if((millis() - startTime)>= 3000)
  {
    vibrationOff();
  }
  
  
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
//Receive user Defined Vibration Strength
BLYNK_WRITE(V3)
{
  vibrationStrength = param.asInt();
  vibrationStrength = vibrationStrength/100*255;
}

//Process Notification from Doorbell Module
BLYNK_WRITE(V4)
{
  sendVibration = param.asInt();
  if(sendVibration)
  {
    vibrationTest();
    Blynk.virtualWrite(V4,LOW);
  }
}
void vibrationTest()
{
  analogWrite(VIBRATION_PIN,vibrationStrength);
  startTime = millis();
}

void vibrationOff()
{
  analogWrite(VIBRATION_PIN,0);
}


//



BLYNK_CONNECTED() {
    Blynk.syncAll();
}
