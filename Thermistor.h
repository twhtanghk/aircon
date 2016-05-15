#ifndef Thermistor_h
#define Thermistor_h

/*
 * see http://playground.arduino.cc/ComponentLib/Thermistor2
 */
class Thermistor {
  private:
    int _pin;
    double _r2;
                    
  public:
    Thermistor(int pin, double r2 = 10000.0);
    double k();
    double c();
    double f();
};

#endif
