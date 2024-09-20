#include <LiquidCrystal.h>

// Define LCD pin connections
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define sensor and relay pins
int sensorPin = A0;    // Analog pin for soil moisture sensor
int relayPin = 8;      // Digital pin for relay module
int sensorValue = 0;   // Variable to store sensor value
int threshold = 400;   // Moisture threshold (adjust as needed)

void setup() {
  // Start the LCD and set its dimensions (16x2)
  lcd.begin(16, 2);
  lcd.print("Irrigation Sys");

  // Set relay pin as output
  pinMode(relayPin, OUTPUT);
  
  // Ensure pump is off initially
  digitalWrite(relayPin, HIGH);

  // Wait for LCD to display the initial message
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read the soil moisture sensor value
  sensorValue = analogRead(sensorPin);
  
  // Print the sensor value on LCD
  lcd.setCursor(0, 0);
  lcd.print("Moisture Level:");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);

  // If soil is dry (sensor value below threshold)
  if (sensorValue < threshold) {
    // Turn on the pump
    digitalWrite(relayPin, LOW);
    lcd.setCursor(12, 1);
    lcd.print("Pump ON ");
  }
  else {
    // Turn off the pump
    digitalWrite(relayPin, HIGH);
    lcd.setCursor(12, 1);
    lcd.print("Pump OFF");
  }

  // Wait 1 second before taking the next reading
  delay(1000);
}
