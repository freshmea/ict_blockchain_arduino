#ifndef Switch_h
#define Switch_h
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
    Switch(int8_t pin, int8_t led);
    void readSwitchChangeLed();
    bool readSwitch();
};

#endif