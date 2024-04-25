#include <ArduinoBLE.h>
#include "HX711.h" //This library can be obtained here http://librarymanager/All#Avia_HX711
#include <Adafruit_ADS1X15.h>

BLEService myService("fff0");
BLEFloatCharacteristic myCharacteristic("fff1", BLERead | BLEBroadcast); // Changed to BLEFloatCharacteristic
#define LOADCELL_DOUT_PIN  9
#define LOADCELL_SCK_PIN  10

HX711 scale;

float calibration_factor = -7050;
const uint8_t manufactData[4] = {0x01, 0x02, 0x03, 0x04};
const uint8_t serviceData[3] = {0x00, 0x01, 0x02};
float f=0.0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("failed to initialize BLE!");
    while (1);
  }

  myService.addCharacteristic(myCharacteristic);
  BLE.addService(myService);

  // Build scan response data packet
  BLEAdvertisingData scanData;
  // Set parameters for scan response packet
  scanData.setLocalName("NanoBLE");
  // Copy set parameters in the actual scan response packet
  BLE.setScanResponseData(scanData);

  // Build advertising data packet
  BLEAdvertisingData advData;
  // Set parameters for advertising packet
  advData.setManufacturerData(0x004C, manufactData, sizeof(manufactData));
  advData.setAdvertisedService(myService);
  advData.setAdvertisedServiceData(0xfff0, serviceData, sizeof(serviceData));
  // Copy set parameters in the actual advertising packet
  BLE.setAdvertisingData(advData);

  BLE.advertise();
  Serial.println("advertising ...");
}

void loop() {
  BLEDevice cen = BLE.central();
  BLE.poll();
  if(cen){
    while(cen.connected()){
      readValues();
      delay(200);
    }
  }
 }

// Define readValues function
void readValues() {
  float sensorValue = getSensorValue(); // Placeholder for sensor value calculation
  myCharacteristic.writeValue(sensorValue); // Write the float value to the characteristic
}

float getSensorValue() {
  f=round(scale.get_units());
      //Serial.print(scale.get_units(), 1); //scale.get_units() returns a float
      Serial.print("Force:");
      Serial.print(f);
      Serial.print(" lbs"); //change to lbs for weight
      Serial.println();
  return 0.0; // Return the calculated float value from your sensor
}
