int aPinLed[8] = {13, 12, 11, 10, 9, 8, 7, 6};

int pinGnd = 4; 
int pinVcc = 3; 
int pinTilt = 2;

void setup() {
  for(int i=0; i<8; i++)
  {
    pinMode(aPinLed[i], OUTPUT);
  }
  pinMode(pinGnd, OUTPUT);  
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinTilt, INPUT); 
  digitalWrite(pinGnd, LOW);  
  digitalWrite(pinVcc, HIGH); 

}

void loop() {
  int i;
  if(digitalRead(pinTilt))  
  {
    for(i=0; i<8; i++)
    {
      digitalWrite(aPinLed[i], HIGH);   // LED ON
    }
  }
  else
  {
    for(i=0; i<8; i++)
    {
      digitalWrite(aPinLed[i], LOW);    // LED OFF
    }
  }
}
