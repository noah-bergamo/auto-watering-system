/****************************************
* Include Libraries
****************************************/

#include "Ubidots.h"

/****************************************
* Define Instances and Constants
****************************************/

const char* UBIDOTS_TOKEN = "BBUS-zB1tgVRU5bLNFl4B4GTOcL0twL5J4U";
const char* WIFI_SSID = "POCO X3 NFC";  
const char* WIFI_PASS = "12345678";

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);


void setup() {
  Serial.begin(115200);
  pinMode(14, INPUT);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
}

void loop() {

  float sensorData = analogRead(0);

  uint relativeHumidity = 100.0-(sensorData/1024.0 ) * 100.0;
  ubidots.add("humidity", relativeHumidity);


  bool bufferSent = false;
  bufferSent = ubidots.send(); 

  if (bufferSent) {

    Serial.println("Values sent by the device");
  }
  delay(1000);
}
