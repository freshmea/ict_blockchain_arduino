#include <LiquidCrystal.h>


// RS, RW, E
int aPinLcdCtrl[3] = {13, 12, 11}; 
// D0, D1, D2, D3, D4, D5, D6, D7
int aPinLcdData[8] = {10, 9, 8, 7, 6, 5, 4, 3};


// initialize the library with the numbers of the interface pins
// rs, rw, e, d0, d1, d2, d3, d4, d5, d6, d7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
}

void loop() {
  String buffer;
  lcd.cursor();
  if(Serial.available() > 0)
  {
    buffer = Serial.readString(); 
  }

  if(buffer != "")
  {
    lcd.clear();  
    lcd.setCursor(0, 0);
    lcd.print(buffer);
  }
}

