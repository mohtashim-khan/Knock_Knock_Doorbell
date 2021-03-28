#include "MKR_HeaderFile.h"

//DOORBELL

WidgetBridge bridge1(V1); // Bridge widget on virtual pin 1 to allow connection to WristBand
BlynkTimer timer; // Timer
BlynkTimer vibrationTimer;  //Vibration code
BlynkTimer buzzerTimer;
int phoneNotifications;
volatile bool pinChanged = false;
volatile bool playBuzzer = false;
volatile int pinValue = 0;

//Vibration test
int vibrationStrength;
//


void setup() {
  connectWifi();
  setPinMode();
  attachInterrupt(digitalPinToInterrupt(DOORBELL_PIN), checkPin, CHANGE);
  timer.setInterval(5000L, checkBatteryVoltage);
}


void loop() {
  Blynk.run(); //BLYNK connection
  timer.run();
  
  if (pinChanged) 
  {
    // Process the value inside loop since interrupts cant send messages through wifi
    if (pinValue) 
    {
      sendNotifications();
      tone(BUZZER_PIN,2000,500);
  
    } 
    else 
    {
      bridge1.digitalWrite(LED_BUILTIN, LOW); //MVP code, most likely wont have anything here for the final.
    }
    pinChanged = false;
  }

  
  
  

}

void turnOffBuzzer()
{
  noTone(BUZZER_PIN);
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
  if(phoneNotifications)
  {
    Blynk.notify("Someone is at the door!");
  }
  //Vibration motor logic TESTING - REMOVE CODE
  //vibrationTest();
  //
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
  if(voltage<=3.5)
  {
    Blynk.notify("Recharge doorbell battery!!");
  }
  
}

//vibration motor testing -- REMOVE FROM HERE
BLYNK_WRITE(V3)
{
  vibrationStrength = param.asInt();
  vibrationStrength = vibrationStrength/100*255;
}

void vibrationTest()
{
  digitalWrite(2,HIGH);
  Serial.print("INSIDE VIBRATION TEST");
  delay(2000);
  vibrationOff();
}

void vibrationOff()
{
  digitalWrite(2,LOW);
  Serial.print("INSIDE VIBRATIONOFF");
}


//

//Simulate doorbell code
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  if(pinValue)
  {
    Blynk.notify("Simulated Doorbell!");
    //vibrationTest();
  }
}

BLYNK_WRITE(V2)
{
  phoneNotifications = param.asInt();
}

BLYNK_CONNECTED() {
    Blynk.syncAll();
    bridge1.setAuthToken(BRACELET_AUTH_CODE); // AuthToken For bracelet
}
