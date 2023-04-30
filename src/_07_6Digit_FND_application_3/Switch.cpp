#include "Arduino.h"
#include "Switch.h"


/**
 * 스위치를 설정하는 함수 풀업 스위치에 지정한다.
 * @param pin 스위치에 연결된 핀 지정
 * @param led LED 에 연결된 핀 지정 기본값은 -1 이다.
*/
Switch::Switch(int8_t pin, int8_t led){
    _digitalPin = pin;
    _led = led;
    if(_led != -1) pinMode(_led, OUTPUT);
    pinMode(_digitalPin, INPUT);
}

void Switch::readSwitchChangeLed(int de)
{
    _buttonInput = digitalRead(_digitalPin);
    _button_curr_state = _buttonInput;
    if (_button_curr_state == HIGH && _button_prev_input == LOW && (millis()-_prevTime)>de){
        if(_led_state){
            _led_state = LOW;
        } else {
            _led_state = HIGH;
        }
        _prevTime = millis();
        digitalWrite(_led, _led_state);
    } else if (_button_curr_state == LOW && _button_prev_input == HIGH && (millis()-_prevTime)>de){
        _prevTime = millis();
    }
    _button_prev_input = _button_curr_state;
}

bool Switch::readSwitch(int de)
{
    _buttonInput = digitalRead(_digitalPin);
    _button_curr_state = _buttonInput;
    if (_button_curr_state == HIGH && _button_prev_input == LOW && (millis()-_prevTime)>de){
        _prevTime = millis();
        return true;
    } else if (_button_curr_state == LOW && _button_prev_input == HIGH && (millis()-_prevTime)>de){
        _prevTime = millis();
    }
    _button_prev_input = _button_curr_state;
    return false;
}