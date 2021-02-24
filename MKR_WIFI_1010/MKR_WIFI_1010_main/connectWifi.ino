#include "MKR_HeaderFile.h"

void connectWifi(){
  /*This function will be used to connect the MKR 1010 Arduino with the house wifi
   */
    
    char network_name[] = "wifi name"; //Put your wifi network name here
    char network_password[] = "password"; //Put your wifi password here
    int connection_status = WL_IDLE_STATUS;
    
    Serial.begin(9600);
    while (!Serial);
    
    while (status != WL_CONNECTED) {
      
       connection_status = WiFi.begin(network_name, network_password);

       delay(10000);
     }
    
    if (connection_status == WL_CONNECTED){
        Serial.print("Arduino is connected to the wifi");
    }
}