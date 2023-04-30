int pinGnd = A1;  
int pinVcc = A2; 
int pinTouchA = A0; 
int pinTouchD = A3;  

long timer1 = 0, timer2 = 0;
int touchFlag = 1;

void setup() {
  Serial.begin(115200); 

  pinMode(pinGnd, OUTPUT); 
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinTouchD, INPUT); 
  digitalWrite(pinGnd, LOW); 
  digitalWrite(pinVcc, HIGH);
}

void loop() {
  if(digitalRead(pinTouchD)) {
    timer1 = millis();
    // 16.6ms High read
    if((timer1 - timer2) < 18) {
      if(touchFlag == 0) {
        Serial.println("Touch On");
        touchFlag = 1;
      }
    }
    timer2 = timer1;
  }
  else {
    // always Low
    if((millis() - timer1) > 18) {
      if(touchFlag) {
        Serial.println("Touch Off");
        touchFlag = 0;
      }
    }
  }
}

