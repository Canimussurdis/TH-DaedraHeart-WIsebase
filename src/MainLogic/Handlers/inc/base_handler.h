#ifndef BASE_HANDLER_H
#define BASE_HANDLER_H

#include "request.h"
#include "response.h"

class BaseHandler {
public:
    BaseHandler(const Request &request) : request(request) {};
    virtual ~BaseHandler() = default;

    virtual Response execute() = 0;

public:
    Request request;
};

#endif