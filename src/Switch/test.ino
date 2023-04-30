#include "Switch.h"

Switch switch1(6, 10);
Switch switch2(7, 11);
Switch switch3(8, 12);
Switch switch4(9, 13);

void setup(){
  Serial.begin(9600);
}

void loop(){
  switch1.readSwitchChangeLed();
  switch2.readSwitchChangeLed();
  switch3.readSwitchChangeLed();
  switch4.readSwitchChangeLed();
}
