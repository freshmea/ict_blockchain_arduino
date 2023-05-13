int pinPos = 5;
int pinNeg = 4;
int pinEn = 3;

void setup()
{
  pinMode(pinPos, OUTPUT);    
  pinMode(pinNeg, OUTPUT);   
  pinMode(pinEn, OUTPUT);   
}

void loop() 
{
  ClockWise(50);
  delay(3000);
  
  MotorStop();
  delay(2000);
  
  CounterClockWise(100);
  delay(3000);
  
  MotorStop();
  delay(2000);
}

void ClockWise(int Speed)
{
  digitalWrite(pinPos, HIGH); 
  digitalWrite(pinNeg, LOW);  
  analogWrite(pinEn, Speed); 
}

void CounterClockWise(int Speed)
{
  digitalWrite(pinPos, LOW);   
  digitalWrite(pinNeg, HIGH);  
  analogWrite(pinEn, Speed);   
}

void MotorStop()
{
  digitalWrite(pinPos, LOW);  
  digitalWrite(pinNeg, LOW);   
}
