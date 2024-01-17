#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setupDisplay() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello world");
}

void setup() {
  setupDisplay();
}

void loop() {}
