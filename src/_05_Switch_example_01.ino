int pinSwitch = 13; 

void setup() { 
  Serial.begin(115200); 
  pinMode(pinSwitch, INPUT); 
}

void loop() {
  if(digitalRead(pinSwitch)) {
    Serial.println("Pushed");
    delay(500);
  }
}

