int pinGnd = 4;  
int pinVcc = 3;  
int pinHit = 2;  
int count = 0;
void hitISR(void);
void setup() {
  Serial.begin(115200);

  pinMode(pinGnd, OUTPUT); 
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinHit, INPUT); 
  digitalWrite(pinGnd, LOW);  // ground pin LOW Output
  digitalWrite(pinVcc, HIGH); // power pin HIGH Output
  
  // External interrupt setup
  // source : pinHit, ISR: hitISR, mode : RISING
  attachInterrupt(0, hitISR, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  // print "Hit : "
  Serial.print("Hit : ");
  // print as an ASCII-encoded decimal
  Serial.println(count);
  delay(500);  // delay 500 milliseconds
}

// External ISR function
void hitISR(void)
{
  count++; // 1 increase
}
