int pinGnd = A2; 
int pinVcc = A1;  
int pinCds = A0;  
int ledPin = 10;
void setup() {
  Serial.begin(115200);  

  pinMode(pinGnd, OUTPUT);  
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinCds, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pinGnd, LOW); 
  digitalWrite(pinVcc, HIGH);
}

void loop() {
  int adcData = analogRead(pinCds);
  analogWrite(ledPin, (adcData < 612) ? adcData-150 : 511);
  Serial.print("CDS : ");
  Serial.println(adcData);
  //delay(500);
}

