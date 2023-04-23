int aPinLed[8] = {13, 12, 11, 10, 9, 8, 7, 6};

void setup() {
  for(int i=0; i<8; i++)
  {
    pinMode(aPinLed[i], OUTPUT);
  }
}

void loop() {
  int i;
  for(i=0; i<8; i++)
  {
    digitalWrite(aPinLed[i], HIGH);   // LED ON
  }
  delay(1000);
  
  for(i=0; i<8; i++)
  {
    digitalWrite(aPinLed[i], LOW);    // LED OFF
  }
  delay(1000);
}
