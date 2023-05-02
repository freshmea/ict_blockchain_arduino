#define SIZE 4
#include "Switch.h"

int aKey[SIZE] = {0,};
int aPassword[SIZE] = {0,};

int aPinRow[4] = {13, 12, 11, 10};
int aPinColumn[4] = {9, 8, 7, 6};
int pinGnd = 5;
int i, j;
int nCount = 0;

Switch sw[4]={Switch(9), Switch(8), Switch(7), Switch(6)};

void setup() {

  Serial.begin(115200);
  randomSeed(analogRead(0));
  
  for(int i=0; i<4; i++)
  {
    pinMode(aPinRow[i], OUTPUT);
    pinMode(aPinColumn[i], INPUT);
  }
  pinMode(pinGnd, OUTPUT);  
  digitalWrite(pinGnd, LOW);

  // generate key
  for(i=0; i<SIZE; i++)
  {
    aKey[i] = random(16);
    // check duplication
    for(j=0; j<i; j++) {
      if(aKey[i]==aKey[j]) {
        i=-1;
      }
    }
  }

  // print
  for(i=0; i<SIZE; i++)
  {
   Serial.print(aKey[i], HEX);
  }
  Serial.println();

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
        aPassword[nCount] = nNumber;
        nCount++;
      }
    }
    digitalWrite(aPinRow[i], LOW);

    if(nCount == SIZE) {
      checkPassword(aPassword);
      nCount = 0;
    }
  }
}

void checkPassword(int aPassword[SIZE])
{
  int nStrike = 0, nBall = 0;
  for(int i=0; i<SIZE; i++) {
    for(int j=0; j<SIZE; j++) {
      if(aKey[i] == aPassword[j]){
        if(i==j) nStrike++;
        else nBall++;
      }
    }
  }
  Serial.print("\tStrike : ");
  Serial.print(nStrike);
  Serial.print("\tBall : ");
  Serial.print(nBall);

  if(nStrike == SIZE) {
    Serial.println("\t<<Success>>");
  }
  else
    Serial.println("\t<<Fail>>");
}
