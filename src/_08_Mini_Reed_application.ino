int aPinLed[8] = {13, 12, 11, 10, 9, 8, 7, 6};

int pinGnd = 4;  
int pinVcc = 3;  
int pinReed = 2;  

void setup() {
  Serial.begin(115200);  
  for(int i=0; i<8; i++)
  {
    pinMode(aPinLed[i], OUTPUT);
  }

  pinMode(pinGnd, OUTPUT); 
  pinMode(pinVcc, OUTPUT);
  pinMode(pinReed, INPUT);
  digitalWrite(pinGnd, LOW);  
  digitalWrite(pinVcc, HIGH); 
}

void loop() {
  int i;
  if(digitalRead(pinReed))  
  {
    for(i=0; i<8; i++)
    {
      digitalWrite(aPinLed[i], LOW);    // LED OFF
    }
    Serial.println("LED OFF");
  }
  else
  {
    for(i=0; i<8; i++)
    {
      digitalWrite(aPinLed[i], HIGH);   // LED ON
    }
    Serial.println("LED ON");    
  }
  delay(500);
}

