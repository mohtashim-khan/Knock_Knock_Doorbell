/* MKR_HeaderFile.h

File used to define the functions that will be needed
as the project progesses.
 */

#define WIFI_NAME "Wifi Name"
#define WIFI_PASSWORD "Wifi Password"

#include <WiFiNINA.h>
#include <ArduinoBLE.h>



 void connectBluetooth();
 void connectWifi();
 void doorbellButtonPressed();
 void sendPhoneNotif();
 void sendWristBandNotif();
