#include "Beetle_BLE_Header.h"

void connectBluetooth()
{
  char auth[] = "eAM0Uf0tMVNlh0qZR6re0pgirGfdnEev";
  
  DebugSerial.begin(9600);

  DebugSerial.println("Waiting for connections...");

  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(115200);
  Blynk.begin(Serial, auth);
  
}
