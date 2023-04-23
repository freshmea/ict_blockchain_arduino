int aPinSwitch[8] = {13,12,11,10,9,8,7,6}; 

void setup() { 
  Serial.begin(115200); 
  for(int i=0; i<8; i++)
  {
    pinMode(aPinSwitch[i], INPUT);
  }
}

void loop() {
  for(int i=0; i<8; i++)
  {
    if(digitalRead(aPinSwitch[i]))
    {
      Serial.print(i);
      Serial.print("# ");
      Serial.println("Switch PUSH");
    }
  }
  delay(500);
}

