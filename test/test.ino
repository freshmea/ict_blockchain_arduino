int aPinSwitch[3] = {13,12,11}; 
int aPinLed[3] = { 10, 9, 8};
int aFlag[3] = {0,};

void setup() { 
  //Serial.begin(115200); 
  for(int i=0; i<3; i++)
  {
    pinMode(aPinSwitch[i], INPUT);
  }
  for(int i=0; i<3; i++)
  {
    pinMode(aPinLed[i], OUTPUT);
  }
}

void loop() {
  for(int i=0; i<3; i++)
  {
    int readData = digitalRead(aPinSwitch[i]);
    if(readData)
    {
        if(aFlag[i]) {
            digitalWrite(aPinLed[i], LOW);
            aFlag[i] = 0;
        }
        else {
            digitalWrite(aPinLed[i], HIGH);
            aFlag[i] = 1;
        }
    }
  }
  delay(300);
}

