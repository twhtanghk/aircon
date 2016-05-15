#include <Logging.h>
#include "Switch.h"
#include "Volt.h"
#include "Thermistor.h"
#include "App.h"

char result[10];
  
char *ftoa(double f, int precision = 5, char *a = result) {
  String ret = String(f);
  ret.toCharArray(result, 10);
  return result;
}

enum {CONDENSER = 0, EVAPORATOR, PUMP, FAN};
Switch relay[4] = {Switch(8), Switch(9), Switch(10), Switch(11)};
Thermistor thermistor[2] = {Thermistor(0), Thermistor(1)};
Volt in = Volt(2);

enum {MIN = 0, MAX};
int aircon[2] = {23, 25}; // 23 to 25 Celcius

void status() {
  for (int i = 0; i < 4; i++) {
    Log.Info("%i ", relay[i].state()); 
  }
  for (int i = 0; i < 2; i++) {
    Log.Info("%s ", ftoa(thermistor[i].c()));
  }
  Log.Info("\n");
}

App *app;

void setup() {
  Log.Init(LOG_LEVEL_VERBOSE, 115200);
  app = new App();  
  app->listen(80);
}

void loop() {
  Log.Info("loop");
  for (int i = 0; i < 4; i++) {
    relay[i].toggle();
  } 
  Log.Debug("%s\n", ftoa(thermistor[0].c()));
  
  delay(3000);
}
