#ifndef USER_HANDLER_H
#define USER_HANDLER_H

#include "base_handler.h"

class UserHandler: public BaseHandler{
public:
    UserHandler(const Request &request) : BaseHandler(request) {};
    ~UserHandler() override = default;

    Response execute() override;

public:
    Request request;
};

#endif