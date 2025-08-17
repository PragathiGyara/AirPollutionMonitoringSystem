int ledPin = 23; // LED pin number
int mq2Pin = 4; // MQ2 sensor pin number

float voltage = 0; // Variable to store voltage reading from MQ2 sensor
float RS_gas = 0; // Variable to store resistance of the sensor
float ratio = 0; // Variable to store ratio of RS_gas to Ro value
float Ro = 10; // Resistance of the sensor in clean air
float CO_Concentration = 0; // Concentration of carbon monoxide in ppm
float NH3_Concentration = 0; // Concentration of ammonia in ppm

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  pinMode(mq2Pin, INPUT); // Set MQ2 sensor pin as input
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  int sensorValue = analogRead(mq2Pin); // Read sensor value
  voltage = sensorValue * (5.0 / 1023.0); // Convert sensor value to voltage
  RS_gas = ((5.0 - voltage) / voltage) * 10.0; // Calculate resistance of the sensor

  ratio = RS_gas / Ro; // Calculate ratio of RS_gas to Ro value

  // Calculate concentration of carbon monoxide in ppm
  CO_Concentration = pow(ratio, -1.179) * 4.385;
  
  // Calculate concentration of ammonia in ppm
  NH3_Concentration = pow(ratio, -1.67) * 1.47;
  
  Serial.print("CO Concentration: ");
  Serial.print(CO_Concentration);
  Serial.print(" ppm, NH3 Concentration: ");
  Serial.print(NH3_Concentration);
  Serial.println(" ppm");

  if (CO_Concentration > 10 || NH3_Concentration > 20) { // If gas is detected
    digitalWrite(ledPin, HIGH); // Turn on LED
    delay(2000); // Wait for 1 second
    digitalWrite(ledPin, LOW); // Turn off LED
    delay(2000); // Wait for 1 second
  }
  else { // If no gas is detected
    digitalWrite(ledPin, LOW); // Turn off LED
    delay(2000); // Wait for 1 second
  }
}

