#include "MKR_HeaderFile.h"

void connectWifi(){
  /*This function will be used to connect the MKR 1010 Arduino with the house wifi and BLYNK
   */
    
    char network_name[] = WIFI_NAME; //Put your wifi network name here
    char network_password[] = WIFI_PASSWORD; //Put your wifi password here
    char auth[] = DOORBELL_AUTH_CODE;
    
    Blynk.begin(auth, network_name, network_password); // connect to BLYNK cloud
    
    
    }
