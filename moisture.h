#define sensorPin A0

//  This function returns the analog data to calling function
int readMoistureSensor() {
  int sensorValue = analogRead(sensorPin);  // Read the analog value from sensor
  int outputValue = map(sensorValue, 0, 1023, 255, 0); // map the 10-bit data to 8-bit data
  int moisturePercent = map(outputValue, 0, 255, 0, 100);
  return moisturePercent;             // Return analog moisture value
}

