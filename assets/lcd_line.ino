#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>
#include <Keypad.h>

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

// Keypad setup
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

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

  // Handle keypad input for password
  key = keypad.getKey();
  if (key) {
    if (key == '#') { // Assuming '#' is used to clear the input
      password = "";
    } else if (key == '*') { // Assuming '*' is used to submit the input
      // Do something with the entered password
      Serial.println("Password entered: " + password);
    } else {
      password += key;
    }

    // Display the password (masking it)
    lcd.setCursor(0, 0);
    lcd.print("Enter Password:");
    lcd.setCursor(0, 1);
    for (int i = 0; i < password.length(); i++) {
      lcd.print("*");
    }
    // Clear the rest of the line
    for (int i = password.length(); i < 6; i++) {
      lcd.print(" ");
    }
  }

  delay(2000); // Delay to avoid flooding the LCD updates
}
