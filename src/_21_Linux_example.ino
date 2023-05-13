void setup() {
  Serial.begin(115200);
  Serial.println("Serial Test !!"); 
}

void loop() {
}


void serialEvent(void) {
  String data;
  data = Serial.readString();
  Serial.println(data);
}

