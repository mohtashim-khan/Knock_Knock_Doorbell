#include "MKR_HeaderFile.h"

//DOORBELL

WidgetBridge bridge1(V1); // Bridge widget on virtual pin 1 to allow connection to WristBand
BlynkTimer batterytimer; // Timer
BlynkTimer vibrationTimer;  //Vibration code
BlynkTimer reconnectionTimer;
int phoneNotifications;
volatile bool pinChanged = false;
volatile bool playBuzzer = false;
volatile int pinValue = 0;
volatile int reCnctFlag;  // Reconnection Flag
volatile int reCnctCount = 0;  // Reconnection counter




void setup() {
  connectWifi();
  setPinMode();
  attachInterrupt(digitalPinToInterrupt(DOORBELL_PIN), checkPin, CHANGE);
  batterytimer.setInterval(5000L, checkBatteryVoltage);
}


void loop() {
  batterytimer.run();
  reconnectionTimer.run();
  if(Blynk.connected())
  {
    Blynk.run(); //BLYNK connection
  }
  else if(reCnctFlag == 0)
  {
    reCnctFlag = 1;  // Set reconnection Flag
    reconnectionTimer.setTimeout(30000L, []() 
    {  // Lambda Reconnection Timer Function
      reCnctFlag = 0;  // Reset reconnection Flag
      reCnctCount++;  // Increment reconnection Counter
      Blynk.connect();  // Try to reconnect to the server
    }); //End timer function
  }
  
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
  bridge1.virtualWrite(WRISTBANDNOTIFPIN,HIGH);
  if(phoneNotifications)
  {
    Blynk.notify("Someone is at the door!");
  }
  
}

void setPinMode()
{
  pinMode(DOORBELL_PIN, INPUT);
}

void checkBatteryVoltage()
{
  int sensorValue = analogRead(ADC_BATTERY);
  float voltage = sensorValue * (4.25 / 1023.0);
  Blynk.virtualWrite(V1,voltage);
  if(voltage<=3.5 &&phoneNotifications == 1)
  {
    Blynk.notify("Recharge doorbell battery!!");
  }

  if(voltage>=4.2 && phoneNotifications == 1)
  {
    Blynk.notify("Fully Charged Doorbell!");
  }
  
}

//vibration motor testing -- REMOVE FROM HERE


//Simulate doorbell code
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  if(pinValue)
  {
    Blynk.notify("Family Alert!");
    bridge1.virtualWrite(WRISTBANDNOTIFPIN,HIGH);
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
