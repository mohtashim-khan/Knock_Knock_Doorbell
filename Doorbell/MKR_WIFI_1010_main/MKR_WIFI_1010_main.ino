#include "MKR_HeaderFile.h"

//DOORBELL

WidgetBridge bridge1(V1); // Bridge widget on virtual pin 1 to allow connection to WristBand
BlynkTimer timer; // Timer
volatile bool pinChanged = false;
volatile int pinValue = 0;

void setup() {
  connectWifi();
  setPinMode();
  attachInterrupt(digitalPinToInterrupt(DOORBELL_PIN), checkPin, CHANGE);
  timer.setInterval(2000L, checkBatteryVoltage);
//  Serial.begin(9600);
}


void loop() {
  Blynk.run(); //BLYNK connection
  timer.run();
//  Serial.println(digitalRead(DOORBELL_PIN));
  
  if (pinChanged) 
  {
    // Process the value inside loop since interrupts cant send messages through wifi
    if (pinValue) 
    {
      sendNotifications();
  //    Serial.print("sendNotifications()");
    } 
    else 
    {
      bridge1.digitalWrite(LED_BUILTIN, LOW); //MVP code, most likely wont have anything here for the final.
    }
    pinChanged = false;
  }
  
  
  

}
  
void checkPin()
{
  // Invert value, since button is "Active LOW"
  pinValue = digitalRead(DOORBELL_PIN);
  pinChanged = true;
  //Serial.print("inside Interrupt");
}

void sendNotifications()
{
  bridge1.digitalWrite(LED_BUILTIN, HIGH); // Wristband notif

  //Vibration motor logic 

  
  Blynk.notify("Someone is at the door!");
}

void setPinMode()
{
  pinMode(DOORBELL_PIN, INPUT);
}

void checkBatteryVoltage()
{
  int sensorValue = analogRead(ADC_BATTERY);
  float voltage = sensorValue * (4.3 / 1023.0);
  Blynk.virtualWrite(V1,voltage);
  if(voltage<3.3)
  {
    Blynk.notify("Recharge doorbell battery!!");
  }
  
}


//Simulate doorbell code
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  if(pinValue)
  {
    Blynk.notify("Simulated Doorbell!");
  }
}

BLYNK_CONNECTED() {
    Blynk.syncAll();
    bridge1.setAuthToken(BRACELET_AUTH_CODE); // AuthToken For bracelet
}
