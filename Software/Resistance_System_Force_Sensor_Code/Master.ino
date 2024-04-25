#include <ArduinoBLE.h>

struct DeviceInfo {
  String address;
  String uuid;
};

// Define an array of devices you want to interact with
DeviceInfo devices[] = {
  {"84:cc:a8:77:9f:1a", "3672"} // NANO 33 IOT for
};
int currentDeviceIndex = 0; // Index of the current device being processed

void setup() {
  Serial.begin(9600);
  while (!Serial);


  if (!BLE.begin()) {
    Serial.println("Failed");
    while (1);
  }    
  BLE.setLocalName("Master");
  Serial.println("Bluetooth Low Energy Central scan");
  BLE.scanForAddress("84:cc:a8:77:9f:1a"); // Start scanning without specifying an address
}

void loop() {
  // Check if we've gone through all devices
  if (currentDeviceIndex >= (sizeof(devices) / sizeof(devices[0]))) {
    Serial.println("Processed all devices. Restarting...");
    currentDeviceIndex = 0; // Optionally restart or halt the program
    //return; // Uncomment to stop after processing all devices
  }

  BLEDevice peripheral = BLE.available();

  if (peripheral) {
    // Get the current target device info
    DeviceInfo& targetDevice = devices[currentDeviceIndex];

    // Check if the found peripheral matches the target address
    if(peripheral.address() == targetDevice.address) {
      Serial.println("Discovered a peripheral");
      Serial.println("-----------------------");
      Serial.print("Address: ");
      Serial.println(peripheral.address());

      Serial.print("Local Name: ");
      Serial.println(peripheral.localName());

      Serial.print("UUID: ");
      Serial.print(peripheral.advertisedServiceUuid());
      Serial.println();

      BLE.stopScan();

      // Assuming explorerPeripheral function is adapted to use DeviceInfo
      explorerPeripheral(peripheral, targetDevice.uuid);

      // Move to the next device
      currentDeviceIndex++;
      BLE.scan(); // Restart scanning for the next device
    }
  }
}

void explorerPeripheral(BLEDevice peripheral, String uuic) {
  // connect to the peripheral
  Serial.println("Connecting ...");

  if (peripheral.connect()) {
    Serial.println("Connected");
  } else {
    Serial.println("Failed to connect!");
    return;
  }

  // discover peripheral attributes
  Serial.println("Discovering attributes ...");
  if (peripheral.discoverAttributes()) {
    Serial.println("Attributes discovered");
  } else {
    Serial.println("Attribute discovery failed!");
    peripheral.disconnect();
    return;
  }

  // loop the services of the peripheral and explore each
  for (int i = 0; i < peripheral.serviceCount(); i++) {
    BLEService service = peripheral.service(i);
    exploreService(service);
  }

  Serial.println();
}

void exploreService(BLEService service) {
  // Filter for services with UUIDs 180D and 180C
  const char* serviceUUID = service.uuid();
  if(strcmp(serviceUUID, "3672") == 0){
    Serial.print("Service ");
    Serial.println(serviceUUID);

    // Loop the characteristics of the service and explore each
    for (int i = 0; i < service.characteristicCount(); i++) {
      BLECharacteristic characteristic = service.characteristic(i);
      // Filter for characteristic with UUID 2A57
      if(strcmp(characteristic.uuid(), "4783") == 0){
        exploreCharacteristic(characteristic);
      }
    }
  }
}

void exploreCharacteristic(BLECharacteristic characteristic) {
  // Print the UUID and properties of the characteristic
  Serial.print("\tCharacteristic ");
  Serial.print(characteristic.uuid());

  // Check if the characteristic is readable
  if (characteristic.canRead()) {
    while(true) { // Continuously read the characteristic value
      // Read the characteristic value
      characteristic.read();

      if (characteristic.valueLength() > 0) {
        // Print out the value of the characteristic
        Serial.print(" value 0x");
        printData(characteristic.value(), characteristic.valueLength());
        Serial.println();
      }
      delay(200); // Add delay to prevent flooding
    }
  }
  Serial.println();
}

void printData(const unsigned char data[], int length) {
  for (int i = 0; i < length; i++) {
    unsigned char b = data[i];

    if (b < 16) {
      Serial.print("0");
    }

    Serial.print(b, HEX);

  }
}