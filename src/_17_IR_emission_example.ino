#include <IRremote.h>
#include <IRremoteInt.h>


int pinGnd = 5; 
int pinIr = 3; 

IRsend irsend;

void setup() {
  Serial.begin(115200);  

  pinMode(pinGnd, OUTPUT);
  pinMode(pinIr, OUTPUT); 
  digitalWrite(pinGnd, LOW);  
}

void loop() {
  if (Serial.read() != -1) {
    Serial.println("Send ");
    irsend.sendSony(0xa90, 12);    // Sony TV power code
  }
}

