int pinRelay = 2;
int pinVcc = 3;
int pinGnd = 4;

void setup() {
  pinMode(pinRelay, OUTPUT);  
  pinMode(pinVcc, OUTPUT);
  pinMode(pinGnd, OUTPUT);
  digitalWrite(pinVcc, HIGH);
  digitalWrite(pinGnd, LOW);
}

void loop(){
  digitalWrite(pinRelay, HIGH); 
  delay(3000);  
  digitalWrite(pinRelay, LOW); 
  delay(3000); 
}


