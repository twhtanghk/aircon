#ifndef Switch_h
#define Switch_h

class Switch {
  private:
    int _pin;
    
  public:
    Switch(int pin);
    int state();
    Switch &toggle(int value = -1);
    Switch &on();
    Switch &off();
};

#endif
