/* MKR_HeaderFile.h

File used to define the functions that will be needed
as the project progesses.
 */

#define WIFI_NAME "Sohail"
#define WIFI_PASSWORD "251171052221"
#define MKR_WIFI_AUTH_CODE "JfE879N0pHv0y-XdwGikomp5jcWfkiwf"

#include <WiFiNINA.h>
#include <ArduinoBLE.h> //will probably not need this
#include <BlynkSimpleWiFiNINA.h> //BLYNK library



 void connectBluetooth(); // again will probably not need this
 void connectWifi(); //Connects to BLYNK App through Wifi
 void doorbellButtonPressed(); //Check if doorbell button is pressed
 void sendPhoneNotif(); //Send the phone notification
 void sendWristBandNotif(); // Send the wristband notification
 void putMKRtoSleep(); //battery life saving techinique, will need to implement for the final product.
