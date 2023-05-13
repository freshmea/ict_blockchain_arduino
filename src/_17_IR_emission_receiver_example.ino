int pinGndReceiver = 11;
int pinVccReceiver = 12;
int pinReceiver = 13;

int pinGndEmission = 4;
int pinEmission = 3;

void setup()
{
  Serial.begin(115200);

  pinMode(pinGndReceiver, OUTPUT);
  pinMode(pinVccReceiver, OUTPUT);
  pinMode(pinReceiver, INPUT);
  digitalWrite(pinGndReceiver, LOW);
  digitalWrite(pinVccReceiver, HIGH);

  pinMode(pinGndEmission, OUTPUT);
  pinMode(pinEmission, OUTPUT);
  digitalWrite(pinGndEmission, LOW);

  digitalWrite(pinEmission, HIGH);
}

void loop() {
  if (!digitalRead(pinReceiver)) {
    Serial.println("Read");
    delay(100);
  }

}



