#include "MKR_HeaderFile.h"

WidgetBridge bridge1(V1); // Bridge widget on virtual pin 1 to allow connection to WristBand
BlynkTimer timer; // Timer
volatile bool pinChanged = false;
volatile int pinValue = 0;

void setup() {
  connectWifi();
  setPinMode();
  attachInterrupt(digitalPinToInterrupt(DOORBELL_PIN), checkPin, RISING);
}


void loop() {
  Blynk.run(); //BLYNK connection
  
  if (pinChanged) 
  {
    // Process the value inside loop since interrupts cant send messages through wifi
    if (pinValue) 
    {
      sendNotifications();
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
  pinValue = !digitalRead(DOORBELL_PIN);
  pinChanged = true;
}

void sendNotifications()
{
  bridge1.digitalWrite(LED_BUILTIN, HIGH); // Wristband notif
  Blynk.notify("Someone is at the door!");
}

void setPinMode()
{
  pinMode(DOORBELL_PIN, INPUT_PULLUP);
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
