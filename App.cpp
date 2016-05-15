#include <Logging.h>
#include <SoftwareSerial.h>
#include "App.h"

App::App(char *ssid, char *pass, int rx, int tx, int baud) {
  SoftwareSerial *serial = new SoftwareSerial(rx, tx);
  serial->begin(baud);
  WiFi.init(serial);
  if (WiFi.status() == WL_NO_SHIELD)
    Log.Error("WiFi shield not present");
  WiFi.configAP(IPAddress(192, 168, 1, 1));
  WiFi.beginAP(ssid, 10, pass, ENC_TYPE_WPA2_PSK);
}
  
App &App::listen(int _port) {
  port = _port;
  server = new WiFiEspServer(port);
  server->begin();
  return *this;
}

WiFiEspClient App::available() {
  return server->available();
}

App &App::get(char *path, Callback cb) {
  return *this;
}

