#define FAN_PIN 9  // PWM pin connected to the fan control wire
#define PWM_MAX 255  // Maximum PWM value (255 for 8-bit PWM)

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  
  // Initialize PWM pin for fan control
  pinMode(FAN_PIN, OUTPUT);

// Set Timer/Counter2 to Fast PWM mode with non-inverted output
  TCCR2A = (1 << WGM21) | (1 << WGM20) | (1 << COM2A1);
  
  // Set prescaler to 64
  TCCR2B = (1 << CS22);
 
}


void loop() {
 
int w = Serial.parseInt();
if (w>0) {
analogWrite(FAN_PIN, w);
Serial.println(w);
}
 
  delay(1000); // 5 seconds
}
