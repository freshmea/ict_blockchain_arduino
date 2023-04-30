int pinGnd = 5; 
int pinBuzzer = 3;  
int aPinSwitch[8] = {13, 12, 11, 10, 9, 8, 7, 6}; 

// 3 octave - Do, Re, Mi, Fa, So, La, Ti, 4 octave - Do
int aPitchData[8] = {131, 147, 165, 175, 196, 220, 247, 262};

void setup() {
  for(int i=0; i<8; i++)
  {
    pinMode(aPinSwitch[i], INPUT); 
  }
  pinMode(pinGnd, OUTPUT);    
  pinMode(pinBuzzer, OUTPUT);   
  digitalWrite(pinGnd, LOW);  
}

void loop(){
  for(int i=0; i<8; i++)
  {
    if(digitalRead(aPinSwitch[i]))
    {
      tone(pinBuzzer,aPitchData[i]); 
      delay(100);  
      noTone(pinBuzzer);      
    }
  }
}

