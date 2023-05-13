int pinGnd = 5;
int pinEcho = 4;
int pinTrigger = 3;
int pinVcc = 2;

int pinBuzzerGnd = 11; 
int pinBuzzer = 9;  

// 3 octave - Do, Re, Mi, Fa, So, La, Ti, 4 octave - Do
int aPitchData[8] = {131, 147, 165, 175, 196, 220, 247, 262};


void setup() {
  Serial.begin(115200);
  pinMode(pinGnd, OUTPUT);
  pinMode(pinVcc, OUTPUT);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(pinGnd, LOW);
  digitalWrite(pinVcc, HIGH);
  
  pinMode(pinBuzzerGnd, OUTPUT);    
  pinMode(pinBuzzer, OUTPUT);   
  digitalWrite(pinBuzzerGnd, LOW);  
}

void loop() {
  float fDuration, fDistance;
  
  digitalWrite(pinTrigger, HIGH);
  delay(10);
  digitalWrite(pinTrigger, LOW);
  
  fDuration = pulseIn(pinEcho, HIGH); 

  fDistance = ((float)(340 * fDuration) / 10000) / 2;  
  
  Serial.print(fDistance);
  Serial.println("cm");

  if(fDistance >= 40) 
  {
    noTone(pinBuzzer);
  }
  else
  {
    int nNumber = 7-(int)fDistance/5;   // distance 0 ~ 39 / 5 = 0 ~ 7  
    tone(pinBuzzer,aPitchData[nNumber]); // number 0 ~ 7
    delay(1000/nNumber);  
    noTone(pinBuzzer);    
  }
   
}

