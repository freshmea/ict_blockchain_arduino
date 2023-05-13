int pinGnd = A0; 
int pinVcc = A1; 
int pinX= A2;  
int pinY= A3;  
int pinSwitch= A4; 

void setup()
{
  Serial.begin(115200);  
  pinMode(pinGnd, OUTPUT);  
  pinMode(pinVcc, OUTPUT);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(pinSwitch, INPUT_PULLUP);
  digitalWrite(pinGnd, LOW);  
  digitalWrite(pinVcc, HIGH); 
}

void loop()
{
  int x = map(analogRead(pinX), 0, 1023, -5, 5);
  int y = map(analogRead(pinY), 0, 1023, -5, 5);
  Serial.print("X : ");
  Serial.print(x);
  Serial.print(" \tY : ");
  Serial.print(y);
  Serial.print(" \tSW : ");
  if(!digitalRead(pinSwitch))
  {
    Serial.println("ON"); 
  }
  else
  {
    Serial.println("OFF"); 
  }
  delay(500);
}
