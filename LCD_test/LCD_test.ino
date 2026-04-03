#include <LiquidCrystal.h>

// Mapping for NodeMCU: 
// D1=5, D2=4, D5=14, D6=12, D7=13, D8=15
const int rs = 5, en = 4, d4 = 14, d5 = 12, d6 = 13, d7 = 16;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Most 16x2 LCDs need a moment to stabilize power
  delay(500); 
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("NodeMCU Active");
  lcd.setCursor(0, 1);
  lcd.print("Current: 22.9mA");
}

void loop() {
  // Stay empty for now to test the static display
}
