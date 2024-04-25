#include <Wire.h>
#define SLAVE_ADDRESS 0x08
#define FAN_PIN 9  // PWM pin connected to the fan control wire
#define PWM_MAX 255  // Maximum PWM value (255 for 8-bit PWM)
int w = 0;
byte data_received = 0;
void setup() 
{
  Serial.begin(9600); //Initialize the Serial Monitor

  pinMode(FAN_PIN, OUTPUT); // Initialize PWM pin for fan control

// Set PWM frequency for Pin 9 (25 Khz)

// Set Timer/Counter2 to Fast PWM mode with non-inverted output
  TCCR2A = (1 << WGM21) | (1 << WGM20) | (1 << COM2A1);
  
  // Set prescaler to 64
  TCCR2B = (1 << CS22);

  Wire.begin(SLAVE_ADDRESS); //Setup For I2C Wiring with Rpi
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  
}
void loop() { 

int w = data_received; // Initialize variable for received Rpi data

Serial.println("Current Speed (MPH): "); //Prints out speed read from bike
Serial.println(w);
w = w * 12.3732523; // PWM to RPM Conversion Value
Serial.println("PWM Duty Cycle Value: "); //Prints converted PWM duty cycle value
Serial.println(w);
delay(300);


}

void receiveData(int bytecount) // Function for receiving I2C data from Rpi
{
  for (int i = 0; i < bytecount; i++) {
    data_received = Wire.read(); // Setting the variable to hold the data read from wire
       
  }
  int w = data_received;
   w = w * 12.3732523; // Value Calculated to scale speed values to appropriate PWM values
   if (255>=w>0) { // Loop for when PWM value is within appropriate limits

  analogWrite(FAN_PIN, w); // Writes the PWM duty cycle value to the pin to drive the fan 
  delay(20);
}
}
void sendData()
{
  Wire.write(data_received); // Sends received value back to Rpi
}
