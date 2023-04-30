bool ledState;

void setup() {
  pinMode(2, INPUT);
  pinMode(7, OUTPUT);
}

void loop(){
  if(digitalRead(2)){
    if(ledState){
    digitalWrite(7, LOW);
    ledState = false;
    }else{
    digitalWrite(7, HIGH);
    ledState = true;
    }
    delay(500);
  }
}

