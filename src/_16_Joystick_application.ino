int pinGnd = A0; 
int pinVcc = A1; 
int pinX= A2;  
int pinY= A3;  
int pinSwitch= A4; 

// FND control pin
// A, B, C, D, E, F, G, H pin
int aPinFndData[8] = {13, 12, 11, 10, 9, 8, 7, 6};
// S4, S5 pin
int aPinFndSel[2] = {5, 4};  

int count = 0;

// 0 ~ 9 data
uint8_t aFndData[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x6F};
                        
// Fnd select data
uint8_t aFndSelData[2] = {0x2, 0x1};

void setup()
{
  int i;
  for(i=0; i<8; i++)
  {
    pinMode(aPinFndData[i], OUTPUT);  // FND_DATA pin Output setup
  }
  for(i=0; i<2; i++)
  {
    pinMode(aPinFndSel[i], OUTPUT);  // FND_SEL pin Output setup
  }
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(pinGnd, OUTPUT);  
  pinMode(pinVcc, OUTPUT);  
  pinMode(pinSwitch, INPUT_PULLUP);
  digitalWrite(pinGnd, LOW);  
  digitalWrite(pinVcc, HIGH); 
  
  delay(1000);
}

void loop()
{

  int x = map(analogRead(pinX), 0, 1023, 0, 100);
  int y = map(analogRead(pinY), 0, 1023, 0, 100);
  if(x ==99)
  {
    count++;
  }
  else if(x == 0)
  {
    count--;
  } 
  if(count > 100 || count < 0)
  {
    count = 0;
  }
  if(!digitalRead(pinSwitch))
  {
    count = 0;
  }
  delay(10);
  display(count);
  
}

void display(int number)
{
  int aPosition[2] = {0,0};
  
  aPosition[0] = number/10;
  aPosition[1] = number%10;

  if(aPosition[0] != 0)
  {
    digitalWrite(aPinFndSel[0], LOW);
    digitalWrite(aPinFndSel[1], HIGH);
    FndDataOut(aFndData[aPosition[0]]);
    delay(5);
    digitalWrite(aPinFndSel[0], HIGH);
    digitalWrite(aPinFndSel[1], LOW);
    FndDataOut(aFndData[aPosition[1]]);
    delay(5);
  }
  else
  {
    digitalWrite(aPinFndSel[0], HIGH);
    digitalWrite(aPinFndSel[1], LOW);
    FndDataOut(aFndData[aPosition[1]]);    
  }
}

void FndDataOut(uint8_t data)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(aPinFndData[i],(data>>i) & 0x1);
  }
}
