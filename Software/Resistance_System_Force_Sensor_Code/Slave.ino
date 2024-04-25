#include "Arduino.h"
#include <ArduinoBLE.h>
#include "HX711.h" //This library can be obtained here http://librarymanager/All#Avia_HX711
#define LOADCELL_DOUT_PIN  9
#define LOADCELL_SCK_PIN  10
float calibration_factor = -7050;
float f=0.0;
HX711 scale;

#define RX_PIN 27                                        // Rx pin which the MHZ19 Tx pin is attached to
#define TX_PIN 28                                          // Tx pin which the MHZ19 Rx pin is attached to
#define BAUDRATE 9600

int Data;

BLEService customService("3672");
// Assuming you want a characteristic that can hold up to 4 bytes (e.g., a float)
BLECharacteristic Pedal("4783", BLERead | BLENotify, 4, true);

void readValues();

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare();	//Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
  // Initialize the MIKROE 3700 sensor
  while(!Serial);
  if(!BLE.begin()){
    Serial.println("BLE Failed to Initiate");
    delay(500);
    while(1);
  }

    BLE.setLocalName("Left Pedal");
    
    // Setting BLE Service Advertisment
    BLE.setAdvertisedService(customService);
    
    // Adding characteristics to BLE Service Advertisment
    customService.addCharacteristic(Pedal);

    // Adding the service to the BLE stack
    BLE.addService(customService);

    // Start advertising
    BLE.advertise();

}

void loop() {
  BLEDevice central = BLE.central();
  if(central){
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    while(central.connected()){
      delay(200);
      readValues();

      Pedal.writeValue((uint32_t)Data);

    }
  }
}

void readValues(){
  scale.set_scale(calibration_factor);
  f=round(scale.get_units());
  //Serial.print(scale.get_units(), 1); //scale.get_units() returns a float
  Serial.print("Force:");
  Serial.print(f);
  Serial.print(" lbs"); //change to lbs for weight
  Serial.println();
  Data = int(f);

}