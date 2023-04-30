#include <LiquidCrystal.h>

// rs, rw, e, d0, d1, d2, d3, d4, d5, d6, d7
LiquidCrystal lcd(13,12,11,10,9,8,7,6,5,4,3);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello!!");
  lcd.setCursor(0, 1);
  lcd.print("EdgeILAB");
}

void loop() {
}


