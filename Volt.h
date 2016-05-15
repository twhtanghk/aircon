#ifndef Volt_h
#define Volt_h

/*
 * see https://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
 */
class Volt {
  private:
    int _pin;
    double _v;
  
  public:
    // pin: analog pin input
    Volt(int pin, double v = 5);
    double value();
};

#endif
