int aPinLed[8] = {13, 12, 11, 10, 9, 8, 7, 6};

int pinGnd = A2; 
int pinVcc = A1;  
int pinCds = A0;  

void setup() {
  Serial.begin(115200);  
  for(int i=0; i<8; i++)
  {
    pinMode(aPinLed[i], OUTPUT);
  }
  pinMode(pinGnd, OUTPUT);  
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinCds, INPUT); 
  digitalWrite(pinGnd, LOW); 
  digitalWrite(pinVcc, HIGH);
}

void loop() {
  int i;
  int adcData = analogRead(pinCds);
  if(adcData > 500)  
  {
    for(i=0; i<8; i++)
    {
      digitalWrite(aPinLed[i], HIGH);   // LED ON
    }
    Serial.println("LED ON");
  }
  else
  {
    for(i=0; i<8; i++)
    {
      digitalWrite(aPinLed[i], LOW);    // LED OFF      
    }
    Serial.println("LED OFF");    
  }
  delay(500);
}
