#include <Logging.h>
#include "Switch.h"

Switch::Switch(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

int Switch::state() {
  return digitalRead(this->_pin);
}
    
Switch &Switch::toggle(int value) {
  if (value == -1) {
    value = state() == HIGH ? LOW : HIGH;
  }
  digitalWrite(this->_pin, value);
  Log.Debug("{%d: %d}", _pin, value);
  return *this;
}

Switch &Switch::on() {
  return toggle(HIGH);
}

Switch &Switch::off() {
  return toggle(LOW);
}
