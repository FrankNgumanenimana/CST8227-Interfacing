// These constants won't change:
const int sensorPin = A1;    // pin that the sensor is attached to
const int ledPin = 19;        // pin that the LED is attached to
const int buzzerPin = 21;
// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023; // minimum sensor value
int sensorMax = 0;          // maximum sensor value


void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = touchRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // signal the end of the calibration period
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // read the sensor:
  sensorValue = touchRead(sensorPin);
  Serial.println(sensorValue);
  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);
//
//  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue);
  tone(buzzerPin, sensorValue); 
  
}
