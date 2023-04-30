int pinGnd = 4; 
int pinVcc = 3;
int pinReed = 2;  

void setup() {
  Serial.begin(115200); 

  pinMode(pinGnd, OUTPUT); 
  pinMode(pinVcc, OUTPUT); 
  pinMode(pinReed, INPUT);
  digitalWrite(pinGnd, LOW); 
  digitalWrite(pinVcc, HIGH); 
}

void loop() {
  if(digitalRead(pinReed))  // Reed read
  {
    Serial.println("Mini Reed OFF");  // HIGH
  }
  else
  {
    Serial.println("Mini Reed ON");  // LOW
  }
  delay(500);
}

