const int digitalPin = 6;
const int LED = 10;


int button_prev_input = LOW;
int button_curr_state = LOW;
int led_state = 0;

void setup(){
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop(){
  int buttonInput = digitalRead(digitalPin);
  button_curr_state = buttonInput;
  if (button_curr_state == HIGH && button_prev_input == LOW){
    Serial.println("rising EDGE");
    if(led_state){
      led_state=LOW;
    } else {
      led_state=HIGH;
    }
    // 채터링 방지
    delay(50);
  } else if (button_curr_state == LOW && button_prev_input == HIGH){
    Serial.println("falling EDGE");
    // 채터링 방지
    delay(50);
  }
  button_prev_input = button_curr_state;

  digitalWrite(LED, led_state);
}