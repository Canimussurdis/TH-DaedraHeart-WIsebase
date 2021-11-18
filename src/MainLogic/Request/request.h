#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <vector>
#include <map>

class Request {
 public:
  Request();

  std::string RequestToString(const Request& request);
  std::vector<std::string> split(const std::string& s, char delim);
  Request parse(std::string req_data);

  std::string host;
  std::string method;
  std::string http_version;
  std::string path;
  std::map<std::string, std::string> params;
  std::map<std::string, std::string> headers;
  std::string body;
};

#endif