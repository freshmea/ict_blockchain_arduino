#include "Switch.h"

int aPinRow[4] = {13, 12, 11, 10};
int aPinColumn[4] = {9, 8, 7, 6};
int pinGnd = 5;

Switch sw[4]={Switch(9), Switch(8), Switch(7), Switch(6)};

void setup() {
  Serial.begin(115200);
  
  for(int i=0; i<4; i++)
  {
    pinMode(aPinRow[i], OUTPUT);
    pinMode(aPinColumn[i], INPUT);
  }
  pinMode(pinGnd, OUTPUT);  
  digitalWrite(pinGnd, LOW);
}

void loop() {
  int nRow, nColumn, nNumber;
  
  for(int i=0; i<4; i++)
  { 
    digitalWrite(aPinRow[i], HIGH);
    nRow = 0;    
    nRow = i*4;    
    for(int j=0; j<4; j++)
    { 
      nColumn = 0;
      nColumn += j;    
      if(sw[j].readSwitchDTC())
      {
        nNumber = nRow + nColumn;
        Serial.print("KEY [");
        Serial.print(nNumber, HEX);
        Serial.println("] PUSH");
      }
    }
    digitalWrite(aPinRow[i], LOW);
  }
}
