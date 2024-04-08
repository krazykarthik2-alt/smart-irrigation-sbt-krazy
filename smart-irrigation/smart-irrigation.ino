#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define SOIL_MOISTURE_PIN A0 // Analog pin for soil moisture sensor

// Initialize the LCD with the I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);
int motor=7; 

void setup() {
  
  pinMode(motor,OUTPUT);
  digitalWrite(motor,HIGH);
  lcd.init(); // Initialize the LCD
  lcd.backlight();  // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("hello boss");
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("SBT SMART                  ");
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("this is DCME B");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("initializing...");
  delay(3000);
  lcd.setCursor(0, 0);
}

void loop() {
  int moistureLevel = analogRead(SOIL_MOISTURE_PIN); // Read soil moisture level
  int percentage = map(moistureLevel, 0, 1023, 100, 0); // Map moisture level to percentage
  lcd.setCursor(0, 1);
  lcd.print("               "); // Clear previous content
  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(percentage);
  lcd.print("%");

  // Check if the soil moisture is below a threshold value
  if (percentage < 50  ) { // Adjust threshold value according to your requirements
    // Turn on irrigation system
    // Add your irrigation control logic here
    lcd.setCursor(0, 0);
    digitalWrite(motor,LOW);
    lcd.print("Irrigating...");
  } else  {
    // Turn off irrigation system
    // Add your irrigation control logic here
    lcd.setCursor(0, 0);
    lcd.print("Soil Moisture:");
    digitalWrite(motor,HIGH);
  }

  delay(500); // Delay for stability
}
