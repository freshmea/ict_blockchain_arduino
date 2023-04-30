int pinGnd = 4; 
int pinVcc = 3; 
int pinTilt = 2;
unsigned long prevTime;
 
void setup() {
  Serial.begin(115200);  

  pinMode(pinGnd, OUTPUT);  
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinTilt, INPUT_PULLUP); 
  digitalWrite(pinGnd, LOW);  
  digitalWrite(pinVcc, HIGH); 
}
void loop() {
  if(millis()-prevTime>500)
  {
    if(!digitalRead(pinTilt) )  
    {
      Serial.println("Tilt ON");
    }
    else
    {
      Serial.println("Tilt OFF");
    }
    prevTime = millis();
  }
    //delay(500);
}