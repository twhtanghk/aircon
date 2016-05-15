#include <WiFiEspUdp.h>
#include <WiFiEspServer.h>
#include <WiFiEsp.h>
#include <WiFiEspClient.h>

#ifndef App_h
#define App_h

typedef void (*Callback)();

class App {
  private:
    int port;
    WiFiEspServer *server;
    
  public:
    App(char *ssid = "TTSwtich", char *pass = "12345678", int rx = 6, int tx = 7, int baud = 9600);
    App &listen(int _port = 80);
    WiFiEspClient available();
    App &get(char *path, Callback cb);
};

#endif
