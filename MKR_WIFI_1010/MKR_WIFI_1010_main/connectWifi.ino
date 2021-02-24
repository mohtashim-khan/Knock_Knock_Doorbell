#include "MKR_HeaderFile.h"

void connectWifi(){
  /*This function will be used to connect the MKR 1010 Arduino with the house wifi
   */
    
    char network_name[] = WIFI_NAME; //Put your wifi network name here
    char network_password[] = WIFI_PASSWORD; //Put your wifi password here
    int connection_status = WL_IDLE_STATUS;  // the Wifi radio's status
    
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    while (!Serial);
    
    // attempt to connect to Wifi network:
    while (status != WL_CONNECTED) {
       
       //Code for feedback on the serial computer monitor, will get rid of this in the final product if needed.
       Serial.print("Attempting to connect to network: ");
       Serial.println(network_name);
       
       // Connect to WPA/WPA2 network:
       connection_status = WiFi.begin(network_name, network_password);
       
       // wait 10 seconds for connection:
       delay(10000);
     }
    
    if (connection_status == WL_CONNECTED){
        Serial.print("Doorbell Module is connected to the wifi");
    }
}
