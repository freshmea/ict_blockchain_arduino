#include <DHT.h>
#define DHTTYPE DHT11

int pinGnd = 4;
int pinVcc = 3;
int pinDht = 2;

DHT dht(pinDht, DHTTYPE);

void setup() {
  Serial.begin(115200); 
  pinMode(pinVcc, OUTPUT);
  pinMode(pinGnd, OUTPUT);
  digitalWrite(pinVcc, HIGH);
  digitalWrite(pinGnd, LOW);
  
  dht.begin();
}

void loop() {
  delay(1000);
  float fTemp = dht.readTemperature();
  float fHumi = dht.readHumidity();
  
  if (isnan(fTemp) || isnan(fHumi)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Temperature: "); 
  Serial.print(fTemp);
  Serial.print("[C]\t ");
  Serial.print("Humidity: "); 
  Serial.print(fHumi);
  Serial.println("[%]");
}
