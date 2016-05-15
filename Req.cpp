#include <Logging.h>
#include <Regexp.h>
#include "Req.h"

Req::Req(Stream &_in) : client(_in), headers(rawHeaders, HASH_SIZE) {
  MatchState ms;
  char line[80];
  in.readStringUntil('\n').toCharArray(line, 80);
  Log.Debug("%s", line);
  ms.Target(line);
  char result = ms.Match("(.*) (.*) HTTP/(.*)");
  if (result == REGEXP_MATCHED) {
    method = ms.GetCapture(line, 0);
    url = ms.GetCapture(line, 1);
    ver = ms.GetCapture(line, 2);
    Log.Debug("%s %s %s", method, url, ver);
  }
}

void Req::httpParser(Req req) {
  char *line = req.client.readStringUntil('\n');
  MatchState ms;
  ms.Target(line);
  char result = ms.Match("(.*) (.*) HTTP/(.*)")
  if (result == REGEXP_MATCHED)
  char method[10], url[20], version[5];
  ms.GetCapture(method, 0);
  ms.GetCapture(url, 1);
  ms.GetCapture(version, 2);
}

