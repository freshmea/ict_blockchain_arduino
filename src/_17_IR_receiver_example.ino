#include <IRremote.h>

int pinGnd = 11;  
int pinVcc = 12;  
int pinRecv = 13; 

IRrecv irrecv(pinRecv);
decode_results results;

void setup()
{
  Serial.begin(115200);  

  pinMode(pinGnd, OUTPUT); 
  pinMode(pinVcc, OUTPUT);  
  digitalWrite(pinGnd, LOW);  
  digitalWrite(pinVcc, HIGH); 

  irrecv.enableIRIn(); 
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); 
  }
}
