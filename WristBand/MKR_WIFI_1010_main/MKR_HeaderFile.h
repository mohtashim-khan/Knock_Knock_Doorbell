/* MKR_HeaderFile.h
WRISTBAND
File used to define the functions that will be needed
as the project progesses.
 */

#define WIFI_NAME "Sohail"//Engg4Life
#define WIFI_PASSWORD "251171052221"//ginger123
#define DOORBELL_AUTH_CODE "JfE879N0pHv0y-XdwGikomp5jcWfkiwf"
#define BRACELET_AUTH_CODE "eAM0Uf0tMVNlh0qZR6re0pgirGfdnEev"
#define DOORBELL_PIN 1
#define DOORBELL_PRESSED 1
#define DOORBELL_NOTPRESSED 0
#define DOORBELLTOWRIST V1
#define VIBRATION_PIN 5

#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h> //BLYNK library

 void connectWifi(); //Connects to BLYNK App through Wifi
