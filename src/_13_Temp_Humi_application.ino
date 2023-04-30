#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTTYPE DHT11

int pinDht = 2;

int aPinLcdCtrl[3] = {13, 12, 11}; 
int aPinLcdData[8] = {10, 9, 8, 7, 6, 5, 4, 3};

DHT dht(pinDht, DHTTYPE);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  delay(2000);
  float fHumi = dht.readHumidity();
  float fTemp = dht.readTemperature();

  lcd.clear();
  lcd.print("Temp: "); 
  lcd.print(fTemp);
  lcd.print("[C]");
  lcd.setCursor(0,1);
  lcd.print("Humi: "); 
  lcd.print(fHumi);
  lcd.print("[%]");
}
