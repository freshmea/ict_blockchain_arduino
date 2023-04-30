int aPinFndData[8] = {13, 12, 11, 10, 9, 8, 7, 6};

int aPinFndSel[6] = {5, 4, 3, 2, 1, 0};  

// 0 ~ F data
uint8_t aFndData[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,
                        0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
                        
// Fnd sel data
uint8_t aFndSelData[6] = {0x3E, 0x3D, 0x3B, 0x37, 0x2F, 0x1F};

void setup() {
  int i;
  for(i=0; i<8; i++)
  {
    pinMode(aPinFndData[i], OUTPUT);  // FND_DATA pin Output setup
  }
  for(i=0; i<6; i++)
  {
    pinMode(aPinFndSel[i], OUTPUT);  // FND_SEL pin Output setup
  }

}

void loop() {
  // FND 0 ~ F output
  for(int i=0; i<6; i++)
  {
    FndSelOut(aFndSelData[i]); 
    for(int j=0; j<16; j++)
    {
      FndDataOut(aFndData[j]);
      delay(1000);
    }
  }
}

// FND data output function
void FndDataOut(uint8_t data)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(aPinFndData[i],(data>>i) & 0x1);
  }
}

// FND sel output function 
void FndSelOut(uint8_t data)
{
  for(int i=0; i<6; i++)
  {
    digitalWrite(aPinFndSel[i],(data>>i) & 0x1);
  }
}
