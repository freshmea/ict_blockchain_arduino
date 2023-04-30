int pinGnd = A1;  
int pinVcc = A2; 
int pinTouchA = A0; 
int pinTouchD = A3;  

unsigned long timer1 = 0, timer2 = 0;
bool touchFlag = true;

void setup() {
  Serial.begin(115200); 

  pinMode(pinGnd, OUTPUT); 
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinTouchD, INPUT); 
  digitalWrite(pinGnd, LOW); 
  digitalWrite(pinVcc, HIGH);
}

void loop() {
  if(digitalRead(pinTouchD) && !touchFlag) {
      Serial.println("Touch On");
      delay(500);
      touchFlag = true;
  }
  if(touchFlag)
    Serial.println("touch off");
    touchFlag = false;
}

