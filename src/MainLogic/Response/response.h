#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <vector>
#include <map>

class Response {
 public:
  std::string ResponseToString(const Response &response);

  int status_code;
  std::string http_version;
  std::string status_message;
  std::map<std::string, std::string> params;
  std::map<std::string, std::string> headers;
  std::string body;
};

#endif
