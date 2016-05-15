#include <Logging.h>
#include "Volt.h"

Volt::Volt(int pin, double v) {
  _pin = pin;
  _v = v;
  pinMode(_pin, INPUT);
}

double Volt::value() {
  return analogRead(_pin) * _v / 1023;
}
