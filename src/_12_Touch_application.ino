#include <LiquidCrystal.h>

int pinGnd = A1;  
int pinVcc = A2; 
int pinTouchA = A0; 
int pinTouchD = A3;  
int pinLed = 2;

long timer1 = 0, timer2 = 0;
int touchFlag = 1;


// LCD control pin
// RS, RW, E
int aPinLcdCtrl[3] = {13, 12, 11}; 
// D0, D1, D2, D3, D4, D5, D6, D7
int aPinLcdData[8] = {10, 9, 8, 7, 6, 5, 4, 3};

LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);

void setup() {
  pinMode(pinGnd, OUTPUT); 
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinTouchD, INPUT); 
  digitalWrite(pinGnd, LOW); 
  digitalWrite(pinVcc, HIGH);
  
  pinMode(pinLed, OUTPUT);
  
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Touch check
  lcd.setCursor(0, 0);
  if(digitalRead(pinTouchD))
  {
    timer1 = millis();
    // 16.6ms High read
    if((timer1 - timer2) < 18)
    {
      if(touchFlag == 0)
      {
        digitalWrite(pinLed, HIGH);
        lcd.clear();
        lcd.print("LCD ON");
        touchFlag = 1;
      }
    }
    timer2 = timer1;
  }
  else
  {
    // always Low
    if((millis() - timer1) > 18)
    {
      if(touchFlag)
      {
        digitalWrite(pinLed, LOW);
        lcd.clear();        
        lcd.print("LCD OFF");
        touchFlag = 0;
      }
    }
  }
}
