void setup() {
  Serial.begin(115200);
  Serial.println("Serial Test !!"); 
  Serial.print("ECHO >> ");
}

void loop() {
}

void serialEvent(void) {
  char data;
  data = Serial.read();
  Serial.print(data);
}

