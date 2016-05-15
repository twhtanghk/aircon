#include <HashMap.h>

#ifndef Req_h
#define Req_h

const byte HASH_SIZE = 20;

class Req {
  private:
    Stream &client;
    char *method;
    char *url;
    char *ver;
    HashType<char*,char*> rawHeaders[HASH_SIZE];
    HashMap<char*, char*> headers;
  
  public:
    Req(Stream &_in);

    static void httpParser(Req req);
};

#endif
