#include <Logging.h>
#include <math.h>
#include "Thermistor.h"

Thermistor::Thermistor(int pin, double r2) {
  _pin = pin;
  _r2 = r2;
  pinMode(pin, INPUT);
}

double Thermistor::k() {
  double r1 = _r2 * ((1024.0 / analogRead(_pin)) - 1);
  double temp = log(r1);
  return 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
}
    
double Thermistor::c() {
  return k() - 273.15;
}

double Thermistor::f() {
  return (c() * 9 / 5) + 32;
}

