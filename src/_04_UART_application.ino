#include <string.h>

int pin_LED[8] = {13, 12, 11, 10, 9, 8, 7, 6};

void setup() {
  Serial.begin(115200);
  int i;
  for(i=0; i<8; i++)
  {
    pinMode(pin_LED[i], OUTPUT);
  }
}

void loop() {
  char buffer;
  int i = 0;

  while(Serial.available())
  {
    buffer = Serial.read();
  }
  
  if(buffer == 'O' || buffer == 'o')
  {
    for(i=0; i<8; i++)
    {
      digitalWrite(pin_LED[i], HIGH);   // LED ON
    }
    Serial.println("LED ON");
  }
  
  else if(buffer == 'X' || buffer == 'x')
  {
    for(i=0; i<8; i++)
    {
      digitalWrite(pin_LED[i], LOW);   // LED OFF
    }
    Serial.println("LED OFF");
  }
  
}

