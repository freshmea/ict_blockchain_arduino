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

/**
 * DTC(delayed time check) 방법으로 스위치를 인식하는 함수
 * 어쩔 수 없이 전압의 변화가 있을 때 시간으로만 버튼을 인식
*/
bool Switch::readSwitchDTC(int de = 50)
{
if(digitalRead(_digitalPin)) {
    _prevTime = millis();
    // de ms High read
    if((_prevTime - _prevTime2) < de) {
      if(_flag == 0) {
        _flag = 1;
        return true;
      }
    }
    _prevTime2 = _prevTime;
  }
  else {
    // always Low
    if((millis() - _prevTime) > de) {
      if(_flag) {
        _flag = 0;
      }
    }
  }
  return false;
}