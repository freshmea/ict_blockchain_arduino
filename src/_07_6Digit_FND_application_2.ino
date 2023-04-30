// switch push -> count++ -> FND output

// FND control pin
// A, B, C, D, E, F, G, H pin
int pin_FND_DATA[8] = {13, 12, 11, 10, 9, 8, 7, 6};
// S4, S5 pin
int pin_FND_SEL[2] = {5, 4};  

// Switch pin
int pin_GND = 1;
int pin_SWITCH = 2;
int pin_VCC = 3;

int count = 0;


// 0 ~ 9 data
uint8_t FND_data[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x6F};
                        
// Fnd select data
uint8_t FND_sel_data[2] = {0x2, 0x1};

void setup() {
  int i;
  for(i=0; i<8; i++)
  {
    pinMode(pin_FND_DATA[i], OUTPUT);  // FND_DATA pin Output setup
  }
  for(i=0; i<2; i++)
  {
    pinMode(pin_FND_SEL[i], OUTPUT);  // FND_SEL pin Output setup
  }
  pinMode(pin_GND, OUTPUT);
  pinMode(pin_VCC, OUTPUT);
  pinMode(pin_SWITCH, INPUT);
  digitalWrite(pin_GND, LOW);
  digitalWrite(pin_VCC, HIGH);

  delay(1000);
}

void loop() {
  if(digitalRead(pin_SWITCH))
  {
    count++;
    delay(10);
  }
  display(count);
  
  if(count == 100)
  {
    count = 0;
  }
}

void display(int number)
{
  int i;
  int position[2] = {0,};
  
  position[0] = number/10;
  position[1] = number%10;

  if(position[0] > 0)
  {
    digitalWrite(pin_FND_SEL[0], LOW);
    digitalWrite(pin_FND_SEL[1], HIGH);
    FND_data_out(FND_data[position[0]]);
    delay(5);
    digitalWrite(pin_FND_SEL[0], HIGH);
    digitalWrite(pin_FND_SEL[1], LOW);
    FND_data_out(FND_data[position[1]]);
    delay(5);
  }
  else
  {
    digitalWrite(pin_FND_SEL[0], HIGH);
    digitalWrite(pin_FND_SEL[1], LOW);
    FND_data_out(FND_data[position[1]]);    
  }
}

void FND_data_out(uint8_t data)
{
  int i;
  for(i=0; i<8; i++)
  {
    digitalWrite(pin_FND_DATA[i],(data>>i) & 0x1);
  }
}
