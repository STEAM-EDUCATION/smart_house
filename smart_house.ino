#include <DHT11.h>

// Constants for the LED pins
const int redLEDPin = 13;
const int blueLEDPin = 12;
const int greenLEDPin = 11;

// Constants for the sensor pins
const int irSensorPin = 3;
const int dhtPin = 2;
const int ldrPin = A0;

// Temperature threshold (change as needed)
const float temperatureThreshold = 30.0;

// Initialize the DHT11 sensor
DHT11 dht11(dhtPin);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize LED pins as outputs
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);

  // Initialize sensor pins
  pinMode(irSensorPin, INPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  // Check IR sensor for motion
  if (digitalRead(irSensorPin) == LOW) {
    digitalWrite(redLEDPin, HIGH); // Turn on Red LED if motion detected
  } else {
    digitalWrite(redLEDPin, LOW);  // Turn off Red LED if no motion
  }

  // Read temperature from DHT11 sensor
  float temperature = dht11.readTemperature();
  if (temperature != -1) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    // Check if temperature is above threshold
    if (temperature >= temperatureThreshold) {
      digitalWrite(blueLEDPin, HIGH); // Turn on Blue LED if temperature is high
    } else {
      digitalWrite(blueLEDPin, LOW);  // Turn off Blue LED if temperature is normal
    }
  } else {
    Serial.println("Error reading temperature");
  }

  // Read LDR value
  int ldrStatus = analogRead(ldrPin);
  Serial.println(ldrStatus);

  // Check if it's dark based on LDR value
  if (ldrStatus <= 80) {
    digitalWrite(greenLEDPin, HIGH); // Turn on Green LED if it's dark
  } else {
    digitalWrite(greenLEDPin, LOW);  // Turn off Green LED if it's not dark
  }

  // Wait for a short period before the next loop
  delay(500);
}
