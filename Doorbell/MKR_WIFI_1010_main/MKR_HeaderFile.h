/* MKR_HeaderFile.h
DOORBELL
File used to define the functions that will be needed
as the project progesses.
 */

#define WIFI_NAME "Sohail" //Engg4Life
#define WIFI_PASSWORD "251171052221"//ginger123
#define DOORBELL_AUTH_CODE "JfE879N0pHv0y-XdwGikomp5jcWfkiwf"
#define BRACELET_AUTH_CODE "eAM0Uf0tMVNlh0qZR6re0pgirGfdnEev"
#define DOORBELL_PIN 1
#define DOORBELL_PRESSED 1
#define DOORBELL_NOTPRESSED 0
#define DOORBELLTOWRIST V1
#define BUZZER_PIN 5
#define WRISTBANDNOTIFPIN V4

#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h> //BLYNK library



 void connectBluetooth(); // again will probably not need this
 void connectWifi(); //Connects to BLYNK App through Wifi
 boolean doorbellButtonPressed(); //Check if doorbell button is pressed
 void sendPhoneNotif(); //Send the phone notification
 void sendWristBandNotif(); // Send the wristband notification
 void putMKRtoSleep(); //battery life saving techinique, will need to implement for the final product.
 void checkBatteryVoltage();
 void vibrationTest();
 void vibrationOff();
 void turnOffBuzzer();
 
 //DEBUGGING
 void flipflop();
