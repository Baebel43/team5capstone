#include <ArduinoBLE.h>
#include "HX711.h" //This library can be obtained here http://librarymanager/All#Avia_HX711
#define LOADCELL_DOUT_PIN  9
#define LOADCELL_SCK_PIN  10
float calibration_factor = -7050;
float f=0.0;
HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare();	//Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
}

void loop() {
  scale.set_scale(calibration_factor);
  f=round(scale.get_units());
  //Serial.print(scale.get_units(), 1); //scale.get_units() returns a float
  Serial.print("Force:");
  Serial.print(f);
  Serial.print(" lbs"); //change to lbs for weight
  Serial.println();

}
