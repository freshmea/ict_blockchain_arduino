int pinGnd = 4;  
int pinVcc = 3;  
int pinHit = 2;  

int aPinLed[8] = {13, 12, 11, 10, 9, 8, 7, 6};
volatile int i = 0;

void setup() {
  Serial.begin(115200);
  for(i=0; i<8; i++)
  {
    pinMode(aPinLed[i], OUTPUT);
  }
  pinMode(pinGnd, OUTPUT); 
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinHit, INPUT); 
  digitalWrite(pinGnd, LOW);  
  digitalWrite(pinVcc, HIGH); 
  
  attachInterrupt(0, HitISR, RISING);
}

void loop() {
  for(i=0; i<8; i++)
  {
    digitalWrite(aPinLed[i], HIGH);
    delay(1000);
  }
  
  if(i==8)
  {
    for(i=0; i<8; i++)
    {
      digitalWrite(aPinLed[i], LOW);
    }  
    delay(1000);
  }
}

// External ISR function
void HitISR(void)
{
  for(i=0; i<8; i++)
  {
    digitalWrite(aPinLed[i], LOW);
  }
  i = -1;
  delay(1000);
}
