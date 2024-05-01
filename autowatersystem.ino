/****************************************
* Include Libraries
****************************************/

#include "Ubidots.h"

/****************************************
* Define Instances and Constants
****************************************/

const char* UBIDOTS_TOKEN = "BBUS-zB1tgVRU5bLNFl4B4GTOcL0twL5J4U";
const char* WIFI_SSID = "POCO X3 NFC";  // Put here your Wi-Fi SSID
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
  ubidots.add("humidity", relativeHumidity);  // Change for your variable name


  bool bufferSent = false;
  bufferSent = ubidots.send();  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }
  delay(1000);
}