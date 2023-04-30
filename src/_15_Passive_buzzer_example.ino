int pinGnd = 5; 
int pinBuzzer = 3;  

// 3 octave - Do, Re, Mi, Fa, So, La, Ti, 4 octave - Do
int aPitchData[8] = {131, 147, 165, 175, 196, 220, 247, 262};

void setup() {
  pinMode(pinGnd, OUTPUT);    
  digitalWrite(pinGnd, LOW);  
  pinMode(pinBuzzer, OUTPUT);    
}

void loop(){
  for(int i=0; i<8; i++) {
    tone(pinBuzzer,aPitchData[i]);
    delay(100);  
    noTone(pinBuzzer); 
  }
  delay(1000);  
}

