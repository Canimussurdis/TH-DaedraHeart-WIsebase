#ifndef ROUTER_H
#define ROUTER_H

#include "base_handler.h"

class Router {
 public:
  explicit Router();

  Response processRoute(const std::string &method, const Request &request);
};

#endif