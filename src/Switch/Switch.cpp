#include "Arduino.h"
#include "Switch.h"

Switch::Switch(int8_t pin, int8_t led = -1){
    _digitalPin = pin;
    _led = led;
    if(_led != -1) pinMode(_led, OUTPUT);
    pinMode(_digitalPin, INPUT);
}

void Switch::readSwitchChangeLed()
{
    _buttonInput = digitalRead(_digitalPin);
    _button_curr_state = _buttonInput;
    if (_button_curr_state == HIGH && _button_prev_input == LOW && (millis()-_prevTime)>50){
        if(_led_state){
            _led_state = LOW;
        } else {
            _led_state = HIGH;
        }
        digitalWrite(_led, _led_state);
        _prevTime = millis();
    } else if (_button_curr_state == LOW && _button_prev_input == HIGH){
        _prevTime = millis();
    }
    _button_prev_input = _button_curr_state;
}

bool Switch::readSwitch()
{
    _buttonInput = digitalRead(_digitalPin);
    _button_curr_state = _buttonInput;
    if (_button_curr_state == HIGH && _button_prev_input == LOW && (millis()-_prevTime)>50){
        return true;
        _prevTime = millis();
    } else if (_button_curr_state == LOW && _button_prev_input == HIGH){
        _prevTime = millis();
    }
    _button_prev_input = _button_curr_state;
    return false;
}