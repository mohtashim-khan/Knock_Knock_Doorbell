/* MKR_HeaderFile.h
WRISTBAND
File used to define the functions that will be needed
as the project progesses.
 */

#define WIFI_NAME "Engg4Life"
#define WIFI_PASSWORD "ginger123"
#define DOORBELL_AUTH_CODE "JfE879N0pHv0y-XdwGikomp5jcWfkiwf"
#define BRACELET_AUTH_CODE "eAM0Uf0tMVNlh0qZR6re0pgirGfdnEev"
#define DOORBELL_PIN 1
#define DOORBELL_PRESSED 1
#define DOORBELL_NOTPRESSED 0
#define DOORBELLTOWRIST V1

#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h> //BLYNK library

 void connectWifi(); //Connects to BLYNK App through Wifi
