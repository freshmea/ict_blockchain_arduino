const int digitalPin = 6;
const int LED = 10;

class Switch
{
  private:
    int _button_prev_input = LOW;
    int _button_curr_state = LOW;
    int _led_state = 0;
    int _digitalPin = NULL;
    int _buttonInput = 0;
    int _led = NULL;
    unsigned long _prevTime= 0;

  public:
    Switch(int8_t pin, int8_t led){
        _digitalPin = pin;
        _led = led;
        pinMode(_led, OUTPUT);
        pinMode(_digitalPin, INPUT);
    }
    void readSwitchChangeLed()
    {
        _buttonInput = digitalRead(_digitalPin);
        _button_curr_state = _buttonInput;
        if (_button_curr_state == HIGH && _button_prev_input == LOW && (millis()-_prevTime)>50){
            Serial.println("rising EDGE");  //not good! 시리얼이 선언되지 않으면 오류 
            if(_led_state){
                _led_state = LOW;
            } else {
                _led_state = HIGH;
            }
            digitalWrite(_led, _led_state);
            _prevTime = millis();
        } else if (_button_curr_state == LOW && _button_prev_input == HIGH){
            Serial.println("falling EDGE"); //not good! 시리얼이 선언되지 않으면 오류
            _prevTime = millis();
        }
        _button_prev_input = _button_curr_state;
    }
};

Switch switch1(6, 10);
Switch switch2(7, 11);
Switch switch3(8, 12);
Switch switch4(9, 13);

void setup(){
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop(){
  switch1.readSwitchChangeLed();
  switch2.readSwitchChangeLed();
  switch3.readSwitchChangeLed();
  switch4.readSwitchChangeLed();
}
