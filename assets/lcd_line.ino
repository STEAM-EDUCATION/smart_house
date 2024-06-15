#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>

// Initialize the LCD with the I2C address (usually 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the DHT11 sensor pin
#define DHT11_PIN 2
DHT11 dht11;

// Variables for storing password input
String password = "";
char key;

// Variables for storing temperature and humidity
int humidity;
int temperature;

void setup() {
  // Start the LCD
  lcd.init();
  lcd.backlight();
  
  // Start serial communication (optional, for debugging)
  Serial.begin(9600);

  // Initial LCD display
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
  lcd.print("Temp: --C Hum: --%");
}

void loop() {
  // Read temperature and humidity from DHT11 sensor
  int chk = dht11.read(DHT11_PIN);
  humidity = dht11.humidity;
  temperature = dht11.temperature;
  
  // Update the temperature and humidity display
  lcd.setCursor(6, 1);
  if (chk == DHTLIB_OK) {
    lcd.print(temperature);
    lcd.print("C");
    lcd.setCursor(13, 1);
    lcd.print(humidity);
    lcd.print("%");
  } else {
    lcd.print("--C");
    lcd.setCursor(13, 1);
    lcd.print("--%");
  }

  // Simulate password input (replace with actual input mechanism)
  if (Serial.available() > 0) {
    key = Serial.read();
    if (key == '\n') {
      // Clear the input if Enter is pressed
      password = "";
    } else {
      // Append the input character to the password string
      password += key;
    }
    // Display the password (masking it)
    lcd.setCursor(0, 0);
    lcd.print("Enter Password:");
    lcd.setCursor(0, 1);
    for (int i = 0; i < password.length(); i++) {
      lcd.print("*");
    }
  }

  delay(2000); // Delay to avoid flooding the LCD updates
}
