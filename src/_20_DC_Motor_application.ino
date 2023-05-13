
// DC motor
int pinPos = 13;
int pinNeg= 12;
int pinEn = 11;

// LED
int pinLed = 10;
int pinLedGnd = 9;

// Buzzer
int pinBuzzer = 3;
int pinBuzzerGnd = 5; 

// Joystick
int pinGnd = A0; // ground pin
int pinVcc = A1; // POWER pin
int pinX= A2;  // joystick X pin
int pinY= A3;  // joystick Y pin
int pinSwitch= A4; // Switch pin

void setup()
{
  Serial.begin(115200);
  pinMode(pinPos, OUTPUT);    
  pinMode(pinNeg, OUTPUT);    
  pinMode(pinLed, OUTPUT);
  pinMode(pinLedGnd, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinBuzzerGnd, OUTPUT);

  pinMode(pinGnd, OUTPUT);  
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinSwitch, INPUT_PULLUP);
  digitalWrite(pinGnd, LOW);  
  digitalWrite(pinVcc, HIGH); 
  
}

void loop() 
{
  int x = map(analogRead(pinX), 0, 1023, 0, 100);
  int y = map(analogRead(pinY), 0, 1023, 0, 100);
  Serial.print("x:");
  Serial.print(x);
  Serial.print("\ty:");
  Serial.println(y);
  if(x ==99)
  {
    ClockWise(50);
  }
  else if(x == 0)
  {
    CounterClockWise(50);
  }
  else if(y == 99)
  {
    digitalWrite(pinLed, HIGH);
  }
  else if(y == 0)
  {
    digitalWrite(pinLed, LOW);
  }
  else
  {
    MotorStop();     
  }
  
  if(!digitalRead(pinSwitch))
  {
    tone(pinBuzzer, 196);
    delay(100);
    noTone(pinBuzzer);
  }
  delay(500);
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
  digitalWrite(pinNeg, LOW); 
  digitalWrite(pinPos, LOW);   
}
